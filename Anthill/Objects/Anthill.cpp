#include "Anthill.h"


Anthill::Anthill(sf::RenderWindow * window_, Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_)
	:ForestObject(window_, camera_, res_, par_, allObjects_)
{
	shader = &(res->standartShader);
	texture = &(res->anthillTex);
	model = new Model3D(res->anthillModel, texture);
	tag = "Anthill";
}

Anthill::~Anthill()
{
}


void Anthill::Update()
{
	ForestObject::Draw();
}
