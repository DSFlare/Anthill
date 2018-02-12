#pragma once
#include "Organism.h"
class Beetle :
	public Organism
{
public:
	Beetle();
	virtual void Death() override;
	~Beetle();
};

