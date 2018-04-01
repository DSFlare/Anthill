#include <iostream>
#include <fstream>
#include "Forest.h"

int main()	
{	
	sf::RenderWindow* window = Forest::InitializeGL(1920, 1080, sf::Style::Default);
	Resources res;

	//���� �����������. ����� ���� ������� ������� ��������� (������� �� �������)
	res.standartShader = Shader("Resources\\vertex.glsl", "Resources\\fragment.glsl");
	res.selectedShader = Shader("Resources\\vertex.glsl", "Resources\\fragment.glsl");
	res.testTex.loadFromFile("Resources\\test.png");
	res.dirtTex.loadFromFile("Resources\\dirt.jpg");
	res.anthillTex.loadFromFile("Resources\\anthill.jpg");
	res.screenCenter.loadFromFile("Resources\\centre.png");
	res.anthillSprite.loadFromFile("Resources\\UI\\uiAnthill.png");
	res.hotkeys.loadFromFile("Resources\\UI\\hotkeys.png");
	
	Parametres par;

	Forest forest(window, &res, &par);

	forest.StartSimulation();
	
	return 0;
}