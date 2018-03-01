#include "Anthill.h"


Anthill::Anthill(sf::RenderWindow * window_, Camera * camera_, Resources * res_)
	:Drawable3D(window_, camera_, res_, &position, &rotation, &scale)
{
	shader = &(res->standartShader);
	texture = &(res->anthillTex);
	model = new Model3D(res->anthillModel, texture);
}

Anthill::~Anthill()
{
}

void Anthill::Update()
{
	Drawable3D::Draw();
}
