#include "Room.h"
#include "../../UI/Notificator.h"


void Room::upgrade(float resources)
{
	needResForUpgrade -= resources;
	//needAntHoursForUpgrade -= workers;
	if (needResForUpgrade <= 0)
	{
		if (type == FOOD_STORAGE)
			capacity += 3;
		else
			capacity++;
		level++;
		needResForUpgrade += 2;
	}
}

bool Room::isFull()
{
	return fullness == capacity;
}


void Room::addItem(float number)
{
	if (fullness + number < capacity)
	{
		fullness += number;
	}
	else
	{
		fullness = capacity;
	}
}

float Room::popItem(float number)
{
	if (fullness > number)
	{
		fullness -= number;
		return number;
	}
	else
	{
		float ret = fullness;
		fullness = 0;
		return ret;
	}
}

Room::Room(RoomType type_)
{
	type = type_;
	capacity = 1;
	fullness = 0;
}


Room::~Room()
{
}
