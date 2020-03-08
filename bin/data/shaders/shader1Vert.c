#version 120
#extension GL_ARB_texture_rectangle: enable
#extension GL_EXT_gpu_shader4: enable
uniform float startTime = -1.0;
uniform float ellapsedTime;


float rand(float n){return fract(sin(n) * 43758.5453123);}

float noise(float p){
    float fl = floor(p);
  float fc = fract(p);
    return mix(rand(fl), rand(fl + 1.0), fc);
}

void main() {
    float duration = 10.0;
    vec3 v = gl_Vertex.xyz;
    
    if (startTime > -1.0) {
        float difference = ellapsedTime - startTime;
        if (difference < duration/2) {
            v.x += sin(v.x * difference / 5);
            v.y += sin(v.y * difference / 5);
            v.z += sin(v.z * difference / 5);
        } else if (difference < duration){
            v.x += sin(v.x * (duration/2 - abs(duration/2- difference)) / 5);
            v.y += sin(v.y * (duration/2 - abs(duration/2- difference)) / 5);
            v.z += sin(v.z * (duration/2 - abs(duration/2- difference)) / 5);
        }
    }
        
//    if (index == gl_VertexID){
//    v.x += noise(v.x);
//    v.y += noise(v.y);
//    v.z += noise(v.z);
//        v.x = sin(v.x * 1.3);
//        v.y = sin(v.y * 1.3);
//        v.z = sin(v.z * 1.3);
//    }
    
    vec4 posHomog = vec4(v, 1.0);
    gl_Position = gl_ModelViewProjectionMatrix * posHomog;
    
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_FrontColor = gl_Color;
}
