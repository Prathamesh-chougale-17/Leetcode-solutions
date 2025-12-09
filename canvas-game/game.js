// AI Canvas Game - Powered by Gemini API
// Game Engine and API Integration

class GameEngine {
    constructor() {
        this.canvas = document.getElementById('gameCanvas');
        this.ctx = this.canvas.getContext('2d');
        this.objects = [];
        this.isRunning = false;
        this.isPaused = false;
        this.apiKey = localStorage.getItem('geminiApiKey') || '';
        this.lastTime = 0;
        this.fps = 0;
        this.frameCount = 0;
        
        this.initializeCanvas();
        this.setupEventListeners();
        this.startGameLoop();
    }

    initializeCanvas() {
        // Set canvas size and background
        this.canvas.width = 800;
        this.canvas.height = 600;
        this.clearCanvas();
        
        // Add click event for canvas interaction
        this.canvas.addEventListener('click', (e) => {
            const rect = this.canvas.getBoundingClientRect();
            const x = e.clientX - rect.left;
            const y = e.clientY - rect.top;
            this.handleCanvasClick(x, y);
        });
    }

    setupEventListeners() {
        // Enter key in prompt input
        document.getElementById('promptInput').addEventListener('keypress', (e) => {
            if (e.key === 'Enter' && !e.shiftKey) {
                e.preventDefault();
                this.processPrompt();
            }
        });

        // Load saved API key
        if (this.apiKey) {
            document.getElementById('apiKey').value = this.apiKey;
            this.showStatus('apiStatus', 'API key loaded from storage', 'info');
        }
    }

    handleCanvasClick(x, y) {
        // Find clicked object
        const clickedObject = this.objects.find(obj => 
            x >= obj.x - obj.width/2 && 
            x <= obj.x + obj.width/2 && 
            y >= obj.y - obj.height/2 && 
            y <= obj.y + obj.height/2
        );

        if (clickedObject) {
            this.showStatus('promptStatus', `Clicked on ${clickedObject.type} at (${Math.round(x)}, ${Math.round(y)})`, 'info');
            // Add interaction behavior
            clickedObject.onClick && clickedObject.onClick();
        } else {
            this.showStatus('promptStatus', `Clicked at (${Math.round(x)}, ${Math.round(y)})`, 'info');
        }
    }

    startGameLoop() {
        this.isRunning = true;
        const gameLoop = (currentTime) => {
            if (!this.isRunning) return;

            const deltaTime = currentTime - this.lastTime;
            this.lastTime = currentTime;

            if (!this.isPaused) {
                this.update(deltaTime);
                this.render();
            }

            // Calculate FPS
            this.frameCount++;
            if (this.frameCount % 60 === 0) {
                this.fps = Math.round(1000 / deltaTime);
                document.getElementById('fps').textContent = this.fps;
            }

            requestAnimationFrame(gameLoop);
        };
        requestAnimationFrame(gameLoop);
    }

    update(deltaTime) {
        // Update all game objects
        this.objects.forEach(obj => {
            if (obj.update) {
                obj.update(deltaTime, this.canvas.width, this.canvas.height);
            }
        });

        // Update object count
        document.getElementById('objectCount').textContent = this.objects.length;
    }

    render() {
        // Clear canvas
        this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
        
        // Draw background
        this.ctx.fillStyle = '#f8f9fa';
        this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);

        // Draw grid
        this.drawGrid();

