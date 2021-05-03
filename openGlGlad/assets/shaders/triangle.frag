#version 330 core

out vec4 fragColor;

in vec3 vertCol;
in vec2 textCoord;

uniform sampler2D myTexture;

void main()
{
    //fragColor = vec4(vertCol, 1.0);
    fragColor = texture(myTexture, textCoord);
}