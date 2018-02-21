#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <SFML\Graphics.hpp>

#include "Objects\ForestObject.h"
#include "Objects\Landscape.h"
#include "Objects\Animals\Ant.h"
#include "Objects\Staff.h"
#include "Graphic\Camera.h"
//#include "Time.h"

#include <vector>
#include <iostream>
#include "Resources\Resources.h"


// главный управляющий класс
class Forest     
{
private:

	int windowWidth = 1280, windowHeight = 720;
	sf::RenderWindow* window;
	std::vector<ForestObject*> objects;
	Camera* camera;
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

	static sf::RenderWindow* InitializeGL(int width, int height);

	void Update();
	void AddObject(ForestObject* obj);

	int StartSimulation();
	void ProcessEvents(sf::Event);
};

