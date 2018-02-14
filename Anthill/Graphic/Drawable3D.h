#pragma once
#include "Model3D.h"
#include "Shader.h"
#include <SFML\Graphics.hpp>

class Drawable3D
{
	Model3D mesh;
	Shader* shader;
	sf::Texture texture;
public:
	Drawable3D();
	~Drawable3D();
};

