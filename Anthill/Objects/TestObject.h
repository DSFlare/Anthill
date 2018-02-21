#pragma once
#include "ForestObject.h"
#include "../Graphic/Drawable3D.h"

class TestObject: public ForestObject, public Drawable3D
{
	//float vertices[];
	//vec3* cubePositions;
	GLuint VAO, VBO;
	//sf::Texture* texture;

public:
	TestObject(sf::RenderWindow * window_, Camera * camera_, Resources* res_);
	~TestObject();

	virtual void Update() override;
};

