#pragma once
#include "Organism.h"
#include "AntRoles\Role.h"
class Ant :
	public Organism
{
	Role* role;
	int currentTask;
public:
	virtual void Death();
	virtual void Update() override;
	Role* getRole();
	Ant(Camera * camera_, Resources * res_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));
	virtual ~Ant();
};

