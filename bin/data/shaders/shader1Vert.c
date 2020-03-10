#version 120
#extension GL_ARB_texture_rectangle: enable
#extension GL_EXT_gpu_shader4: enable
uniform float ellapsedTime;


float rand(float n){return fract(sin(n) * 43758.5453123);}

float noise(float p){
    float fl = floor(p);
    float fc = fract(p);
    return mix(rand(fl), rand(fl + 1.0), fc);
}

void main() {
    vec3 v = gl_Vertex.xyz;
    v.x += sin(v.x * ellapsedTime / 5);
    v.y += sin(v.y * ellapsedTime / 5);
    v.z += sin(v.z * ellapsedTime / 5);
    
    vec4 posHomog = vec4(v, 1.0);
    gl_Position = gl_ModelViewProjectionMatrix * posHomog;
    
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_FrontColor = gl_Color;
}
