#version 330 core
 
layout (location=0) out vec4 vFragColor;	//fragment shader output

//input from the vertex shader
smooth in vec2 vUV;		//2D texture coordinates

//shader uniform
uniform sampler2D textureMap;		//the image to display
uniform sampler3D iccMap;
uniform float brightness;
uniform float scale;

void main()
{
	//sample the textureMap at the given 2D texture coodinates to obntain the colour
        //vFragColor =   vec4(brightness);
        vec3 coloridx = texture(textureMap, vUV).xyz;
        vFragColor =   vec4(coloridx, 1.0);
        //vFragColor =   vec4(texture(iccMap, coloridx).xyz, 1.0);
}
