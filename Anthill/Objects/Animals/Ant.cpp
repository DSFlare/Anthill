#include "Ant.h"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "Queen.h"

void Ant::Destroy()
{
	auto it = std::find(allObjects->begin(), allObjects->end(), this);
	if (it != allObjects->end())
		allObjects->erase(it);
	delete this;
}

void Ant::Update()
{
	Organism::Update();
	ForestObject::Draw();
	(this->*action)();
}

Ant::Ant(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_,
	sf::RenderWindow * window_, Queen* queen_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, par_, allObjects_, window_, position_, rotation_, scale_)
{
	queen = queen_;
	shader = &(res->standartShader);
	texture = &(res->antTex);
	model = new Model3D(res->antModel, texture);
	tag = "Ant";
	health = par->AntPar.antHealth;
	attack = par->AntPar.attack;

	anthillPosition = vec3(0, 0, 0);
}

Ant::~Ant()
{
}

//======================== Общие методы =======================

//возвращает true, если пошел сообщать в муравейник о врагах
bool Ant::checkEnemies(bool needToReport)
{
	for (ForestObject* obj : *allObjects) {
		if (obj->CompareTag("Caterpillar") || obj->CompareTag("Beetle"))
		{
			if (glm::length(obj->getPosition() - position) < par->AntPar.viewDistance)
			{
				Organism* enemy = dynamic_cast<Organism*>(obj);
				if (enemy != NULL) {
					enemies.push_back(enemy);
				}
				obj->SetTag(obj->GetTag() + " discovered");
				//если установлен параметр, то идем в муравейник сообщать
				if (needToReport)
				{
					Eadle();
					return true;
				}
			}
		}
	}
	return false;
}


bool Ant::checkRes(bool needToPickUp)
{
	for (ForestObject* obj : *allObjects) {
		if (obj->CompareTag("Leaf") || obj->CompareTag("Stick"))
		{
			ForestObject* temp = obj->GetParent();
			if (glm::length(obj->getPosition() - position) < par->AntPar.viewDistance && obj->GetParent() == NULL)
			{
				//если муравей свободен, то подходим к ресурсу и уносим с собой в муравейник
				if (isFree && needToPickUp)
				{
					velosity += followTowards(obj->getPosition());
					if (glm::length(velosity) > par->AntPar.maxVelosity)
					{
						velosity = glm::normalize(velosity) * par->AntPar.maxVelosity;
					}
					position += velosity;
					calculateDiraction();

					if (glm::length(obj->getPosition() - position) < 0.1f)
					{
						pickUp(obj);
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
	return false;
}

//Возвращает steering, которое можно сразу добавлять к velosity
vec3 Ant::followTowards(vec3 target, bool isApproach)
{

	vec3 steering = target - position;
	if (!isApproach)
	{
		steering = glm::normalize(steering) * par->AntPar.maxVelosity - velosity;
	}
	else
	{
		float dist = glm::length(steering);
		steering = glm::normalize(steering);

		if (dist < par->AntPar.approachRadius)
			steering += dist / par->AntPar.approachRadius * par->AntPar.maxVelosity;
		else
			steering *= par->AntPar.maxVelosity;
		steering -= velosity;
	}

	if (glm::length(steering) > par->AntPar.maxForce)
	{
		steering = glm::normalize(steering) * par->AntPar.maxForce;
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
	position.y = 0;
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
		enterToAnthill();
		//Scout();
	}
	else
	{
		checkEnemies(false);
		checkRes(false);
		velosity += followTowards(anthillPosition);

		if (glm::length(velosity) > par->AntPar.maxVelosity)
		{
			velosity = glm::normalize(velosity) * par->AntPar.maxVelosity;
		}
		position += velosity;
		calculateDiraction();
	}
}

void Ant::enterToAnthill()
{
	queen->SendItems(items);
	queen->SendEnemies(enemies);
	target = NULL;

	for (ForestObject* obj : childs) {
		obj->SetParent(NULL);
		obj->setDrawn(false);

		auto it = std::find(allObjects->begin(), allObjects->end(), obj);
		if (it != allObjects->end())
			allObjects->erase(it);

		obj->SetTag("broughtItem");
	}
	childs.clear();
	items.clear();
	enemies.clear();
	isFree = true;
	Destroy();
}

//========================  методы SCOUT  ====================================

void Ant::Scout()	//стартовый
{
	velosity = vec3(par->AntPar.maxVelosity, 0, 0);
	glm::rotateY(velosity, (rand() % 360) * 1.0f);
	action = &Ant::explore;
}

void Ant::explore()
{
	//смотрим, есть ли поблизости ресурсы и враги
	if (!checkEnemies(true) && !checkRes(true))
	{
		changeDirTimer++;
		if (changeDirTimer > par->AntPar.changeDirFreq)
		{
			changeDirTimer = 0;
			vec3 circlePos = position + glm::normalize(velosity) * par->AntPar.circkeDistance;
			vec3 target = circlePos + glm::rotateY(vec3(par->AntPar.circleRadius, 0, 0), (rand() % 360) * 1.0f);

			velosity += followTowards(target, false);
		}
		if (glm::length(velosity) > par->AntPar.maxVelosity)
		{
			velosity = glm::normalize(velosity) * par->AntPar.maxVelosity;
		}
		position += velosity;
		calculateDiraction();
	}
}

void Ant::followItem()
{
	checkRes(false);
	checkEnemies(false);
	if (glm::length(target->getPosition() - position) < par->AntPar.attackDistance)
	{
		pickUp(target);
		action = &Ant::goHome;
	}
	else
	{
		velosity += followTowards(target->getPosition());
		position += velosity;
		calculateDiraction();
	}
}

void Ant::pickUp(ForestObject * item)
{
	childs.push_back(item);
	item->SetParent(this);
	isFree = false;
	Eadle();
}

void Ant::Scout(ForestObject * target_)
{
	target = target_;
	action = &Ant::followItem;
}

//========================= методы Hunter ================================

void Ant::Hunter(ForestObject * target_)
{
	target = target_;
	action = &Ant::followEnemy;
}

void Ant::followEnemy()
{
	checkRes(false);
	checkEnemies(false);
	if (glm::length(target->getPosition() - position) < 0.12)
	{
		action = &Ant::Fight;
	}
	else
	{
		velosity += followTowards(target->getPosition());
		position += velosity;
		calculateDiraction();
	}
}

void Ant::Fight()
{
	Organism* target_ = dynamic_cast<Organism*>(target);
	if (target_->getHealth() > 0)
	{
		target_->makeDamage(attack);
	}
	else
	{
		auto it = std::find(enemies.begin(), enemies.end(), target_);
		if (it != enemies.end())
			enemies.erase(it);
		action = &Ant::goHome;
	}
	if (glm::length(target_->getPosition() - position) > par->AntPar.attackDistance)
	{
		action = &Ant::followEnemy;
		return;
	}
}