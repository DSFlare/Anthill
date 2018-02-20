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
