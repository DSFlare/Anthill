#include "Queen.h"



Queen::Queen(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* objects_, sf::RenderWindow * window_,
			 vec3 position_, vec3 rotation_, vec3 scale_)
			 : Organism(camera_, res_, par_, allObjects_, window_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->queenTex);
	model = new Model3D(res->queenModel, texture);

	//заполняем вектор приоритета апгрейдов
	upgradePriority.push_back(Rooms::STOCK);
	upgradePriority.push_back(Rooms::FOOD_STORAGE);
	upgradePriority.push_back(Rooms::MAIN_ROOM);
	upgradePriority.push_back(Rooms::CHILD_ROOM);

	tag = "Queen";
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

Queen * Queen::Initialize(vec3 position_, Camera * camera, Resources * res, sf::RenderWindow * window, vector<ForestObject*>* objects)
{
	//6 муравьев и матка в лесу
	Queen* queen = new Queen(camera, res, window, objects);
	objects->push_back(queen);
	queen->antsInAnthillForNow = 6;
	queen->setPosition(position_);

	return queen;
}

Anthill * Queen::CreateAnthill()
{
	//устанавливаем сам муравейник
	anthill = new Anthill(window, camera, res);
	anthill->setScale(vec3(0.5f, 0.5f, 0.5f));
	anthill->setPosition(position);
	objects->push_back(anthill);

	return anthill;
}

void Queen::UpgradeRooms()
{

}
