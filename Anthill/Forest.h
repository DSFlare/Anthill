#pragma once
#include <SFML\Graphics.hpp>
#include "ForestObject.h"
#include "Graphic\Camera.h"
#include <vector>
#include "Time.h"

// ������� ����������� �����
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
	void processEvents(sf::Event);
};

