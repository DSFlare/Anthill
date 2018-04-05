#pragma once

#include "Ant.h"
#include "Organism.h"
#include "../Anthill.h"
#include "../Stick.h"
#include "../Leaf.h"

class Queen : public Organism
{
private:

	vector<Ant*> hunters;
	vector<Ant*> scouts;
	vector<Ant*> warriors;
	vector<ForestObject*> items; // ветки и листья, которые найдены, но не подобраны
	vector<ForestObject*> enemies;

	Anthill* anthill;
	vector<ForestObject*>* objects;

	typedef enum Rooms
	{
		MAIN_ROOM, FOOD_STORAGE, CHILD_ROOM, STOCK 
	};
	vector<Rooms> upgradePriority;

public:
	int antsInAnthillForNow; // все муравьи, находящиеся именно в муравейнике

	void sendItems(vector<ForestObject*> items);	//ант передает сюда ветки и листья, которые обнаружил, но не собрал
	void antAtHome() { antsInAnthillForNow++; };	//ант вызывает, когда пришел в муравейник
	void sendEnemies(vector<Organism*> enemies);	//ант передает сюда врагов, которых обнаружил

	Queen(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* objects, 
		sf::RenderWindow * window_,

		  vec3 position_ = vec3(0, 0, 0),
		  vec3 rotation_ = vec3(0, 0, 0),
		  vec3 scale_    = vec3(0.07f, 0.07f, 0.07f));
	
	virtual void Destroy() override;
	virtual void Update() override;
	virtual ~Queen();


	//стартовая точка при создании симуляции ===================================
	static Queen* initialize(vec3 position_, Camera *camera, Resources* res, Parametres* par, 
		sf::RenderWindow* window, vector<ForestObject*>* objects);
	Anthill* createAnthill();
	
	//методы машины состояний ==================================================

	void upgradeRooms();
	void instantiateAnt(Role role, ForestObject* target = nullptr);

	vec3 getAnthillPosition();
};