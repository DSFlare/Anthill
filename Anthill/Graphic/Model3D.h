#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL\glew.h>
#include <vector>
#include <iostream>
#include "Mesh.h"
#include "Shader.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <SFML/Graphics.hpp>

using std::vector;
using std::string;

class Model3D
{
public:
	/*  ������   */
	Model3D(char *path, sf::Texture *texture);
	void Draw(Shader shader);
	void changeTexture(sf::Texture *texture);
private:
	/*  ������ ������  */
	sf::Texture* texture;
	vector<Mesh> meshes;
	string directory;
	/*  ������   */
	void loadModel(string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
};