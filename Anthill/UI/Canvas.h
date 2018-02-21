#pragma once
#include <vector>
#include "UIObject.h"

class Canvas
{
public:

	std::vector<UIObject*> objects;

	Canvas();
	~Canvas();


	void Update();
};

