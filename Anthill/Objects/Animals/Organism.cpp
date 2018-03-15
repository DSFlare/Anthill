#include "Organism.h"





Organism::~Organism()
{
}

Organism::Organism(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
	sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	: ForestObject(window_, camera_, res_, par_, allObjects_, position_,  rotation_, scale_)
{

}

void Organism::Update()
{
}
