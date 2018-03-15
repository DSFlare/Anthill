#include "Ant.h"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"


void Ant::Death()
{
}

void Ant::Update()
{
	//Organism::Update();
	(this->*action)();
	ForestObject::Draw();
}

Ant::Ant(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
	sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, par_, allObjects_, window_, position_,  rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->antTex);
	model = new Model3D(res->antModel, texture);
	tag = "Ant";

	anthillPosition = vec3(0, 0, 0);
	Scout();
}

Ant::~Ant()
{
}

//движение

vec3 Ant::followTowards(vec3 target, bool isApproach)
{
	vec3 steering = target - position;
	if (!isApproach)
	{
		steering = glm::normalize(steering) * maxVelosity - velosity;
	}
	else
	{
		float dist = glm::length(steering);
		steering = glm::normalize(steering);

		if (dist < approachRadius)
			steering += dist / approachRadius * maxVelosity;
		else
			steering *= maxVelosity;
		steering -= velosity;
	}

	if (glm::length(steering) > maxForce)
	{
		steering = glm::normalize(steering) * maxForce;
	}
	return steering;
}

void Ant::calculateDiraction()
{
	if (velosity.z < 0)
	{
		rotation.y = glm::degrees(acos(glm::dot(vec3(1, 0, 0), velosity) / glm::length(velosity)));
	}
	else
	{
		rotation.y = 360 - glm::degrees(acos(glm::dot(vec3(1, 0, 0), velosity) / glm::length(velosity)));
	}
}

//============================== методы EADLE ================================
void Ant::Eadle()
{
	action = &Ant::goHome;
}

void Ant::Warrior()
{
}

void Ant::goHome()
{
	if (glm::length(anthillPosition - position) < 0.1)
	{
		for (ForestObject* obj : childs) {
			obj->SetParent(NULL);
			obj->setDrawn(false);

			auto it = std::find(allObjects->begin(), allObjects->end(), obj);
			//if (it != allObjects->end())
				//allObjects->erase(it);

			obj->SetTag("broughtItem");

		}
  		childs.clear();
		items.clear();
		isFree = true;
		Scout();
	}
	else
	{
		velosity += followTowards(anthillPosition);

		if (glm::length(velosity) > maxVelosity)
		{	
			velosity = glm::normalize(velosity) * maxVelosity;
		}
		position += velosity;
		calculateDiraction();
	}
 	int a = 0;
}

//========================  методы SCOUT  ====================================

void Ant::Scout()	//стартовый
{
	velosity = vec3(maxVelosity, 0, 0);
	glm::rotateY(velosity, (rand() % 360) * 1.0f);
	action = &Ant::explore;
}

void Ant::Scout(ForestObject * target)
{
}

void Ant::Hunter(ForestObject * target)
{
}

bool Ant::checkRes()
{
	bool ret = false;
	for (ForestObject* obj : *allObjects) {
		if (obj->CompareTag("Leaf") || obj->CompareTag("Stick"))
		{
			ForestObject* temp = obj->GetParent();
			if (glm::length(obj->getPosition() - position) < viewDistance && obj->GetParent() == NULL)
			{
				
				//если муравей свободен, то подходим к ресурсу и уносим с собой в муравейник
				if (isFree)
				{
					velosity += followTowards(obj->getPosition());
					if (glm::length(velosity) > maxVelosity)
					{
						velosity = glm::normalize(velosity) * maxVelosity;
					}
					position += velosity;
					calculateDiraction();

					if (glm::length(obj->getPosition() - position) < 0.1f)
					{
						childs.push_back(obj);
						obj->SetParent(this);
						isFree = false;
						Eadle();
					}
					return true;
				}
				else
				{
					items.push_back(obj);
				}
				
			}
		}
	}
	return ret;
}

void Ant::explore()
{
	//смотрим, есть ли поблизости ресурсы
	if (!checkRes())
	{
		changeDirTimer++;
		if (changeDirTimer > changeDirFreq)
		{
			changeDirTimer = 0;
			vec3 circlePos = position + glm::normalize(velosity) * circkeDistance;
			vec3 target = circlePos + glm::rotateY(vec3(circleRadius, 0, 0), (rand() % 360) * 1.0f);

			velosity += followTowards(target, false);
		}
		if (glm::length(velosity) > maxVelosity)
		{
			velosity = glm::normalize(velosity) * maxVelosity;
		}
		position += velosity;
		calculateDiraction();
	}
}
