#include "EnvironmentalObject.h"


EnvironmentalObject::EnvironmentalObject(sf::RenderWindow * window_, Camera * camera_, Resources * res_, 
	Parametres* par_, std::vector<ForestObject*>* allObjects_, Kind kind,
	vec3 position_, vec3 rotation_, vec3 scale_)
	: ForestObject(window_, camera_, res_, par_, allObjects_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	if (kind == FENCE)
	{
		texture = &(res->fenceTex);
		model = new Model3D(res->fenceModel, texture);
	}
	tag = "EnvironmentalObject";
}

void EnvironmentalObject::Update()
{
	ForestObject::Draw();
}


EnvironmentalObject::~EnvironmentalObject()
{
}

