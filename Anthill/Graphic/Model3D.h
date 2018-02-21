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

unsigned int TextureFromFile(const char *path, const string &directory);

class Model3D
{
public:
	/*  ������   */
	Model3D(char *path){ loadModel(path); }
	void Draw(Shader shader);
private:
	//������ ��� ����������� �������
	vector<Texture> textures_loaded;
	/*  ������ ������  */
	vector<Mesh> meshes;
	string directory;
	/*  ������   */
	void loadModel(string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};