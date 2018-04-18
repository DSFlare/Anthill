#include "Beetle.h"
#include "glm/gtx/rotate_vector.hpp"
#include "../../UI/Notificator.h"


Beetle::Beetle(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
	sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, par_, allObjects_, window_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->queenTex);
	model = new Model3D(res->beetleModel, texture);
	tag = "Beetle";
	health = par->beetlePar.health;
	attack = par->beetlePar.attack;
	action = &Beetle::explore;

	velosity = vec3(par->beetlePar.maxVelosity, 0, 0);
	glm::rotateY(velosity, (rand() % 360) * 1.0f);
}

void Beetle::Destroy()
{
	Notificator::notificate("One of the beelte was killed!");
	static int deathTimer = 0;
	if (deathTimer >= par->beetlePar.deathTimer) {
		auto it = std::find(allObjects->begin(), allObjects->end(), this);
		if (it != allObjects->end())
			allObjects->erase(it);
		delete this;
	}
	else
	{
		deathTimer++;
	}
}


void Beetle::Update()
{
	ForestObject::Draw();
	checkAnts();
	(this->*action)();
	Organism::Update();
}


Beetle::~Beetle()
{
}

void Beetle::checkAnts()
{
	for (ForestObject* obj : *allObjects) {
		if (obj->compareTag("Ant"))
		{
			if (glm::length(obj->getPosition() - position) < par->beetlePar.attackDistance)
			{
				target = dynamic_cast<Organism*>(obj);
				action = &Beetle::fight;
				return;
				/*
				return;*/
			}
		}
	}
}


vec3 Beetle::followTowards(vec3 target)
{
	vec3 steering = target - position;
	steering = glm::normalize(steering) * par->beetlePar.maxVelosity - velosity;
	if (glm::length(steering) > par->beetlePar.maxForce)
	{
		steering = glm::normalize(steering) * par->beetlePar.maxForce;
	}
	return steering;
}

void Beetle::explore()
{
	changeDirTimer++;
	if (changeDirTimer > par->beetlePar.changeDirFreq)
	{
		changeDirTimer = 0;
		vec3 circlePos = position + glm::normalize(velosity) * par->beetlePar.circkeDistance;
		vec3 target = circlePos + glm::rotateY(vec3(par->beetlePar.circleRadius, 0, 0), (rand() % 360) * 1.0f);

		velosity += followTowards(target);
	}
	if (glm::length(velosity) > par->beetlePar.maxVelosity)
	{
		velosity = glm::normalize(velosity) * par->beetlePar.maxVelosity;
	}
	position += velosity;

	//вращение
	if (velosity.z < 0)
	{
		rotation.y = glm::degrees(acos(glm::dot(vec3(1, 0, 0), velosity) / glm::length(velosity)));
	}
	else
	{
		rotation.y = 360 - glm::degrees(acos(glm::dot(vec3(1, 0, 0), velosity) / glm::length(velosity)));
	}
	position.y = 0;
}

void Beetle::fight()
{
	if (glm::length(target->getPosition() - position) > par->beetlePar.attackDistance || target->getHealth() <= 0)
	{
		action = &Beetle::explore;
		return;
	}
	else
	{
		if (health > 0)
		{	
			target->makeDamage(attack);
			if (target->getHealth() <= 0)
				Notificator::notificate("One of the ants was killed by beetle!");
		}
	}
	if (health <= 0)
	{
		health = par->beetlePar.health;
		this->setPosition(vec3(rand() % par->forestPar.landscapeWidth - par->forestPar.landscapeWidth / 2,
			0, rand() % par->forestPar.landscapeHeight - par->forestPar.landscapeHeight / 2));
		tag = "Beetle";
		Notificator::notificate("One of the beelte was killed!");
		action = &Beetle::explore;
	}
}