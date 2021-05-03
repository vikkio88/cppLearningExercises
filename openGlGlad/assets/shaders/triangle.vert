#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vCol;
layout (location = 2) in vec2 vTextCoord;

out vec3 vertCol;
out vec2 textCoord;
void main()
{
   vertCol = vCol;
   //gl_Position = vec4(vPos.x, vPos.y, vPos.z, 1.0);
   // swizzling            ↑ we get this ↓
   gl_Position = vec4(vPos.xyz, 1.0);

   textCoord = vTextCoord;
}