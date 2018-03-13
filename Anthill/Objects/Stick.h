#pragma once
#include "ForestObject.h"

class Stick
	:public ForestObject
{
public:
	Stick(sf::RenderWindow* window_, Camera* camera_, Resources * res_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));
	virtual void Update() override;
	~Stick();
};

