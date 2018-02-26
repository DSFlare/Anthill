#pragma once
#include <vector>
#include "UIObject.h"
#include "UIImage.h"

class Canvas
{
public:

	std::vector<UIObject*> objects;

	Canvas();
	~Canvas();


	void Update();
	void HandleEvent(sf::Event e);
};

