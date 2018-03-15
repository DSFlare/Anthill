#pragma once
#include "Organism.h"
#include "../Stick.h"
#include "../Leaf.h"

enum Role {
	SCOUT,
	WARRIOR,
	HUNTER,
	EADLE
};

class Ant : public Organism
{
private:

	void(Ant::*action)();
	Role role = EADLE;
	vec3 anthillPosition; //координаты родного муравейника
	vector<ForestObject*> items;  // найденные ветки и палки
	vector<Organism*> enemies; //найденыне новые враги

	bool isFree = true;	//true, если муравей ничего не несет

	//все это будет в ресурсах(пока так)
	//For stearing behaviour
	float maxVelosity = 0.015;	//максимальная дальность передвижения
	float maxForce = 0.01f;	//макс величина изменения velosity
	float circkeDistance = 3;	//круг перед существом, для рандомного движения
	float circleRadius = 0.7;  //радиус круга
	float approachRadius = 0.5;
	float changeDirTimer = 0;
	float changeDirFreq = 2;

	float viewDistance = 1;

public:

	Ant(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(0.1, 0.1, 0.1));

	virtual void Death() override;
	virtual void Update() override;
	virtual ~Ant();

	Role getRole() { return role; }
	
	//Входные точки в роли
	void Scout(); //приносит ресурсы и сообщает о живой еде
	void Scout(ForestObject* target); //приносит ресурсы и сообщает о живой еде
	void Hunter(ForestObject* target); //
	void Eadle();
	//TODO
	void Warrior();



private:
	//Eadle

	void goHome();
	void goBack(); //муравей идет в сторону своего муравейника
	void enterToAnthill(); //вызывается, когда муравей подошел вплотную к муравейнику


	//методы Hunter

	//методы Scout
	void explore();
	void pickUp(ForestObject* item);
	bool checkRes(); //ищет ресурсы в зоне видимости, если нашел возвр true

	//общие методы
	
	//методы Warrior

	//для движения
	vec3 followTowards(vec3 target, bool isApproach = true);   //isApproach - замедлять ли движение при подходе к цели
	void calculateDiraction(); //меняет rotation исходя из заданного движения
};