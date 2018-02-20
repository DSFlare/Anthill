#pragma once
#include "ForestObject.h"
#include "../Graphic/Drawable3D.h"

class Landscape: public ForestObject, public Drawable3D
{
	//float vertices[];
	vec3* cubePositions;
	GLuint VAO, VBO;
	sf::Texture texture;

public:
	Landscape(sf::RenderWindow* window_, Camera* camera_);
	~Landscape();

	virtual void Update() override;
};