        // Render all objects
        this.objects.forEach(obj => {
            if (obj.render) {
                obj.render(this.ctx);
            }
        });
    }

    drawGrid() {
        this.ctx.strokeStyle = '#e0e0e0';
        this.ctx.lineWidth = 1;
        this.ctx.setLineDash([2, 2]);

        // Vertical lines
        for (let x = 0; x <= this.canvas.width; x += 50) {
            this.ctx.beginPath();
            this.ctx.moveTo(x, 0);
            this.ctx.lineTo(x, this.canvas.height);
            this.ctx.stroke();
        }

        // Horizontal lines
        for (let y = 0; y <= this.canvas.height; y += 50) {
            this.ctx.beginPath();
            this.ctx.moveTo(0, y);
            this.ctx.lineTo(this.canvas.width, y);
            this.ctx.stroke();
        }

        this.ctx.setLineDash([]);
    }

    clearCanvas() {
        this.objects = [];
        this.render();
    }

    addObject(object) {
        this.objects.push(object);
    }

    removeObject(object) {
        const index = this.objects.indexOf(object);
        if (index > -1) {
            this.objects.splice(index, 1);
        }
    }

    showStatus(elementId, message, type = 'info') {
        const element = document.getElementById(elementId);
        element.textContent = message;
        element.className = `status ${type}`;
        
        // Auto-clear after 5 seconds
        setTimeout(() => {
            element.textContent = '';
            element.className = '';
        }, 5000);
    }

    async processPrompt() {
        const promptInput = document.getElementById('promptInput');
        const prompt = promptInput.value.trim();
        
        if (!prompt) {
            this.showStatus('promptStatus', 'Please enter a prompt', 'error');
            return;
        }

        if (!this.apiKey) {
            this.showStatus('promptStatus', 'Please set your Gemini API key first', 'error');
            return;
        }

        const processBtn = document.getElementById('processBtn');
        processBtn.disabled = true;
        processBtn.textContent = '🤖 Processing...';

        try {
            this.showStatus('promptStatus', 'Sending request to Gemini...', 'info');
            
            const gameAction = await this.callGeminiAPI(prompt);
            
            if (gameAction) {
                this.executeGameAction(gameAction);
                this.showStatus('promptStatus', 'Command executed successfully!', 'success');
                promptInput.value = '';
            } else {
                this.showStatus('promptStatus', 'No valid action could be generated', 'error');
            }

        } catch (error) {
            console.error('Error processing prompt:', error);
            this.showStatus('promptStatus', `Error: ${error.message}`, 'error');
        } finally {
            processBtn.disabled = false;
            processBtn.textContent = '🚀 Execute Command';
        }
    }

    async callGeminiAPI(prompt) {
        const API_URL = 'https://generativelanguage.googleapis.com/v1beta/models/gemini-pro:generateContent';
        
        const systemPrompt = `You are a game AI that interprets user commands and returns JSON actions for a canvas game. 

Available actions:
- createCircle: {type: "circle", x: number, y: number, radius: number, color: "hex", dx?: number, dy?: number}
- createSquare: {type: "square", x: number, y: number, width: number, height: number, color: "hex", dx?: number, dy?: number}
- createTriangle: {type: "triangle", x: number, y: number, size: number, color: "hex", dx?: number, dy?: number}
- createText: {type: "text", x: number, y: number, text: string, color: "hex", fontSize?: number}
- clear: {type: "clear"}
- setBouncing: {type: "setBouncing", enabled: boolean}
- setGravity: {type: "setGravity", enabled: boolean}
- createParticles: {type: "particles", x: number, y: number, count: number, color: "hex"}

Canvas size: 800x600 pixels.

User command: "${prompt}"

Return only valid JSON with a single action object. If multiple objects, return an array. Include movement (dx, dy) for animated objects.`;

        const response = await fetch(`${API_URL}?key=${this.apiKey}`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                contents: [{
                    parts: [{
                        text: systemPrompt
                    }]
                }],
                generationConfig: {
                    temperature: 0.3,
                    maxOutputTokens: 1000,
                }
            })
        });

        if (!response.ok) {
            throw new Error(`API request failed: ${response.status} ${response.statusText}`);
        }

        const data = await response.json();
        
        if (!data.candidates || !data.candidates[0] || !data.candidates[0].content) {
            throw new Error('Invalid API response format');
        }

        const responseText = data.candidates[0].content.parts[0].text;
        
        try {
            // Clean up the response text to extract JSON
            const jsonMatch = responseText.match(/\{[\s\S]*\}|\[[\s\S]*\]/);
            if (!jsonMatch) {
                throw new Error('No JSON found in response');
            }
            
            return JSON.parse(jsonMatch[0]);
        } catch (parseError) {
            console.error('JSON parse error:', parseError);
            console.error('Response text:', responseText);
            throw new Error('Failed to parse AI response as JSON');
        }
    }

    executeGameAction(action) {
        // Handle array of actions
        if (Array.isArray(action)) {
            action.forEach(a => this.executeGameAction(a));
            return;
        }

        switch (action.type) {
            case 'circle':
                this.createCircle(action);
                break;
            case 'square':
                this.createSquare(action);
                break;
            case 'triangle':
                this.createTriangle(action);
                break;
            case 'text':
                this.createText(action);
                break;
            case 'clear':
                this.clearCanvas();
                break;
            case 'particles':
                this.createParticles(action);
                break;
            case 'setBouncing':
                this.setBouncing(action.enabled);
                break;
            case 'setGravity':
                this.setGravity(action.enabled);
                break;
            default:
                console.warn('Unknown action type:', action.type);
        }
    }

    createCircle(config) {
        const circle = new Circle(
            config.x || Math.random() * this.canvas.width,
            config.y || Math.random() * this.canvas.height,
            config.radius || 20,
            config.color || '#ff4444',
            config.dx || 0,
            config.dy || 0
        );
        this.addObject(circle);
    }

    createSquare(config) {
        const square = new Square(
            config.x || Math.random() * this.canvas.width,
            config.y || Math.random() * this.canvas.height,
            config.width || 40,
            config.height || 40,
            config.color || '#4444ff',
            config.dx || 0,
            config.dy || 0
        );
        this.addObject(square);
    }

    createTriangle(config) {
        const triangle = new Triangle(
            config.x || Math.random() * this.canvas.width,
            config.y || Math.random() * this.canvas.height,
            config.size || 30,
            config.color || '#44ff44',
            config.dx || 0,
            config.dy || 0
        );
        this.addObject(triangle);
    }

    createText(config) {
        const text = new TextObject(
            config.x || this.canvas.width / 2,
            config.y || this.canvas.height / 2,
            config.text || 'Hello World!',
            config.color || '#333333',
            config.fontSize || 24
        );
        this.addObject(text);
    }

    createParticles(config) {
        const count = config.count || 10;
        for (let i = 0; i < count; i++) {
            const particle = new Particle(
                config.x + (Math.random() - 0.5) * 50,
                config.y + (Math.random() - 0.5) * 50,
                config.color || '#ffaa00'
            );
            this.addObject(particle);
        }
    }

    setBouncing(enabled) {
        this.objects.forEach(obj => {
            if (obj.setBouncing) {
                obj.setBouncing(enabled);
            }
        });
    }

    setGravity(enabled) {
        this.objects.forEach(obj => {
            if (obj.setGravity) {
                obj.setGravity(enabled);
            }
        });
    }
}

