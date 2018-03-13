#pragma once
#include "Ant.h"
#include "Organism.h"
#include "../Anthill.h"
#include "../Stick.h"
#include "../Leaf.h"

class Queen : public Organism
{
private:

	vector<Ant*> colony; // все муравьи из этого муравейника
	vector<Ant*> hunters;
	vector<Ant*> scouts;
	vector<Ant*> warriors;
	vector<Stick*> sticks; // ветки, которые найдены, но не подобраны
	vector<Leaf*> leafs;  // листья, которые найдены, но не подобраны
	vector<Organism*> enemies;

	Anthill* anthill;

public:

	Queen(Camera * camera_, Resources * res_, sf::RenderWindow * window_,
		  vec3 position_ = vec3(0, 0, 0),
		  vec3 rotation_ = vec3(0, 0, 0),
		  vec3 scale_    = vec3(1, 1, 1));
	
	virtual void Death() override;
	virtual void Update() override;
	virtual ~Queen();

	//методы машины состояний


};

