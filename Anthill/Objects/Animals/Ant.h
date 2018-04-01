#pragma once
#include "Organism.h"
#include "../Stick.h"
#include "../Leaf.h"

class Queen;

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
	Queen* queen;  //Своя матка
	vector<ForestObject*> items;  // найденные ветки и палки
	vector<Organism*> enemies; //найденыне новые враги

	bool isFree = true;	//true, если муравей ничего не несет
	Organism* target; //цель для движения, вспомогательное поле

public:

	Ant(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, sf::RenderWindow * window_, Queen* queen,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(0.1, 0.1, 0.1));

	virtual void Destroy() override;
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

	//Общие методы

	/*/
	ищет ресурсы в зоне видимости,
	если в параметре true, то если найдет свободный ресурс, возварщает true и будет подходить к нему, подбирать и уносить в муравейник,
	если false - просто будет запоминать увиденные ресурсы, чтобы потом сообщить о них
	/*/
	bool checkRes(bool needToPickUp = false); 

	/*/
	Если needToReport - true, то при засвете нового врага возвратиться в муравейник, чтобы сообщить матке и вернет true,
			если не найдет нового, вернет false
	В обратном случае просто будет добавлять себе новых врагов и возвращать false
	/*/
	bool checkEnemies(bool needToReport);

	//Eadle

	void goHome();	//муравей идет в сторону своего муравейника
	//void goBack(); 
	void enterToAnthill(); //вызывается, когда муравей подошел вплотную к муравейнику


	//методы Hunter
	void followEnemy();
	void Fight();

	//методы Scout
	void explore();
	void pickUp(ForestObject* item);


	//общие методы
	
	//методы Warrior

	//для движения
	vec3 followTowards(vec3 target, bool isApproach = false);   //isApproach - замедлять ли движение при подходе к цели
	void calculateDiraction(); //меняет rotation исходя из заданного движения
};