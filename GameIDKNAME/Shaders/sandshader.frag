#ifdef GL_ES
precision mediump float;
#endif

// Uniforms
uniform vec2 resolution;
uniform float time;


// ---- Simple hash-based pseudo-random noise ----
float random(vec2 st) 
{
    return fract(sin(dot(st.xy, vec2(12.9898, 78.233))) * 43758.5453123);
}

// ---- Smooth noise ----
float noise(vec2 st) 
{
    vec2 i = floor(st);
    vec2 f = fract(st);

    // Four corners
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));

    // Smooth interpolation
    vec2 u = f * f * (3.0 - 2.0 * f);

    return mix(a, b, u.x) +
           (c - a) * u.y * (1.0 - u.x) +
           (d - b) * u.x * u.y;
}

void main() 
{
    // Normalize coordinates (0 to 1)
    vec2 uv = gl_FragCoord.xy * resolution / max(resolution.x, resolution.y);

    // Scale the texture for finer grain
    vec2 pos = uv * 15.0;

    // Base noise pattern
    float n = noise(pos + time * 0.05);

    // Additional small variation to avoid uniformity
    float grain = noise(pos * 3.0 + vec2(time * 0.1));

    // Combine noises for a sandy pattern
    float sandPattern = mix(n, grain, 0.5);

    // Sand-like colors
    vec3 lightSand = vec3(0.93, 0.82, 0.62); // light beige
    vec3 darkSand  = vec3(0.76, 0.66, 0.47); // darker sandy brown

    // Blend between light and dark based on the noise
    vec3 color = mix(lightSand, darkSand, sandPattern);

    // Slight highlight shimmer effect
    color += 0.03 * sin(time + uv.x * 20.0 + uv.y * 20.0);

    gl_FragColor = vec4(color, 1.0);
}
