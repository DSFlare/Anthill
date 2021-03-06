#include "Stick.h"



Stick::Stick(sf::RenderWindow* window_, Camera* camera_, Resources * res_, Parametres* par_, 
	std::vector<ForestObject*>* allObjects_, vec3 position_, vec3 rotation_, vec3 scale_)
	: ForestObject(window_, camera_, res_, par_, allObjects_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->stickTex);
	model = new Model3D(res->stickModel, texture);
	tag = "Stick";
	materialAmount = 1 + (rand() % 11) * 0.1;
}


void Stick::Update()
{
	ForestObject::Draw();
	ForestObject::Update();
}


Stick::~Stick()
{
}

float Stick::getMaterial()
{
	return materialAmount;
}
