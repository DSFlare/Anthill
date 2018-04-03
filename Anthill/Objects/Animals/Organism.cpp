#include "Organism.h"





Organism::~Organism()
{
}

Organism::Organism(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
	sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	: ForestObject(window_, camera_, res_, par_, allObjects_, position_,  rotation_, scale_)
{

}

void Organism::Update()
{
	if (health <= 0)
	{
		Destroy();
	}
	if (position.x >= 25)
	{
		position.x = 24.7;
		velosity = vec3(-1, 0, 0);
	}
	if (position.x <= -25)
	{
		position.x = -24.7;
		velosity = vec3(1, 0, 0);
	}
	if (position.z >= 25)
	{
		position.z = 24.7;
		velosity = vec3(0, 0, -1);
	}
	if (position.z <= -25)
	{
		position.z = -24.7;
		velosity = vec3(0, 0, 1);
	}
}

int Organism::getHealth()
{
	return health;
}

void Organism::setHealth(int health_)
{
	health = health_;
}

int Organism::getAttack()
{
	return attack;
}

void Organism::setAttack(int attack_)
{
	attack = attack_;
}

void Organism::makeDamage(int damage)
{
	health -= damage;
}
