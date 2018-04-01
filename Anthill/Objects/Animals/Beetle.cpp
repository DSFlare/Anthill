#include "Beetle.h"



Beetle::Beetle(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
	sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, par_, allObjects_, window_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->queenTex);
	model = new Model3D(res->beetleModel, texture);
	tag = "Beetle";
	health = par->enemyPar.beetleHealth;
	attack = par->enemyPar.beetleAttack;
}

void Beetle::Destroy()
{
	static int deathTimer = 0;
	if (deathTimer >= par->enemyPar.deathTimer) {
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
	Organism::Update();
}


Beetle::~Beetle()
{
}

void Beetle::checkAnts()
{
	for (ForestObject* obj : *allObjects) {
		if (obj->CompareTag("Ant"))
		{
			if (glm::length(obj->getPosition() - position) < par->enemyPar.beetleAttackDistance)
			{
				Organism* ant = dynamic_cast<Organism*>(obj);
				ant->makeDamage(attack);
				return;
			}
		}
	}
}
