#pragma once

struct AntParametres
{
	//For stearing behaviour
	float maxVelosity = 0.015;	//������������ ��������� ������������
	float maxForce = 0.01f;	//���� �������� ��������� velosity
	float circkeDistance = 3;	//���� ����� ���������, ��� ���������� ��������
	float circleRadius = 0.7;  //������ �����
	float approachRadius = 0.5;
	float changeDirFreq = 2;

	float viewDistance = 1;
	float attackDistance = 0.14;
	float attack = 15;

	int a = 10;
	float satietyLooses = 0.04;	//� �������
	float satietyLoosesInAnthill = 0.06;
	float maxSatiety = 3.0f;

	float antHealth = 100;
};

struct BeetleParametres
{
	//For stearing behaviour
	float maxForce = 0.007f;	//���� �������� ��������� velosity
	float maxVelosity = 0.008f;	//������������ ��������� ������������
	float circkeDistance = 3.5f;	//���� ����� ���������, ��� ���������� ��������
	float circleRadius = 0.9;  //������ �����
	float approachRadius = 0.5;	//������ � ������� �������� ��������������� ��� ������� � ����
	float changeDirFreq = 4;

	float viewDistance = 2;
	float attackDistance = 0.15;

	float attack = 10;
	float health = 150;
	float deathTimer = 5;
};
 
struct SimulationParametres
{
	float timeScale = 1.0f;
	float resWithOneWorker = 0.001;
	int startingAntsCount = 6;
	float foodForNewEgg = 5;
	int b = 10;
	int eggGrowingTime = 15;	//� ���
	float saveDistance = 7;
};

struct ForestParametres
{
	float generateItemsDelay = 300;
	int landscapeWidth = 50;
	int landscapeHeight= 50;
};

class Parametres
{
public:
	AntParametres AntPar;
	BeetleParametres beetlePar;
	ForestParametres forestPar;
	SimulationParametres simPar;

	Parametres();
	~Parametres();
};