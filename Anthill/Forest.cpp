#include "Forest.h"
#include <GL\glew.h>
#include <iostream>



void Forest::Init()
{

}

Forest::Forest()
{
	Init();
}

Forest::~Forest()
{
}

void Forest::Update()
{
	//��������� ���������� �������
	t::update();
	std::cout << t::deltaTime << "    " << t::lastFrame << std::endl;

	//��� ������� ������� � ���� �������� Update()
	for (auto obj : objects)
	{
		obj->Update();
	}
}

int Forest::StartSimulation()
{
	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = true;
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Anthill simulation",
		sf::Style::Default, contextSettings);
	window->setVerticalSyncEnabled(true);

	//�������������� GLEW ����� �������������� �����-���� ������� openGL
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClearColor(0.6f, 0.85f, 0.9f, 1.0f); //����, ������� ����� ������ �����
	glClear(GL_COLOR_BUFFER_BIT);

	////////////////////////////////////////////////////////////////////////
	/////////////////////////// -- GAME CYCLE -- ///////////////////////////
	////////////////////////////////////////////////////////////////////////

	while (window->isOpen())
	{
		//�������
		sf::Event event;
		while (window->pollEvent(event))
		{
			processEvents(event);
		}

		//����������
		Update();

		//OpenGL �������� � ���������
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



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

	//TODO: ������������ ������� ����������� ���� �������� �� �����
	if (false) {
		for (auto obj : objects) {
			obj->HandleEvent(e);
		}
	}
}