// Game Object Classes
class GameObject {
    constructor(x, y, color) {
        this.x = x;
        this.y = y;
        this.color = color;
        this.dx = 0;
        this.dy = 0;
        this.bouncing = false;
        this.gravity = false;
        this.gravityForce = 0.3;
        this.type = 'object';
    }

    update(deltaTime, canvasWidth, canvasHeight) {
        if (this.gravity) {
            this.dy += this.gravityForce;
        }

        this.x += this.dx;
        this.y += this.dy;

        if (this.bouncing) {
            this.handleBouncing(canvasWidth, canvasHeight);
        }
    }

    handleBouncing(canvasWidth, canvasHeight) {
        const margin = this.width || this.radius || 10;
        
        if (this.x - margin <= 0 || this.x + margin >= canvasWidth) {
            this.dx = -this.dx * 0.8; // Energy loss
            this.x = Math.max(margin, Math.min(canvasWidth - margin, this.x));
        }
        
        if (this.y - margin <= 0 || this.y + margin >= canvasHeight) {
            this.dy = -this.dy * 0.8; // Energy loss
            this.y = Math.max(margin, Math.min(canvasHeight - margin, this.y));
        }
    }

    setBouncing(enabled) {
        this.bouncing = enabled;
        if (enabled && this.dx === 0 && this.dy === 0) {
            this.dx = (Math.random() - 0.5) * 4;
            this.dy = (Math.random() - 0.5) * 4;
        }
    }

    setGravity(enabled) {
        this.gravity = enabled;
    }

    onClick() {
        // Default click behavior - add some movement
        this.dx += (Math.random() - 0.5) * 6;
        this.dy += (Math.random() - 0.5) * 6;
    }
}

class Circle extends GameObject {
    constructor(x, y, radius, color, dx = 0, dy = 0) {
        super(x, y, color);
        this.radius = radius;
        this.width = radius * 2;
        this.height = radius * 2;
        this.dx = dx;
        this.dy = dy;
        this.type = 'circle';
    }

    render(ctx) {
        ctx.fillStyle = this.color;
        ctx.beginPath();
        ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
        ctx.fill();
        
        // Add border
        ctx.strokeStyle = '#333';
        ctx.lineWidth = 2;
        ctx.stroke();
    }
}

