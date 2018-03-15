#include "Caterpillar.h"



Caterpillar::Caterpillar(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
	sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, par_, allObjects_, window_, position_, rotation_, scale_)
{
}

void Caterpillar::Death()
{
}


Caterpillar::~Caterpillar()
{
}
