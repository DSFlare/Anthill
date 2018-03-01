#pragma once
#include <vector>
#include "UIObject.h"
#include "UIImage.h"
#include "UIAnthill.h"
#include "UIHotkeysInfo.h"

class Canvas
{
public:

	std::vector<UIObject*> objects;

	Canvas();
	~Canvas();


	void Update();
	void HandleEvent(sf::Event e);
};

