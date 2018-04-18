#include "Queen.h"
#include "../../Timer.h"
#include "../../UI/Notificator.h"

void Queen::sendBroughtItems(vector<ForestObject*> items)
{
	for (ForestObject* obj : items) {
		if (obj->compareTag("Leaf") || (obj->compareTag("Leaf discovered")))
		{
			Leaf* leaf = dynamic_cast<Leaf*>(obj);
			anthill->addFood(leaf->getFood());
		}
		else if (obj->compareTag("Stick") || (obj->compareTag("Stick discovered")))
		{
			Stick* stick = dynamic_cast<Stick*>(obj);
			anthill->addResources(stick->getMaterial());
		}
	}
}

void Queen::sendItems(vector<ForestObject*> items_)
{
	items.insert(items.end(), items_.begin(), items_.end());
}

//ант передает сюда ветки и листья, которые обнаружил, но не собрал

void Queen::antAtHome(Ant * ant) 
{ 
	if (ant->getRole() == HUNTER)
	{
		auto it = std::find(hunters.begin(), hunters.end(), ant);
		if (it != hunters.end())
			hunters.erase(it);
	}

	else if (ant->getRole() == SCOUT)
	{
		auto it = std::find(scouts.begin(), scouts.end(), ant);
		if (it != scouts.end())
			scouts.erase(it);
	}
	else if (ant->getRole() == WARRIOR)
	{
		auto it = std::find(warriors.begin(), warriors.end(), ant);
		if (it != warriors.end())
			warriors.erase(it);
	}
	anthill->addWorker(); 
	workers.push_back(ant);
}

void Queen::sendEnemies(vector<Organism*> enemies_)
{
	enemies.insert(enemies.end(), enemies_.begin(), enemies_.end());
}

float Queen::askFood(float quantity)
{
	return anthill->foodStorage.popItem(quantity);
}

void Queen::enemyKilled(ForestObject * enemy)
{
	auto pos = std::find(enemies.begin(), enemies.end(), enemy);
	if (pos != enemies.end())
	{
		enemies.erase(pos);
	}
}

void Queen::deletingAnt(Ant * ant)
{
	anthill->decAntsInColony();
	if (ant->getRole() == HUNTER)
	{
		auto it = std::find(hunters.begin(), hunters.end(), ant);
		if (it != hunters.end())
			hunters.erase(it);
	}

	else if (ant->getRole() == SCOUT)
	{
		auto it = std::find(scouts.begin(), scouts.end(), ant);
		if (it != scouts.end())
			scouts.erase(it);
	}
	else if (ant->getRole() == WARRIOR)
	{
		auto it = std::find(warriors.begin(), warriors.end(), ant);
		if (it != warriors.end())
			warriors.erase(it);
	}
	else if (ant->getRole() == WORKER)
	{
		anthill->popAnt();
		auto it = std::find(workers.begin(), workers.end(), ant);
		if (it != workers.end())
			workers.erase(it);
	}
}

Queen::Queen(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* objects_, sf::RenderWindow * window_,
	vec3 position_, vec3 rotation_, vec3 scale_)
	: Organism(camera_, res_, par_, objects_, window_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->queenTex);
	model = new Model3D(res->queenModel, texture);
	objects = objects_;
	action = &Queen::beginning;

	//заполняем вектор приоритета апгрейдов
	upgradePriority.push_back(FOOD_STORAGE);
	upgradePriority.push_back(STOCK);
	upgradePriority.push_back(MAIN_ROOM);
	upgradePriority.push_back(CHILD_ROOM);

	tag = "Queen";
}

void Queen::Destroy()
{

}

void Queen::Update()
{
	(this->*action)();
	upgradeRooms();
	ForestObject::Draw();
}




Queen::~Queen()
{
}

Queen * Queen::initialize(vec3 position_, Camera * camera, Resources * res, Parametres* par, sf::RenderWindow * window, vector<ForestObject*>* objects)
{
	//6 муравьев и матка в лесу
	Queen* queen = new Queen(camera, res, par, objects, window);
	objects->push_back(queen);
	queen->setPosition(position_);
	for (int i = 0; i < par->simPar.startingAntsCount; i++) {
		queen->instantiateAnt(Role::SCOUT);
	}

	return queen;
}

Anthill * Queen::createAnthill()
{
	//устанавливаем сам муравейник
	anthill = new Anthill(window, camera, res, par, objects);

	anthill->setScale(vec3(0.5f, 0.5f, 0.5f));
	anthill->setPosition(position);
	objects->push_back(anthill);
	neededWorkers = 2;

	return anthill;
}


