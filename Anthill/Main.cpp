#include <iostream>
#include <fstream>
#include "Forest.h"

int main()
{
	sf::RenderWindow* window = Forest::InitializeGL(1280, 720);
	Resources res;
	Forest forest(window, &res);
	forest.StartSimulation();

	return 0;
}