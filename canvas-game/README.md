# AI Canvas Game - Powered by Gemini API

A dynamic canvas-based game application that uses Google's Gemini AI to interpret natural language prompts and create interactive game elements in real-time.

## 🎮 Features

- **AI-Powered Game Creation**: Use natural language to create and control game elements
- **Real-time Canvas Rendering**: Smooth 60 FPS game loop with interactive objects
- **Multiple Object Types**: Circles, squares, triangles, text, and particle systems
- **Physics Simulation**: Bouncing, gravity, and collision detection
- **Interactive Elements**: Click on objects to interact with them
- **Responsive Design**: Works on desktop and mobile devices

## 🚀 Getting Started

### Prerequisites

1. **Gemini API Key**: You'll need a Google AI API key to use Gemini
   - Go to [Google AI Studio](https://makersuite.google.com/app/apikey)
   - Create a new API key
   - Keep it secure and don't share it publicly

### Installation

1. Open the `canvas-game` folder
2. Open `index.html` in a web browser
3. Enter your Gemini API key in the settings panel
4. Start giving commands to create your game!

## 🎯 How to Use

### Basic Commands

Try these example prompts to get started:

#### Creating Objects
- `"Create a red bouncing ball"`
- `"Draw a blue square in the center"`
- `"Add a green triangle that moves"`
- `"Create yellow text saying 'Hello World'"`

#### Adding Physics
- `"Make all objects bounce"`
- `"Enable gravity for everything"`
- `"Create a bouncing ball with gravity"`

#### Visual Effects
- `"Add particle explosion at the center"`
- `"Create 20 colorful particles"`
- `"Add sparkling effects"`

#### Game Control
- `"Clear the screen"`
- `"Remove all objects"`
- `"Reset the game"`

### Advanced Commands

The AI can understand more complex instructions:

- `"Create a red ball that bounces between two blue walls"`
- `"Add a text message that says 'Game Over' in large red letters"`
- `"Create a particle system with 50 golden particles"`
- `"Make a green square that follows the mouse"`
- `"Add obstacles that the ball can bounce off"`

### Interactive Features

- **Click Objects**: Click on any game object to give it a random impulse
- **Canvas Grid**: Visual grid helps with positioning
- **Real-time Stats**: See object count and FPS in real-time
- **Game Controls**: Pause, resume, clear, and reset the game

## 🛠️ Technical Details

### Game Objects

The game supports several types of objects:

1. **Circle**: Circular objects with radius and color
2. **Square/Rectangle**: Rectangular objects with width and height
3. **Triangle**: Triangular objects with size
4. **Text**: Text objects with customizable font size
5. **Particle**: Small animated particles with life cycles

### Physics System

- **Bouncing**: Objects can bounce off canvas boundaries
- **Gravity**: Realistic gravity simulation
- **Collision Detection**: Basic boundary collision
- **Energy Loss**: Bouncing includes energy dissipation

### AI Integration

The game uses Google's Gemini Pro model to:
- Parse natural language commands
- Generate JSON game actions
- Understand context and intent
- Create appropriate game responses

## 🎨 Customization

### Adding New Object Types

To add new object types, extend the `GameObject` class:

```javascript
class NewObject extends GameObject {
    constructor(x, y, customProperty) {
        super(x, y, '#ff0000');
        this.customProperty = customProperty;
        this.type = 'newObject';
    }

    render(ctx) {
        // Custom rendering code
    }

    update(deltaTime, canvasWidth, canvasHeight) {
        super.update(deltaTime, canvasWidth, canvasHeight);
        // Custom update logic
    }
}
```

### Modifying AI Prompts

The AI system prompt can be customized in the `callGeminiAPI` method to:
- Add new action types
- Change object behaviors
- Modify game rules
- Add new features

## 🔧 Configuration

### Canvas Settings

- **Size**: 800x600 pixels (can be modified in code)
- **Background**: Light gray with grid overlay
- **FPS Target**: 60 FPS with automatic adjustment

### API Settings

- **Model**: Gemini Pro
- **Temperature**: 0.3 (for consistent responses)
- **Max Tokens**: 1000
- **Response Format**: JSON

## 🐛 Troubleshooting

### Common Issues

1. **API Key Not Working**
   - Verify your Gemini API key is correct
   - Check that the API key has proper permissions
   - Ensure you're not exceeding rate limits

2. **Objects Not Appearing**
   - Check the browser console for errors
   - Verify the AI response is valid JSON
   - Try simpler commands first

3. **Performance Issues**
   - Reduce the number of objects on screen
   - Clear particles regularly
   - Check FPS counter

### Error Messages

- `"API request failed"`: Check your API key and internet connection
- `"No valid action could be generated"`: Try rephrasing your command
- `"Failed to parse AI response"`: The AI returned invalid JSON

## 🚀 Future Enhancements

Potential improvements for the game:

- [ ] Sound effects and music
- [ ] Save/load game states
- [ ] Multiplayer support
- [ ] More complex physics
- [ ] Game templates and presets
- [ ] Animation sequences
- [ ] Custom brushes and drawing tools
- [ ] Achievement system

## 📝 License

This project is open source and available under the MIT License.

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Add new object types
- Improve the AI prompts
- Enhance the physics system
- Add new features
- Fix bugs and improve performance

## 📞 Support

If you encounter issues or have questions:
1. Check the troubleshooting section
2. Look at the browser console for error messages
3. Try different prompt variations
4. Ensure your API key is valid and has permissions