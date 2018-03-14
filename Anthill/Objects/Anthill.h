#pragma once
#include "ForestObject.h"

class Anthill: public ForestObject
{
	int antsNumber;
	int eggsNumber;
	int foodAmount;
	int stockFullness;

	int mainRoomSize;
	int childRoomSize;
	int foodStorageSize;
	int stockSize;

public:

	
	
	


	Anthill(sf::RenderWindow* window_, Camera* camera_, Resources* res_);
	~Anthill();

	virtual void Update() override;
};

