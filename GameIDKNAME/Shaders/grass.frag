#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform vec2 resolution;

float hash(vec2 p){ return fract(sin(dot(p, vec2(127.1,311.7)))*43758.5453); }

float noise(vec2 p)
{
    vec2 i = floor(p);
    vec2 f = fract(p);
    float a = hash(i);
    float b = hash(i+vec2(1.0,0.0));
    float c = hash(i+vec2(0.0,1.0));
    float d = hash(i+vec2(1.0,1.0));
    vec2 u = f*f*(3.0-2.0*f);
    return mix(a,b,u.x)+(c-a)*u.y*(1.0-u.x)+(d-b)*u.x*u.y;
}

void main(){
    vec2 uv = gl_FragCoord.xy/resolution;
    vec2 pos = uv*30.0;
    
    // swaying grass
    float sway = sin(pos.x*0.5 + time*2.0)*0.15;
    float n = noise(pos + vec2(0.0,sway));
    
    vec3 lightGrass = vec3(0.3,0.7,0.25);
    vec3 darkGrass  = vec3(0.15,0.5,0.1);
    
    vec3 color = mix(lightGrass,darkGrass,n);
    
    // vertical gradient for depth
    color *= uv.y*0.8 + 0.2;
    
    gl_FragColor = vec4(color,1.0);
}
