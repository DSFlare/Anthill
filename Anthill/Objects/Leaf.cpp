#include "Leaf.h"



Leaf::Leaf(sf::RenderWindow* window_, Camera* camera_, Resources * res_, vec3 position_, vec3 rotation_, vec3 scale_)
	: ForestObject(window_, camera_, res_)
{
	shader = &(res->standartShader);
	texture = &(res->leafTex);
	model = new Model3D(res->leafModel, texture);
}

void Leaf::Update()
{
	ForestObject::Draw();
}


Leaf::~Leaf()
{
}
