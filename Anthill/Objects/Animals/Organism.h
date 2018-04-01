#pragma once
#include "../ForestObject.h"

class Organism
	: public ForestObject
{
private:
	
protected:
	int health;
	int attack;
	vec3 velosity; //скорость

public:
	Organism(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_,
		sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));

	virtual void Update() override;
	void Start();
	int getHealth();
	void setHealth(int health);
	int getAttack();
	void setAttack(int attack);
	void makeDamage(int damage);
	virtual void Destroy() = 0;
	virtual ~Organism();
};