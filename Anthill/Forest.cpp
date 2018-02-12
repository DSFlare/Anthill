#include "Forest.h"
#include <GL\glew.h>
#include <iostream>



Forest::Forest()
{
}


Forest::~Forest()
{
}

int Forest::StartSimulation()
{
	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = true;
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Anthill simulation",
		sf::Style::Default, contextSettings);
	window->setVerticalSyncEnabled(true);

	//инициализируем GLEW перед использованием каких-либо функций openGL
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			processEvents(event);
		}






		// Finally, display the rendered frame on screen
		window->display();
	}

}

void Forest::processEvents(sf::Event e)
{
	// Close window: exit
	if (e.type == sf::Event::Closed)
	{
		window->close();
	}

	// Escape key: exit
	if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape))
	{
		window->close();
	}

	//TODO: определенные события рассылаются всем объектам на сцене
	if (false) {
		for (auto obj : objects) {
			obj->HandleEvent(e);
		}
	}
}
