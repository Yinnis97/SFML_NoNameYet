#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 resolution;
uniform float time;


void main() 
{
	vec2 st = gl_FragCoord.xy/resolution;
	
	gl_FragColor = vec4(st.x,st.x,st.x,1.0);
}