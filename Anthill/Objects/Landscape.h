#pragma once
#include "ForestObject.h"
#include "../Graphic/Drawable3D.h"

class Landscape: public ForestObject, public Drawable3D
{
	GLuint VAO, VBO;
public:
	Landscape(sf::RenderWindow * window_, Camera * camera_, Resources* res_);
	~Landscape();

	virtual void Update() override;
};

