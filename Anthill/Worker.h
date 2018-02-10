#pragma once
#include "Ant.h"
class Worker :
	public Ant
{
public:
	enum tasks {};
	virtual void Death() override;
	Worker();
	~Worker();
};

