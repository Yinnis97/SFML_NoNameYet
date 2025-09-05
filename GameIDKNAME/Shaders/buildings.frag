#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 resolution;
uniform float time;


void main() 
{
	vec2 st = gl_FragCoord.xy/resolution;
	
	gl_FragColor = vec4(st.y,st.y,st.y,1.0);
}

//vec3 baseColor = vec3(0.0,0.345,0.69); 
//vec3 highlight = vec3(0.0,0.212,0.424);