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
	int needAntHoursForUpgrade = 200;
	int priority; //приоритет дл€ улучшени€ - от 1 до 4 включительно
public:
	//возвращает сколько использовал материалов
	void upgrade(float resources);
	float getCapacity() { return capacity;  }
	float getResForUpgrade() { return needResForUpgrade; }
	float getFullness() { return fullness; }
	int getPriority() { return priority; }
	RoomType getRoomType() { return type; }
	int getNeededWorkers() { return needAntHoursForUpgrade; }
	float getNeededRes() { return needResForUpgrade; }
	int getLevel() { return level; }

	bool isFull();

	void setPriority(int priority_);
	void setFullness(float number) { fullness = number; }
	void setCapacity(float capacity_) { capacity = capacity_; }

	void addItem(float number);
	float popItem(float number);
	Room(RoomType type_);
	~Room();
};

