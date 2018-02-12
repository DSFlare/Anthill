#pragma once
#include "Ant.h"
class Hunter :
	public Ant
{
public:
	enum tasks {};
	virtual void Death() override;
	Hunter();
	~Hunter();
};

