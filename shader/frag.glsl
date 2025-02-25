#version 450 core

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

uniform float ambientStrength;
uniform float specularStrength;


/* 
  Chat gpt generated junk shader.
*/

const bool enableLighting = true;

vec3 calculateLighting(vec3 normal, vec3 fragPos, vec3 lightPos, vec3 viewPos, vec3 lightColor, vec3 objectColor) {
  // Ambient
  vec3 ambient = ambientStrength * lightColor;
  
  // Diffuse 
  vec3 norm = normalize(normal);
  vec3 lightDir = normalize(lightPos - fragPos);
  float diff = max(dot(norm, lightDir), 0.0);
  vec3 diffuse = diff * lightColor;
  
  
  float shininess = 32.0;
  vec3 viewDir = normalize(viewPos - fragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
  vec3 specular = specularStrength * spec * lightColor;


  return (ambient + diffuse + specular) * objectColor;
}

void main() {
  vec3 result;
  if (enableLighting) {
    result = calculateLighting(Normal, FragPos, lightPos, viewPos, lightColor, objectColor);
  } else {
    result = objectColor;
  }
  FragColor = vec4(result, 1.0);
}