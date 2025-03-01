// redShader.frag
#version 330

out vec4 color;

void main()
{
    // Output pure red color (R=1, G=0, B=0, A=1)
    color = vec4(1.0, 0.0, 0.0, 1.0);
}