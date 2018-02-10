#pragma once
#include "Organism.h"
class Caterpillar :
	public Organism
{
public:
	Caterpillar();
	virtual void Death() override;
	~Caterpillar();
};

