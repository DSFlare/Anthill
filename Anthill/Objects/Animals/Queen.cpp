#include "Queen.h"



Queen::Queen(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* objects_, sf::RenderWindow * window_,
			 vec3 position_, vec3 rotation_, vec3 scale_)
			 : Organism(camera_, res_, par_, objects_, window_, position_, rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->queenTex);
	model = new Model3D(res->queenModel, texture);
	objects = objects_;

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

Queen * Queen::Initialize(vec3 position_, Camera * camera, Resources * res, Parametres* par, sf::RenderWindow * window, vector<ForestObject*>* objects)
{
	//6 муравьев и матка в лесу
	Queen* queen = new Queen(camera, res, par, objects, window);
	objects->push_back(queen);
	queen->antsInAnthillForNow = 6;
	queen->setPosition(position_);

	for (int i = 0; i < 6; i++) {
		queen->InstantiateAnt(Role::SCOUT);
	}

	return queen;
}

Anthill * Queen::CreateAnthill()
{
	//устанавливаем сам муравейник
	anthill = new Anthill(window, camera, res, par, objects);
	anthill->setScale(vec3(0.5f, 0.5f, 0.5f));
	anthill->setPosition(position);
	objects->push_back(anthill);

	return anthill;
}

void Queen::UpgradeRooms()
{

}

void Queen::InstantiateAnt(Role role, ForestObject* target_)
{
	Ant* ant = new Ant(camera, res, par, objects, window);
	objects->push_back(ant);
	ant->setPosition(position);
	
	if (role == Role::SCOUT)
		if (target_ == nullptr)
			ant->Scout();
		else
			ant->Scout(target_);
	else if (role == Role::WARRIOR)
		ant->Warrior();
	else if (role == Role::HUNTER)
		ant->Hunter(target_);
	else
		ant->Eadle();
}
