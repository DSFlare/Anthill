#pragma once

struct AntParametres
{
	//For stearing behaviour
	float maxVelosity = 0.015;	//������������ ��������� ������������
	float maxForce = 0.01f;	//���� �������� ��������� velosity
	float circkeDistance = 3;	//���� ����� ���������, ��� ���������� ��������
	float circleRadius = 0.7;  //������ �����
	float approachRadius = 0.5;
	float changeDirTimer = 0;
	float changeDirFreq = 2;

	float viewDistance = 1;
	float attackDistance = 0.14;
	float attack = 10;

	float antHealth = 80;
};

struct EnemyParametres
{
	float beetleViewDistance = 2;
	float beetleAttackDistance = 0.15;

	float beetleAttack = 10;
	float beetleHealth = 150;
	float deathTimer = 5;
};

class Parametres
{
public:
	AntParametres AntPar;
	EnemyParametres enemyPar;

	Parametres();
	~Parametres();
};

