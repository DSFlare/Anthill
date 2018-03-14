#pragma once
#include "ForestObject.h"

class Anthill: public ForestObject
{
public:

	Anthill(sf::RenderWindow* window_, Camera* camera_, Resources* res_, Parametres* par_, std::vector<ForestObject*>* allObjects_);
	~Anthill();

	virtual void Update() override;
};

