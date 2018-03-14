#pragma once
#include "ForestObject.h"

class Landscape: public ForestObject
{
private:
	GLuint VAO, VBO;
public:
	Landscape(sf::RenderWindow * window_, Camera * camera_, Resources* res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
		int landscapeWidth, int landscapeHeight);
	~Landscape();

	virtual void Update() override;
};

