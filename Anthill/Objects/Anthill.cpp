#include "Anthill.h"


Anthill::Anthill(sf::RenderWindow * window_, Camera * camera_, Resources * res_)
	:ForestObject(window_, camera_, res_)
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
	ForestObject::Draw();
}
