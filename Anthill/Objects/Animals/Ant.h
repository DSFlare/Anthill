#pragma once
#include "Organism.h"
class Ant :
	public Organism
{
	int currentTask;
public:
	virtual void Death() = 0;
	Ant();
	virtual ~Ant();
};

