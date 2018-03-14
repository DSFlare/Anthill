#include "Leaf.h"



Leaf::Leaf(sf::RenderWindow* window_, Camera* camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
	vec3 position_, vec3 rotation_, vec3 scale_)
	: ForestObject(window_, camera_, res_, par_, allObjects_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->leafTex);
	model = new Model3D(res->leafModel, texture);
	tag = "Leaf";
}

void Leaf::Update()
{
	ForestObject::Update();
	ForestObject::Draw();
}



Leaf::~Leaf()
{
	ForestObject::Destroy();
}
