#include "Forest.h"


void Forest::Init()
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
		return;
	}
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClearColor(0.6f, 0.85f, 0.9f, 1.0f); //����, ������� ����� ������ �����
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//�������������� ���������� �������
	//t::deltaTime = 0;
	//t::lastFrame = 0;
	deltaTime = 0;
	lastFrame = 0;

	//������� ������
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
	//��������� ���������� �������
	//t::update();
	//std::cout << t::deltaTime << "    " << t::lastFrame << std::endl;
	float now = clock.getElapsedTime().asSeconds();
	deltaTime = now - lastFrame;
	lastFrame = now;
	std::cout << deltaTime << "    " << lastFrame << std::endl;

	//================================================================
	
	

	//================================================================

	//��� ������� ������� � ���� �������� Update()
	for (auto obj : objects)
	{
		obj->Update();
	}
}

int Forest::StartSimulation()
{
	//������� �����������
	objects.push_back(new Landscape(window, camera));



	
	////////////////////////////////////////////////////////////////////////
	/////////////////////////// -- GAME CYCLE -- ///////////////////////////
	////////////////////////////////////////////////////////////////////////

	while (window->isOpen())
	{
		//�������
		sf::Event event;
		while (window->pollEvent(event))
		{
			ProcessEvents(event);
		}

		//OpenGL ��������
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//���������� � ��������� ���� Drawable � UI ��������
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

	//TODO: ������������ ������� ����������� ���� �������� �� �����
	if (true) {
		for (auto obj : objects) {
			obj->HandleEvent(e);
		}
	}
}
