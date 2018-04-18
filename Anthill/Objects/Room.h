#pragma once
#include <cmath>

enum RoomType {
	MAIN_ROOM, FOOD_STORAGE, CHILD_ROOM, STOCK
};
class Room
{
private:
	RoomType type;
	float capacity;
	float fullness;
	int level = 1;
	float needResForUpgrade = 1;
public:
	//возвращает сколько использовал материалов
	void upgrade(float resources);
	float getCapacity() { return capacity;  }
	float getResForUpgrade() { return needResForUpgrade; }
	float getFullness() { return fullness; }
	RoomType getRoomType() { return type; }
	float getNeededRes() { return needResForUpgrade; }
	int getLevel() { return level; }

	bool isFull();

	void setFullness(float number) { fullness = number; }
	void setCapacity(float capacity_) { capacity = capacity_; }

	void addItem(float number);
	float popItem(float number);
	Room(RoomType type_);
	~Room();
};

