#pragma once
#include "ForestObject.h"

class Anthill: public ForestObject
{
public:
	Anthill(sf::RenderWindow* window_, Camera* camera_, Resources* res_);
	~Anthill();

	virtual void Update() override;
};

