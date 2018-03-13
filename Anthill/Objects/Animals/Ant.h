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
	Role role = EADLE;
	vec3 anthillCoord; //координаты родного муравейника

	//For stearing behaviour
	float maxVelosity = 0.015;	//максимальная дальность передвижения
	float maxForce = 0.02f;	//макс величина изменения velosity
	float circkeDistance = 2;	//круг перед существом, для рандомного движения
	float circleRadius = 0.7;  //радиус круга
	float changeDirTimer = 0;

public:

	Ant(Camera * camera_, Resources * res_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(0.1, 0.1, 0.1));

	virtual void Death() override;
	virtual void Update() override;
	virtual ~Ant();

	Role getRole() { return role; }
	
	//Входные точки в роли
	void Scout(); //приносит ресурсы и сообщает о живой еде
	void Scout(ForestObject* target); //приносит ресурсы и сообщает о живой еде
	void Hunter(Organism* target); //
	void Eadle();
	//TODO
	void Warrior();

private:
	//Eadle

	//методы Hunter

	//методы Scout
	void explore();
	void pickUp(ForestObject item);


	//методы Warrior

	//для движения
	vec3 followTowards(vec3 target);
};