#include "Beetle.h"



Beetle::Beetle(Camera * camera_, Resources * res_, sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, window_, position_, rotation_, scale_)
{
}

void Beetle::Death()
{
}


Beetle::~Beetle()
{
}
