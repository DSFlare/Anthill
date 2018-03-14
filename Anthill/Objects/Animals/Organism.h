#pragma once
#include "../ForestObject.h"

class Organism
	: public ForestObject
{
private:
	int health;
	int attack;
protected:
	vec3 velosity; //скорость
	vec3 acceler; //изменение скорости

	// для рандомного движения
	/*float CIRLE_DISTANCE = 0.5;	 //круг перед существом, для рандомного движения
	float circleRadius = 0.3;
	float wanderAngle = 0;  // угол на сколько будет происходить смещение
	int angleChange = 40;  //диапазон изменения угла поворота
	vec3 wanderForce = vec3(0, 0, 0);	//итоговый вектор смещения*/
public:
	Organism(Camera * camera_, Resources * res_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));

	virtual void Update() override;
	void Start();
	int getHealth();
	void setHealth(int health);
	int getAttack();
	void setAttack(int attack);
	virtual void Death() = 0;
	virtual ~Organism();
};