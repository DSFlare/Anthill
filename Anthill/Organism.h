#pragma once
class Organism
{
private:
	int health;
	int attack;
public:
	Organism();
	void Update();
	void Start();
	int getHealth();
	void setHealth(int health);
	int getAttack();
	void setAttack(int attack);
	virtual void Death();
	virtual ~Organism();
};

