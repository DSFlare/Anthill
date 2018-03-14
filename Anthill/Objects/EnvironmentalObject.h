#pragma once
#include "ForestObject.h"

enum Kind {
	FENCE
};
//������������� ������� (����. �������, �����, �����)
class EnvironmentalObject
	: public ForestObject
{
public:
	EnvironmentalObject(sf::RenderWindow* window_, Camera* camera_, Resources * res_, Parametres* par_, 
		std::vector<ForestObject*>* allObjects_, Kind Kind,
		vec3 position_,	vec3 rotation_,vec3 scale_);
	virtual void Update() override;
	~EnvironmentalObject();
};

