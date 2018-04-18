#include "Ant.h"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "Queen.h"
#include "../../UI/Notificator.h"
#include "../../Timer.h"

void Ant::Destroy()
{
	auto it = std::find(allObjects->begin(), allObjects->end(), this);
	if (it != allObjects->end())
		allObjects->erase(it);
	if (role == HUNTER || role == SCOUT)
	{
		for (auto it = childs.begin(); it != childs.end(); ++it)
		{
			(*it)->setParent(NULL);
			(*it)->setDrawn(true);
		}
	}
	queen->deletingAnt(this);
	delete this;
}

void Ant::Update()
{
	ForestObject::Draw();
	hungry();
	(this->*action)();
	Organism::Update();
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
	satiety = par->AntPar.maxSatiety;

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
		if (obj->compareTag("Caterpillar") || obj->compareTag("Beetle"))
		{
			if (glm::length(obj->getPosition() - position) < par->AntPar.viewDistance)
			{
				Organism* enemy = dynamic_cast<Organism*>(obj);
				if (enemy != NULL) {
					enemies.push_back(enemy);
				}
				obj->setTag(obj->getTag() + " discovered");
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


void Ant::hungry()
{
	static int lastTime = Timer::getTimeAsSec();
	if (Timer::getTimeAsSec() > lastTime)
	{
		lastTime = Timer::getTimeAsSec();
		if (role == WORKER)
		{
			satiety -= par->AntPar.satietyLoosesInAnthill;
			satiety += queen->askFood(par->AntPar.maxSatiety - satiety);
			health = par->AntPar.antHealth;
		}
		else
		{
			satiety -= par->AntPar.satietyLooses;
		}
		if (satiety <= 0)
		{
			Notificator::notificate("One of the ants died of hunger");
			this->Destroy();
		}
	}
}

bool Ant::checkRes(bool needToPickUp)
{
	for (ForestObject* obj : *allObjects) {
		if (obj->compareTag("Leaf") || obj->compareTag("Stick"))
		{
			ForestObject* temp = obj->getParent();
			if (glm::length(obj->getPosition() - position) < par->AntPar.viewDistance && obj->getParent() == NULL)
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
					obj->setTag(obj->getTag() + " discovered");
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
	role = EADLE;
	action = &Ant::goHome;
}

void Ant::Worker()
{
	action = &Ant::Worker;
	role = WORKER;
}

void Ant::Warrior()
{
}



void Ant::goHome()
{
	if (glm::length(anthillPosition - position) < 0.1)
	{
		enterToAnthill();
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
	queen->sendItems(items);
	queen->sendEnemies(enemies);
	queen->sendBroughtItems(childs);
	target = NULL;

	for (ForestObject* obj : childs) {
		obj->setParent(NULL);
		//obj->setDrawn(false);

		if (obj->compareTag("Leaf") || obj->compareTag("Leaf discovered"))
		{
			obj->setTag("Leaf");
			obj->setPosition(vec3(rand() % par->forestPar.landscapeWidth - par->forestPar.landscapeWidth / 2,
				0, rand() % par->forestPar.landscapeHeight - par->forestPar.landscapeHeight / 2));
		}

		if (obj->compareTag("Stick") || obj->compareTag("Stick discovered"))
		{
			obj->setTag("Stick");
			obj->setPosition(vec3(rand() % par->forestPar.landscapeWidth - par->forestPar.landscapeWidth / 2,
				0, rand() % par->forestPar.landscapeHeight - par->forestPar.landscapeHeight / 2));
		}

	}
	satiety += queen->askFood(par->AntPar.maxSatiety - satiety);
	health = par->AntPar.antHealth;
	childs.clear();
	items.clear();
	enemies.clear();
	isFree = true;
	queen->antAtHome(this);
	Worker();
	isDrawn = false;
	//Destroy();
}

//========================  методы SCOUT  ====================================

void Ant::Scout()	//стартовый
{
	role = SCOUT;
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
	item->setParent(this);
	isFree = false;
	action = &Ant::goHome;
}

void Ant::Scout(ForestObject * target_)
{
	role = SCOUT;
	target = target_;
	action = &Ant::followItem;
}

//========================= методы Hunter ================================

void Ant::Hunter(ForestObject * target_)
{
	role = HUNTER;
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
		if (glm::length(target_->getPosition() - position) > par->AntPar.attackDistance)
		{
			action = &Ant::followEnemy;
			return;
		}

		target_->makeDamage(attack);
		if (target_->getHealth() <= 0)
		{
			auto it = std::find(enemies.begin(), enemies.end(), target_);
			if (it != enemies.end())
				enemies.erase(it);
			queen->enemyKilled(target);
			target = NULL;
			action = &Ant::goHome;
		}
	}
	else
	{
		auto it = std::find(enemies.begin(), enemies.end(), target_);
		if (it != enemies.end())
			enemies.erase(it);
		queen->enemyKilled(target);
		target = NULL;
		action = &Ant::goHome;
	}
}