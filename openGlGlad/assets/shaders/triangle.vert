#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vCol;

out vec3 vertCol;
void main()
{
   vertCol = vCol;
   //gl_Position = vec4(vPos.x, vPos.y, vPos.z, 1.0);
   // swizzling            ↑ we get this ↓
   gl_Position = vec4(vPos.xyz, 1.0);
}