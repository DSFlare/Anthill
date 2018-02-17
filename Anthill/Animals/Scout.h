#pragma once
#include "Role.h"
class Scout 
	: public Role
{
private:
	Role* role;
public:
	Role* getRole();
	Scout();
	~Scout();
};

