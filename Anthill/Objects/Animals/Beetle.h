#pragma once
#include "Organism.h"
class Beetle :
	public Organism
{
public:
	Beetle(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
		sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(0.1, 0.1, 0.1));
	virtual void Destroy() override;
	virtual void Update() override;
	~Beetle();

private:
	void checkAnts();
};

