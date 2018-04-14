#include "Anthill.h"


Anthill::Anthill(sf::RenderWindow * window_, Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_)
	:ForestObject(window_, camera_, res_, par_, allObjects_)
{
	shader = &(res->standartShader);
	texture = &(res->anthillTex);
	model = new Model3D(res->anthillModel, texture);
	tag = "Anthill";

	antsInColony = par->simPar.startingAntsCount;
	mainRoom.setCapacity(par->simPar.startingAntsCount);
	foodStorage.setCapacity(10);
	stock.setCapacity(3);
	mainRoom.setCapacity(par->simPar.startingAntsCount);
}

Anthill::~Anthill()
{
}

float Anthill::upgradeRoom(RoomType type, float resources)
{
	int ants = mainRoom.getFullness();
	if (ants == 0)
	{
		return 0;
	}
	else
	{
		float spendRes = ants * par->simPar.resWithOneWorker;
		if (spendRes > resources)
		{
			spendRes == resources;
		}
		else
		{
			switch (type)
			{
			case FOOD_STORAGE:
			{
				//upgradeFoodStorage(workers, resources);
				foodStorage.upgrade(spendRes);
				break;
			}
			case STOCK:
			{
				//upgradeStock(workers, resources);
				stock.upgrade(spendRes);
				break;
			}
			case CHILD_ROOM:
			{
				childRoom.upgrade(spendRes);
				//upgradeChildRoom(workers, resources);
				break;
			}
			case MAIN_ROOM:
			{
				mainRoom.upgrade(spendRes);
				//upgradeMainRoom(workers, resources);
				break;
			}
			}
		}
		return spendRes;
	}
}

Room Anthill::getRoom(RoomType type)
{
	switch (type)
	{
	case FOOD_STORAGE:
	{
		return foodStorage;
		break;
	}
	case STOCK:
	{
		return stock;
		break;
	}
	case CHILD_ROOM:
	{
		return childRoom;
		break;
	}
	case MAIN_ROOM:
	{
		return mainRoom;
		break;
	}
	}
}


void Anthill::Update()
{
	ForestObject::Draw();
}
