// Demo script for AI Canvas Game
// This file contains example prompts and demonstrations

const demoPrompts = [
    // Basic object creation
    "Create a red bouncing ball",
    "Draw a blue square in the center", 
    "Add a green triangle that moves",
    "Create yellow text saying 'Welcome to AI Game'",
    
    // Physics demonstrations
    "Make all objects bounce around",
    "Enable gravity for everything",
    "Create a ball that falls with gravity",
    
    // Visual effects
    "Add colorful particle explosion at position 400, 300",
    "Create 30 golden particles",
    "Add sparkling effects",
    
    // Complex scenarios
    "Create a red ball bouncing between two blue walls",
    "Add obstacles that objects can bounce off",
    "Create a particle fountain effect",
    "Make a rainbow of colored circles",
    
    // Game control
    "Clear the screen",
    "Reset all physics",
    "Remove all objects"
];

const demoInstructions = [
    {
        title: "Getting Started",
        steps: [
            "Enter your Gemini API key in the settings panel",
            "Try the prompt: 'Create a red bouncing ball'",
            "Click on objects to interact with them",
            "Watch the real-time stats at the bottom"
        ]
    },
    {
        title: "Physics Fun",
        steps: [
            "Create several objects with: 'Add 5 colorful circles'",
            "Enable bouncing: 'Make all objects bounce'",
            "Add gravity: 'Turn on gravity for everything'",
            "Watch the chaos unfold!"
        ]
    },
    {
        title: "Creative Mode",
        steps: [
            "Try: 'Create a smiley face with yellow circles'",
            "Add text: 'Write Game Over in big red letters'",
            "Make art: 'Create a rainbow pattern'",
            "Add effects: 'Particle explosion at the center'"
        ]
    }
];

// Function to run a demo sequence
function runDemo(demoIndex = 0) {
    if (!game || !game.apiKey) {
        console.log("Please set up the game and API key first!");
        return;
    }

    if (demoIndex >= demoPrompts.length) {
        console.log("Demo completed!");
        return;
    }

    const prompt = demoPrompts[demoIndex];
    console.log(`Demo ${demoIndex + 1}: ${prompt}`);
    
    // Set the prompt in the input field
    document.getElementById('promptInput').value = prompt;
    
    // Execute the prompt
    game.processPrompt().then(() => {
        // Wait 3 seconds then run next demo
        setTimeout(() => {
            runDemo(demoIndex + 1);
        }, 3000);
    });
}

// Function to show random demo prompt
function getRandomDemoPrompt() {
    return demoPrompts[Math.floor(Math.random() * demoPrompts.length)];
}

// Function to validate game setup
function validateGameSetup() {
    const issues = [];
    
    if (!game) {
        issues.push("Game engine not initialized");
    }
    
    if (!game.apiKey) {
        issues.push("Gemini API key not set");
    }
    
    if (!game.canvas) {
        issues.push("Canvas not found");
    }
    
    if (!game.ctx) {
        issues.push("Canvas context not available");
    }
    
    return {
        isValid: issues.length === 0,
        issues: issues
    };
}

// Function to test API connectivity
async function testAPIConnection() {
    if (!game || !game.apiKey) {
        return { success: false, error: "No API key set" };
    }
    
    try {
        const result = await game.callGeminiAPI("Create a small red circle");
        return { 
            success: true, 
            response: result,
            message: "API connection successful"
        };
    } catch (error) {
        return { 
            success: false, 
            error: error.message 
        };
    }
}

// Export demo functions for global use
window.demoFunctions = {
    runDemo,
    getRandomDemoPrompt,
    validateGameSetup,
    testAPIConnection,
    demoPrompts,
    demoInstructions
};

// Add demo button to the interface when page loads
window.addEventListener('load', () => {
    setTimeout(() => {
        // Add demo section to controls
        const controls = document.querySelector('.game-controls');
        if (controls) {
            const demoSection = document.createElement('div');
            demoSection.style.marginTop = '15px';
            demoSection.style.paddingTop = '15px';
            demoSection.style.borderTop = '1px solid #ddd';
            
            demoSection.innerHTML = `
                <label>🎬 Demo Mode:</label>
                <button onclick="demoFunctions.runDemo()" style="margin: 5px;">🎮 Run Demo</button>
                <button onclick="document.getElementById('promptInput').value = demoFunctions.getRandomDemoPrompt()" style="margin: 5px;">🎲 Random Prompt</button>
            `;
            
            controls.appendChild(demoSection);
        }
        
        // Add validation info
        const validation = validateGameSetup();
        if (!validation.isValid) {
            console.warn("Game setup issues:", validation.issues);
        } else {
            console.log("✅ Game setup validated successfully!");
        }
    }, 1000);
});