void Queen::beginning()
{
	
	//============setting up upgrade priority==================
	/*if (1)
	{
		upgradePriority[0] = CHILD_ROOM;
		upgradePriority[1] = FOOD_STORAGE;
		upgradePriority[2] = STOCK;
		upgradePriority[3] = MAIN_ROOM;
	}*/
	
	//========================reproduction=====================
	if (anthill->foodStorage.getFullness() - par->simPar.foodForNewEgg >= anthill->foodStorage.getCapacity() * 0.5
		&& anthill->mainRoom.getCapacity() - anthill->getAntsInColony() > 0 && !anthill->childRoom.isFull())
	{
		layTheEgg();
	}
	if (anthill->childRoom.getFullness() != 0)
	{
		growthEggs();
	}
	//======================calculating workers number========================
	if (anthill->stock.getFullness() == 0)
	{
		neededWorkers = 0;
	}
	else
	{
		if (anthill->stock.getFullness() > 0 && anthill->stock.getFullness() <= 1)
		{
			neededWorkers = 1;
		}
		else
		{
			neededWorkers = anthill->stock.getFullness();
		}
		if (neededWorkers > anthill->getAntsInColony() * 0.35)
		{
			neededWorkers = anthill->getAntsInColony() * 0.35;
		}
	}
	
	//======================sending ants===========================
	for (int i = 0; i < anthill->getWorkersNumber() - neededWorkers; i++)
	{
		bool isSend = false;
		Ant* ant = workers.front();
		workers.erase(workers.begin());
		anthill->popAnt();
		ant->setDrawn(true);
		for (auto it = enemies.begin(); it != enemies.end();)
		{
			Organism* enemy = dynamic_cast<Organism*>(*it);
			if (enemy->getHealth() <= 0)
			{
				it = enemies.erase(it);
				continue;
			}
			else if (glm::length((*it)->getPosition() - position) < par->simPar.saveDistance &&
				anthill->getAntsInColony() > anthill->mainRoom.getCapacity() * 0.7)
			{
				ant->Hunter(*it);
				hunters.push_back(ant);
				isSend = true;
			}
			++it;
		}
		if (items.empty() && !isSend)
		{
			ant->Scout();
			scouts.push_back(ant);
		}
		else if (!isSend)
		{
			ant->Scout(items.front());
			scouts.push_back(ant);
			items.erase(items.begin());
		}
	}
}

void Queen::upgradeRooms()
{
	float res = anthill->getStockFullness();
	if (res <= 0)
	{
		return;
	}
	bool isUpgrade = false;
	for (int i = 0; i < upgradePriority.size(); i++)
	{
		if (!isUpgrade)
		{
			bool isCont = false;
			for (int j = i + 1; j < upgradePriority.size(); j++)
			{
				if (anthill->getRoom(upgradePriority.at(i)).getLevel() > anthill->getRoom(upgradePriority.at(j)).getLevel() + 2)
				{
					isCont = true;
					break;
				}
			}
			if (isCont)
				continue;

			res -= anthill->upgradeRoom(upgradePriority.at(i), res);
			if (res <= 0)
				res = 0;
			isUpgrade = true;
		}
	}
	anthill->stock.setFullness(res);
}

void Queen::setUpgradePriority()
{

}

void Queen::layTheEgg()
{
	Notificator::notificate("New egg added!");
	anthill->foodStorage.popItem(par->simPar.foodForNewEgg);
	anthill->addEgg();
	eggs.push_back(par->simPar.eggGrowingTime);
}

void Queen::growthEggs()
{
	static int lastTime = Timer::getTimeAsSec();
	if (Timer::getTimeAsSec() > lastTime)
	{
		lastTime = Timer::getTimeAsSec();
		for (auto it = eggs.begin(); it != eggs.end(); )
		{
			(*it)--;
			if ((*it) <= 0)
			{
				it = eggs.erase(it);
				anthill->childRoom.popItem(1);
				Queen::instantiateAnt(EADLE);
				anthill->incAntsInColony();
				Notificator::notificate("New ant was born!");
			}
			else
			{
				++it;
			}
		}
	}
	
}

void Queen::instantiateAnt(Role role, ForestObject* target_)
{
	Ant* ant = new Ant(camera, res, par, objects, window, this);
	objects->push_back(ant);
	ant->setPosition(position);

	if (role == Role::SCOUT)
	{
		scouts.push_back(ant);
		if (target_ == nullptr)
			ant->Scout();
		else
			ant->Scout(target_);
	}
	else if (role == Role::WARRIOR)
	{
		ant->Warrior();
		warriors.push_back(ant);
	}
	else if (role == Role::HUNTER)
	{
		ant->Hunter(target_);
		hunters.push_back(ant);
	}
	else if (role == Role::WORKER)
	{
		ant->Worker();
		workers.push_back(ant);
	}
	else if (role == Role::EADLE)
	{
		ant->Eadle();
	}
}

vec3 Queen::getAnthillPosition()
{
	return anthill->getPosition();
}
