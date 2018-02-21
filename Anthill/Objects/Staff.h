#pragma once
#include "ForestObject.h"
#include "../Graphic/Drawable3D.h"
#include "../Resources/Resources.h"

class Staff: public ForestObject, public Drawable3D
{

public:
	Staff(sf::RenderWindow* window_, Camera* camera_, Resources * res_);
	~Staff();

	
};

