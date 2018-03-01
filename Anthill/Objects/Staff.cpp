#include "Staff.h"



Staff::Staff(sf::RenderWindow* window_, Camera* camera_, Resources * res_)
	: Drawable3D(window_, camera_, res_, &position, &rotation, &scale)
{
	
}

Staff::~Staff()
{
}
