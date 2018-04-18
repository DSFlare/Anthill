#pragma once
#include "ForestObject.h"
#include "Room.h"

class Anthill: public ForestObject
{
private:
	int antsInColony;
public:
	Room mainRoom = { MAIN_ROOM };
	Room childRoom = { CHILD_ROOM };
	Room foodStorage = { FOOD_STORAGE };
	Room stock = { STOCK };

	Anthill(sf::RenderWindow* window_, Camera* camera_, Resources* res_, Parametres* par_, std::vector<ForestObject*>* allObjects_);

	~Anthill();
	//возвращает количество использованных ресурсов
	float upgradeRoom(RoomType type, float resources);

	int getMainRoomSize() { return mainRoom.getCapacity(); }
	int getChildRoomSize() { return childRoom.getCapacity(); }
	float getFoodStorageSize() { return foodStorage.getCapacity(); }
	float getStockSize() { return stock.getCapacity(); }
	Room getRoom(RoomType type);

	float getFoodAmount() { return foodStorage.getFullness(); }
	float getStockFullness() { return stock.getFullness(); }
	int getWorkersNumber() { return mainRoom.getFullness(); }
	int getEggsNumber() { return childRoom.getFullness(); }

	int getAntsInColony() { return antsInColony; }
	void incAntsInColony() { antsInColony++; }
	void decAntsInColony() { antsInColony--; }
	void setAntsInColony(int antsInColony_) { antsInColony = antsInColony_; }
	void setWorkersNumber(int number) { mainRoom.setCapacity(number); }

	void addFood(float foodAmount_) { foodStorage.addItem(foodAmount_); }
	void addResources(float resources) { stock.addItem(resources); }
	void addWorker() { mainRoom.addItem(1); }
	void addEgg() { childRoom.addItem(1); }
	void popAnt() { mainRoom.popItem(1); }

	virtual void Update() override;
};

