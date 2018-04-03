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
	float attack = 10;

	float antHealth = 80;
};

struct BeetleParametres
{
	//For stearing behaviour
	int a = 10;
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

struct ForestParametres
{
	float generateItemsDelay = 1000;
};

class Parametres
{
public:
	AntParametres AntPar;
	BeetleParametres beetlePar;
	ForestParametres forestPar;

	Parametres();
	~Parametres();
};