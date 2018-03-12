#include "Queen.h"



Queen::Queen(Camera * camera_, Resources * res_, sf::RenderWindow * window_, 
			 vec3 position_, vec3 rotation_, vec3 scale_)
			 : Organism(camera_, res_, window_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->queenTex);
	model = new Model3D(res->queenModel, texture);
}

void Queen::Death()
{

}

void Queen::Update()
{
	ForestObject::Draw();
}




Queen::~Queen()
{
}
