#pragma once
#include <SFML\Graphics.hpp>
#include "ForestObject.h"
#include <vector>

class Forest
{
private:
	int windowWidth = 1280, windowHeight = 720;
	sf::RenderWindow* window;
	std::vector<ForestObject*> objects;

	//время
	sf::Clock clock;

	void Init();
public:
	Forest();
	~Forest();

	void Update();
	void AddObject(ForestObject* obj);
	void GetDeltaTime();

	int StartSimulation();
	void processEvents(sf::Event);
};

