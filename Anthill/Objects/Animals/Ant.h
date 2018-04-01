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
	vec3 anthillPosition; //���������� ������� �����������
	Queen* queen;  //���� �����
	vector<ForestObject*> items;  // ��������� ����� � �����
	vector<Organism*> enemies; //��������� ����� �����

	bool isFree = true;	//true, ���� ������� ������ �� �����
	Organism* target; //���� ��� ��������, ��������������� ����

public:

	Ant(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, sf::RenderWindow * window_, Queen* queen,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(0.1, 0.1, 0.1));

	virtual void Destroy() override;
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

	//����� ������

	/*/
	���� ������� � ���� ���������,
	���� � ��������� true, �� ���� ������ ��������� ������, ���������� true � ����� ��������� � ����, ��������� � ������� � ����������,
	���� false - ������ ����� ���������� ��������� �������, ����� ����� �������� � ���
	/*/
	bool checkRes(bool needToPickUp = false); 

	/*/
	���� needToReport - true, �� ��� ������� ������ ����� ������������ � ����������, ����� �������� ����� � ������ true,
			���� �� ������ ������, ������ false
	� �������� ������ ������ ����� ��������� ���� ����� ������ � ���������� false
	/*/
	bool checkEnemies(bool needToReport);

	//Eadle

	void goHome();	//������� ���� � ������� ������ �����������
	//void goBack(); 
	void enterToAnthill(); //����������, ����� ������� ������� �������� � �����������


	//������ Hunter
	void followEnemy();
	void Fight();

	//������ Scout
	void explore();
	void pickUp(ForestObject* item);


	//����� ������
	
	//������ Warrior

	//��� ��������
	vec3 followTowards(vec3 target, bool isApproach = false);   //isApproach - ��������� �� �������� ��� ������� � ����
	void calculateDiraction(); //������ rotation ������ �� ��������� ��������
};