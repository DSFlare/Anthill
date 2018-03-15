#include "Beetle.h"



Beetle::Beetle(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
	sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, par_, allObjects_, window_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->queenTex);
	model = new Model3D(res->beetleModel, texture);
	tag = "Beetle";
}

void Beetle::Death()
{
}


void Beetle::Update()
{
	ForestObject::Draw();
}


Beetle::~Beetle()
{
}
