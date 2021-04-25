#version 330 core

in vec3 vertCol;
out vec4 fragColor;

void main()
{
    fragColor = vec4(vertCol, 1.0);
}