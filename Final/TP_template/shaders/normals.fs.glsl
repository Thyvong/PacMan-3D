#version 330

// Entrées du shader
in vec3 vPosition_vs; // not used yet
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // not used yet

out vec3 fFragColor;

uniform sampler2D uTexture;

void main() {
	fFragColor = vec3(texture(uTexture,vTexCoords));
    //fFragColor =normalize(vNormal_vs);
}
