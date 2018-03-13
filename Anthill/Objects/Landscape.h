#pragma once
#include "ForestObject.h"
//#include "../Graphic/Drawable3D.h"

class Landscape: public ForestObject
{
private:
	GLuint VAO, VBO;
public:
	Landscape(sf::RenderWindow * window_, Camera * camera_, Resources* res_, int landscapeWidth, int landscapeHeight);
	~Landscape();

	virtual void Update() override;
};

