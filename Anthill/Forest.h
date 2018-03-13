#pragma once

#include <GL\glew.h>
#include <SFML\Graphics.hpp>

#include "Objects\ForestObject.h"
#include "Objects\TestObject.h"
#include "Objects\Landscape.h"
#include "Objects\Animals\Ant.h"
#include "Objects\Animals\Beetle.h"
#include "Objects\Animals\Queen.h"
#include "Objects\Anthill.h"
#include "Objects\Stick.h"
#include "Objects\Leaf.h"
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

	//время
	sf::Clock clock;
	float deltaTime;
	float lastFrame;

	void Init();



public:
	Forest(sf::RenderWindow* window_, Resources* res);
	~Forest();

	static sf::RenderWindow* InitializeGL(int width, int height, int style);

	void Update();
	void AddObject(ForestObject* obj);

	int StartSimulation();
	void ProcessEvents(sf::Event);
};

