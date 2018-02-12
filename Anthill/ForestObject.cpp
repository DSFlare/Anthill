#include "ForestObject.h"



ForestObject::ForestObject(vec3 position_, vec3 rotation_, vec3 scale_)
{
	position = position_;
	rotation = rotation_;
	scale = scale_;
}

ForestObject::~ForestObject()
{
}

void ForestObject::HandleEvent(sf::Event e)
{
}
