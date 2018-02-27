#include "Canvas.h"

Canvas::Canvas()
{

}

Canvas::~Canvas()
{

}

void Canvas::Update()
{
	for (auto obj : objects)
	{
		obj->Update();
	}
}

void Canvas::HandleEvent(sf::Event e)
{
	for (auto obj : objects)
	{
		obj->HandleEvent(e);
	}
}