class Square extends GameObject {
    constructor(x, y, width, height, color, dx = 0, dy = 0) {
        super(x, y, color);
        this.width = width;
        this.height = height;
        this.dx = dx;
        this.dy = dy;
        this.type = 'square';
    }

    render(ctx) {
        ctx.fillStyle = this.color;
        ctx.fillRect(this.x - this.width/2, this.y - this.height/2, this.width, this.height);
        
        // Add border
        ctx.strokeStyle = '#333';
        ctx.lineWidth = 2;
        ctx.strokeRect(this.x - this.width/2, this.y - this.height/2, this.width, this.height);
    }
}

class Triangle extends GameObject {
    constructor(x, y, size, color, dx = 0, dy = 0) {
        super(x, y, color);
        this.size = size;
        this.width = size;
        this.height = size;
        this.dx = dx;
        this.dy = dy;
        this.type = 'triangle';
    }

    render(ctx) {
        ctx.fillStyle = this.color;
        ctx.beginPath();
        ctx.moveTo(this.x, this.y - this.size);
        ctx.lineTo(this.x - this.size, this.y + this.size);
        ctx.lineTo(this.x + this.size, this.y + this.size);
        ctx.closePath();
        ctx.fill();
        
        // Add border
        ctx.strokeStyle = '#333';
        ctx.lineWidth = 2;
        ctx.stroke();
    }
}

class TextObject extends GameObject {
    constructor(x, y, text, color, fontSize = 24) {
        super(x, y, color);
        this.text = text;
        this.fontSize = fontSize;
        this.width = text.length * fontSize * 0.6;
        this.height = fontSize;
        this.type = 'text';
    }

    render(ctx) {
        ctx.fillStyle = this.color;
        ctx.font = `${this.fontSize}px Arial`;
        ctx.textAlign = 'center';
        ctx.textBaseline = 'middle';
        ctx.fillText(this.text, this.x, this.y);
        
        // Add outline
        ctx.strokeStyle = '#fff';
        ctx.lineWidth = 3;
        ctx.strokeText(this.text, this.x, this.y);
        ctx.fillText(this.text, this.x, this.y);
    }
}

class Particle extends GameObject {
    constructor(x, y, color) {
        super(x, y, color);
        this.radius = Math.random() * 5 + 2;
        this.dx = (Math.random() - 0.5) * 8;
        this.dy = (Math.random() - 0.5) * 8;
        this.life = 1.0;
        this.decay = Math.random() * 0.02 + 0.01;
        this.width = this.radius * 2;
        this.height = this.radius * 2;
        this.type = 'particle';
    }

    update(deltaTime, canvasWidth, canvasHeight) {
        super.update(deltaTime, canvasWidth, canvasHeight);
        this.life -= this.decay;
        
        // Remove particle when life is over
        if (this.life <= 0) {
            this.shouldRemove = true;
        }
    }

    render(ctx) {
        ctx.save();
        ctx.globalAlpha = this.life;
        ctx.fillStyle = this.color;
        ctx.beginPath();
        ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
        ctx.fill();
        ctx.restore();
    }
}

// Global game functions
let game;

function saveApiKey() {
    const apiKey = document.getElementById('apiKey').value.trim();
    if (apiKey) {
        localStorage.setItem('geminiApiKey', apiKey);
        game.apiKey = apiKey;
        game.showStatus('apiStatus', 'API key saved successfully!', 'success');
    } else {
        game.showStatus('apiStatus', 'Please enter a valid API key', 'error');
    }
}

function processPrompt() {
    game.processPrompt();
}

function clearCanvas() {
    game.clearCanvas();
    game.showStatus('promptStatus', 'Canvas cleared!', 'info');
}

function pauseGame() {
    game.isPaused = !game.isPaused;
    const pauseBtn = document.getElementById('pauseBtn');
    pauseBtn.textContent = game.isPaused ? '▶️ Resume' : '⏸️ Pause';
    game.showStatus('promptStatus', game.isPaused ? 'Game paused' : 'Game resumed', 'info');
}

function resetGame() {
    game.clearCanvas();
    game.isPaused = false;
    document.getElementById('pauseBtn').textContent = '⏸️ Pause';
    game.showStatus('promptStatus', 'Game reset!', 'info');
}

// Initialize game when page loads
window.addEventListener('load', () => {
    game = new GameEngine();
    
    // Clean up particles that have expired
    setInterval(() => {
        game.objects = game.objects.filter(obj => !obj.shouldRemove);
    }, 1000);
});