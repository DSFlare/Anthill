#include "Forest.h"


void Forest::Init()
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
		return;
	}
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClearColor(0.6f, 0.85f, 0.9f, 1.0f); //цвет, которым будет очищен экран
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//инициализируем переменные времени
	//t::deltaTime = 0;
	//t::lastFrame = 0;
	deltaTime = 0;
	lastFrame = 0;

	//создаем камеру
	camera = new Camera(&windowWidth, &windowHeight, &deltaTime);
	objects.push_back(&(*camera));
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
	//обновляем переменные времени
	//t::update();
	//std::cout << t::deltaTime << "    " << t::lastFrame << std::endl;
	float now = clock.getElapsedTime().asSeconds();
	deltaTime = now - lastFrame;
	lastFrame = now;
	std::cout << deltaTime << "    " << lastFrame << std::endl;

	//================================================================
	
	

	//================================================================

	//для каждого объекта в лесу вызываем Update()
	for (auto obj : objects)
	{
		obj->Update();
	}
}

int Forest::StartSimulation()
{
	//добавим поверхность
	objects.push_back(new Landscape(window, camera));



	
	////////////////////////////////////////////////////////////////////////
	/////////////////////////// -- GAME CYCLE -- ///////////////////////////
	////////////////////////////////////////////////////////////////////////

	while (window->isOpen())
	{
		//события
		sf::Event event;
		while (window->pollEvent(event))
		{
			ProcessEvents(event);
		}

		//OpenGL комманды
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//вычисления и отрисовка всех Drawable и UI объектов
		Update();

	

		window->display();
	}
	return 0;
}

void Forest::ProcessEvents(sf::Event e)
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
	if (true) {
		for (auto obj : objects) {
			obj->HandleEvent(e);
		}
	}
}
