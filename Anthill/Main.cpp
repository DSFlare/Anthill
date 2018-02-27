#include <iostream>
#include <fstream>
#include "Forest.h"

int main()	
{	
	sf::RenderWindow* window = Forest::InitializeGL(1280, 720, sf::Style::Default);
	Resources res;

	//пока захардкорим. потом если припрет напишем интерфейс (надеюсь не припрет)
	res.standartShader = Shader("Resources\\vertex.glsl", "Resources\\fragment.glsl");
	res.selectedShader = Shader("Resources\\vertex.glsl", "Resources\\fragment.glsl");
	res.testTex.loadFromFile("Resources\\test.png");
	res.dirtTex.loadFromFile("Resources\\dirt.jpg");
	res.screenCenter.loadFromFile("Resources\\centre.png");
	
	Forest forest(window, &res);

	forest.StartSimulation();
	
	return 0;
}