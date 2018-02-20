#pragma once
#include "Role.h"
class Hunter :
	public Role
{
private:
	Role* role;
public:
	Role* getRole();
	Hunter();
	~Hunter();
};