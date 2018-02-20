#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <SFML\Graphics.hpp>

#include "Objects\ForestObject.h"
#include "Objects\Landscape.h"
#include "Graphic\Camera.h"
//#include "Time.h"

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

	//время
	sf::Clock clock;
	float deltaTime;
	float lastFrame;

	void Init();

public:
	Forest();
	~Forest();

	void Update();
	void AddObject(ForestObject* obj);

	int StartSimulation();
	void ProcessEvents(sf::Event);
};

