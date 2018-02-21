#include "Organism.h"




Organism::~Organism()
{
}

Organism::Organism(Camera * camera_, Resources * res_, sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Drawable3D(window_, camera_, res_), ForestObject(position_, rotation_, scale_)
{

}

void Organism::Update()
{
}
