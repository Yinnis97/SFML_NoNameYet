#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 resolution;
uniform float time;

// 2D noise function
float hash(vec2 p){
    return fract(sin(dot(p,vec2(127.1,311.7)))*43758.5453);
}

float noise(vec2 p){
    vec2 i = floor(p);
    vec2 f = fract(p);
    float a = hash(i);
    float b = hash(i+vec2(1.0,0.0));
    float c = hash(i+vec2(0.0,1.0));
    float d = hash(i+vec2(1.0,1.0));
    vec2 u = f*f*(3.0-2.0*f);
    return mix(a,b,u.x) + (c-a)*u.y*(1.0-u.x) + (d-b)*u.x*u.y;
}

void main(){
    vec2 uv = gl_FragCoord.xy / resolution;
    vec2 pos = uv*20.0;
    
    // noise for cracks / irregularity
    float n = noise(pos + time*0.05);
    
    // Slight directional lines for path feeling
    float lines = sin(pos.x*2.0)*0.05;
    
	vec3 baseColor = vec3(0.0,0.345,0.69); 
    vec3 highlight = vec3(0.0,0.212,0.424);

    vec3 color = mix(baseColor, highlight, n) + lines;
    
    gl_FragColor = vec4(color,1.0);
}