#include "Organism.h"




Organism::~Organism()
{
}

Organism::Organism(Camera * camera_, Resources * res_, sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	: ForestObject(position_, rotation_, scale_), Drawable3D(window_, camera_, res_, &position, &rotation, &scale)
{

}

void Organism::Update()
{
}
