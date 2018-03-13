#include "Stick.h"



Stick::Stick(sf::RenderWindow* window_, Camera* camera_, Resources * res_, vec3 position_, vec3 rotation_, vec3 scale_)
	: ForestObject(window_, camera_, res_)
{
	shader = &(res->standartShader);
	texture = &(res->stickTex);
	model = new Model3D(res->stickModel, texture);
}

void Stick::Update()
{
	ForestObject::Draw();
}


Stick::~Stick()
{
}
