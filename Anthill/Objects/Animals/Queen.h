#pragma once

#include "Ant.h"
#include "Organism.h"
#include "../Anthill.h"
#include "../Stick.h"
#include "../Leaf.h"

class Queen : public Organism
{
private:

	void(Queen::*action)();	//функция, выполняющаяся каждый кадр

	vector<Ant*> hunters;
	vector<Ant*> scouts;
	vector<Ant*> warriors;
	vector<Ant*> workers;
	vector<ForestObject*> items; // ветки и листья, которые найдены, но не подобраны
	vector<ForestObject*> enemies;

	Anthill* anthill;
	vector<ForestObject*>* objects;

	vector<int> eggs;	//яйца
	vector<RoomType> upgradePriority;
	int neededWorkers;
public:
	//int antsInAnthill; // все муравьи, находящиеся именно в муравейнике
		
	void sendBroughtItems(vector<ForestObject*> items);
	void sendItems(vector<ForestObject*> items);	//ант передает сюда ветки и листья, которые обнаружил, но не собрал
	void antAtHome(Ant* ant);;	//ант вызывает, когда пришел в муравейник
	void sendEnemies(vector<Organism*> enemies);	//ант передает сюда врагов, которых обнаружил
	float askFood(float quantity);

	vec3 getAnthillPosition();
	void deletingAnt(Ant* ant);		//ант вызывает при смерти

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

	void instantiateAnt(Role role, ForestObject* target = nullptr);
	
	//методы машины состояний ==================================================
private:
	void beginning();
	void upgradeRooms();
	void setUpgradePriority();
	void layTheEgg();
	void growthEggs();
};