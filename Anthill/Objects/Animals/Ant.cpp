#include "Ant.h"

void Ant::Death()
{
}

void Ant::Update()
{
	Organism::Update();
	ForestObject::Draw();
}

Ant::Ant(Camera * camera_, Resources * res_, sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, window_, position_,  rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->antTex);
	model = new Model3D(res->antModel, texture);
}

Ant::~Ant()
{
}

