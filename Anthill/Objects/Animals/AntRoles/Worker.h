#pragma once
//#include "Ant.h"
#include "Role.h"
class Worker :
	public Role
{
public:
	enum tasks {};
	//virtual void Death() override;
	Worker();
	~Worker();
};

