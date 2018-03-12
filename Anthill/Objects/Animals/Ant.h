#pragma once
#include "Organism.h"

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

public:

	Ant(Camera * camera_, Resources * res_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));

	virtual void Death() override;
	virtual void Update() override;
	virtual ~Ant();

	Role getRole() { return role; }
	
	//������� ����� � ����
	void Scout(); //�������� ������� � �������� � ����� ���
	void Scout(ForestObject* target); //�������� ������� � �������� � ����� ���
	void Hunter(Organism* target); //
	void Eadle();
	//TODO
	void Warrior();

private:
	//Eadle

	//������ Hunter

	//������ Scout

	//������ Warrior


};