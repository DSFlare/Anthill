#pragma once
#include "../ForestObject.h"
#include "../../Graphic/Drawable3D.h"
class Organism
	: public ForestObject, public Drawable3D
{
private:
	int health;
	int attack;
public:
	Organism(Camera * camera_, Resources * res_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));
	virtual void Update() override;
	void Start();
	int getHealth();
	void setHealth(int health);
	int getAttack();
	void setAttack(int attack);
	virtual void Death() = 0;
	virtual ~Organism();
};

