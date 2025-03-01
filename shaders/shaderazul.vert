#version 330
layout (location = 0) in vec3 pos;

out vec4 vColor;
uniform mat4 model;
uniform mat4 projection;

void main()
{
    gl_Position = projection * model * vec4(pos, 1.0);
    
    // Create gradient based on position
    float gradientFactor = (pos.y + 0.5) * 0.5 + 0.5;
    
    // Navy blue base color: RGB(0.0, 0.0, 0.5)
    // Lighter variation: RGB(0.1, 0.2, 0.6)
    float r = 0.0 + (0.1 * gradientFactor);
    float g = 0.0 + (0.2 * gradientFactor);
    float b = 0.4 + (0.2 * gradientFactor);
    
    vColor = vec4(r, g, b, 1.0);
}