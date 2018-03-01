#include "Anthill.h"


Anthill::Anthill(sf::RenderWindow * window_, Camera * camera_, Resources * res_)
	:Drawable3D(window_, camera_, res_, &position, &rotation, &scale)
{

}

Anthill::~Anthill()
{
}
