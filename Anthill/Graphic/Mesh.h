#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL\glew.h>
#include <assimp\Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <SFML\Graphics.hpp>

#include "Shader.h"

#include <vector>
#include <iostream>

using std::vector;
using std::string;

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

class Mesh
{
public:
	/*  Mesh Data  */
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	sf::Texture *texture;
	/*  Functions  */
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, sf::Texture *texture);
	void Draw(Shader shader);
private:
	/*  Render data  */
	unsigned int VAO, VBO, EBO;
	/*  Functions    */
	void setupMesh();
};