#pragma once

#include <GL\glew.h>
#include <SFML\Graphics.hpp>

#include "Objects\ForestObject.h"
#include "Objects\Landscape.h"
#include "Objects\Animals\Ant.h"
#include "Objects\Animals\Beetle.h"
#include "Objects\Animals\Caterpillar.h"
#include "Objects\Animals\Queen.h"
#include "Objects\Anthill.h"
#include "Objects\Stick.h"
#include "Objects\Leaf.h"
#include "Objects/EnvironmentalObject.h"
#include "Graphic\Camera.h"
#include "Resources\Resources.h"
#include "UI\Canvas.h"

#include <vector>
#include <iostream>


// главный управляющий класс
class Forest     
{
private:

	int windowWidth = 1280, windowHeight = 720;
	sf::RenderWindow* window;
	std::vector<ForestObject*> objects;
	Camera* camera;
	Canvas canvas;
	bool isCursorVisible = false;
	Resources* res;
	Parametres* par;
	bool isRunning = true;



	//время
	sf::Clock clock;
	float deltaTime;
	float lastFrame;

	float generateItemsTimer = 0;

	void generateItems(int leafQuantity, int stickQuantity); //рандомно генерирует палки и листья
	void generateEnemies(int bugs, int caterpillars); //рандомно генерирует врагов


public:
	Forest(sf::RenderWindow* window_, Resources* res, Parametres* par);
	~Forest();

	static sf::RenderWindow* InitializeGL(int width, int height, int style);

	void Update();
	void addObject(ForestObject* obj);

	int startSimulation();
	void processEvents(sf::Event);
};

