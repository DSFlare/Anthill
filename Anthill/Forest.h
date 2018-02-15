#pragma once
#include <GL\glew.h>
#include <SFML\Graphics.hpp>

#include "ForestObject.h"
#include "Graphic\Camera.h"
#include "Time.h"

#include <vector>
#include <iostream>

// главный управл€ющий класс
class Forest     
{
private:
	int windowWidth = 1280, windowHeight = 720;
	sf::RenderWindow* window;
	std::vector<ForestObject*> objects;
	Camera* camera;

	void Init();
public:
	Forest();
	~Forest();

	void Update();
	void AddObject(ForestObject* obj);

	int StartSimulation();
	void ProcessEvents(sf::Event);
};

