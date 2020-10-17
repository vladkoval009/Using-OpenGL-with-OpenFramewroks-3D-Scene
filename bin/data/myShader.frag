#version 150

uniform float time;
uniform vec2 resolution;
uniform sampler2DRect tex;


in vec2 texCoordVarying;
out vec4 outputColor;

void main() {

  vec2 p = (gl_FragCoord.xy * 2.0 - resolution) / min(resolution.x, resolution.y);

    vec2 t = vec2(resolution.x, -resolution.y) / min(resolution.x, resolution.y);
    
    t.xy += vec2(-resolution.x, resolution.y) / min(resolution.x, resolution.y);

    vec2 sz = vec2(resolution.x, resolution.y) / min(resolution.x, resolution.y);
    
    vec2 q = p + t;
    
    float d = length(q);
    
    if(d < length(sz)){

      float a = atan(q.y, q.x);
      float x = t.x + cos(a + time * 3 + d * 2) * d;
      float y = t.y + sin(a + time * 3 + d * 2) * d;
      p = vec2(x, y);
        
    }

    vec4 color = texture(tex, vec2((p.x * min(resolution.x, resolution.y) + resolution.x) * 0.8,  (p.y * min(resolution.x, resolution.y) + resolution.y) * 0.8));
  
    outputColor = vec4(vec3(color.rgb), color.a);

}
