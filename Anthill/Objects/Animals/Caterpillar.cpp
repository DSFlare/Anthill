#include "Caterpillar.h"



Caterpillar::Caterpillar(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
	sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, par_, allObjects_, window_, position_, rotation_, scale_)
{
	tag = "Caterpillar";
}

void Caterpillar::Destroy()
{
}


Caterpillar::~Caterpillar()
{
}

void Caterpillar::checkEdges()
{
	if (position.x >= 50)
	{
		velosity.x = -par->AntPar.maxVelosity;
	}
	if (position.x <= -50)
	{
		velosity.x = par->AntPar.maxVelosity;
	}
	if (position.z >= 50)
	{
		velosity.z = -par->AntPar.maxVelosity;
	}
	if (position.z <= -50)
	{
		velosity.z = par->AntPar.maxVelosity;
	}
}
