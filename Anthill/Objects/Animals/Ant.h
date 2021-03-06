#pragma once
#include "Organism.h"
#include "../Stick.h"
#include "../Leaf.h"

class Queen;

enum Role {
	SCOUT,
	WARRIOR,
	HUNTER,
	EADLE,
	WORKER
};

class Ant : public Organism
{
private:

	void(Ant::*action)();	//�������, ������������� ������ ����
	Role role = EADLE;
	vec3 anthillPosition; //���������� ������� �����������
	Queen* queen;  //���� �����
	vector<ForestObject*> items;  // ��������� ����� � �����
	vector<Organism*> enemies; //��������� ����� �����

	bool isFree = true;	//true, ���� ������� ������ �� �����
	ForestObject* target; //���� ��� ��������, ��������������� ����

	int changeDirTimer = 0;
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
	void Worker();
	//TODO
	void Warrior();



private:

	//����� ������
	/*/
	�������� ������� ������ �� �������������
	���� ������� � ����������� �������� �������� ��� �� ������ �������
	/*/
	void hungry();

	/*/
	���� ������� � ���� ���������,
	���� � ��������� true, �� ���� ������ ��������� ������, ���������� true � ����� ��������� � ����, ��������� � ������� � ����������,
	���� false - ������ ����� ���������� ��������� �������, ����� ����� �������� � ���
	/*/
	bool checkRes(bool needToPickUp); 

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
	void followItem();
	void pickUp(ForestObject* item);


	//����� ������
	
	//������ Warrior

	//��� ��������
	vec3 followTowards(vec3 target, bool isApproach = false);   //isApproach - ��������� �� �������� ��� ������� � ����
	void calculateDiraction(); //������ rotation ������ �� ��������� ��������
};