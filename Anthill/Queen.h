#pragma once
#include "Ant.h"
class Queen :
	public Ant
{
public:
	enum tasks{};
	Queen();
	virtual void Death() override;
	~Queen();
};

