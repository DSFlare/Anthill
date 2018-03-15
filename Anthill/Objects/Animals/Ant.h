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
	vec3 anthillPosition; //���������� ������� �����������
	vector<ForestObject*> items;  // ��������� ����� � �����
	vector<Organism*> enemies; //��������� ����� �����

	bool isFree = true;	//true, ���� ������� ������ �� �����

	//��� ��� ����� � ��������(���� ���)
	//For stearing behaviour
	float maxVelosity = 0.015;	//������������ ��������� ������������
	float maxForce = 0.01f;	//���� �������� ��������� velosity
	float circkeDistance = 3;	//���� ����� ���������, ��� ���������� ��������
	float circleRadius = 0.7;  //������ �����
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
	
	//������� ����� � ����
	void Scout(); //�������� ������� � �������� � ����� ���
	void Scout(ForestObject* target); //�������� ������� � �������� � ����� ���
	void Hunter(ForestObject* target); //
	void Eadle();
	//TODO
	void Warrior();



private:
	//Eadle

	void goHome();
	void goBack(); //������� ���� � ������� ������ �����������
	void enterToAnthill(); //����������, ����� ������� ������� �������� � �����������


	//������ Hunter

	//������ Scout
	void explore();
	void pickUp(ForestObject* item);
	bool checkRes(); //���� ������� � ���� ���������, ���� ����� ����� true

	//����� ������
	
	//������ Warrior

	//��� ��������
	vec3 followTowards(vec3 target, bool isApproach = true);   //isApproach - ��������� �� �������� ��� ������� � ����
	void calculateDiraction(); //������ rotation ������ �� ��������� ��������
};