#pragma once
#include "Organism.h"

enum Role {
	SCOUT,
	WARRIOR,
	HUNTER,
	EADLE
};

class Ant : public Organism
{
private:

	void(Ant::*action)();
	int role = EADLE;
public:

	virtual void Death();
	virtual void Update() override;
	Role* getRole();
	Ant(Camera * camera_, Resources * res_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));
	virtual ~Ant();


	//Входные точки в роли
	void Scout(); //приносит ресурсы и сообщает о живой еде
	void Scout(ForestObject* target); //приносит ресурсы и сообщает о живой еде
	void Hunter(Organism* target); //

	//TODO
	void Warrior();
};