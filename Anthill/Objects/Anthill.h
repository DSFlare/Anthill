#pragma once
#include "ForestObject.h"
#include "../Graphic/Drawable3D.h"

class Anthill: public ForestObject, public Drawable3D
{
public:
	Anthill(sf::RenderWindow* window_, Camera* camera_, Resources* res_);
	~Anthill();
};

