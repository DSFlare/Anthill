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
	vec3 anthillCoord; //���������� ������� �����������

	//For stearing behaviour
	float maxVelosity = 0.015;	//������������ ��������� ������������
	float maxForce = 0.02f;	//���� �������� ��������� velosity
	float circkeDistance = 2;	//���� ����� ���������, ��� ���������� ��������
	float circleRadius = 0.7;  //������ �����
	float changeDirTimer = 0;

public:

	Ant(Camera * camera_, Resources * res_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(0.1, 0.1, 0.1));

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
	void explore();
	void pickUp(ForestObject item);


	//������ Warrior

	//��� ��������
	vec3 followTowards(vec3 target);
};