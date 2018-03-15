#pragma once
#include "Organism.h"
class Caterpillar :
	public Organism
{
public:
	Caterpillar(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));
	virtual void Death() override;
	~Caterpillar();
};

