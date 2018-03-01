#include "Forest.h"



Forest::Forest(sf::RenderWindow* window_, Resources* res_)
{
	res = res_;
	window = window_;
	windowWidth = window->getSize().x;
	windowHeight = window->getSize().y;

	//ресурсы
	res->LoadShaders("Resources\\vertex.glsl", "Resources\\fragment.glsl", 
		"Resources\\vertex.glsl", "Resources\\fragment.glsl");
	res->LoadModels("Resources/Models/RedAnt/formica rufa.obj", 
		"Resources/Models/Queen/gigantic_ant_monster.obj",
		"", "Resources/Models/Beetle/rolypolymodoli.obj", "Resources/Models/Anthill/anthill.obj");

	res->LoadTextures("", "", "Resources/Models/RedAnt/texture.jpg", "", "", "", "", "", "");

	//инициализируем переменные времени
	deltaTime = 0;
	lastFrame = 0;

	//создаем камеру
	camera = new Camera(&windowWidth, &windowHeight, &deltaTime, window);
	objects.push_back(&(*camera));
}

Forest::~Forest()
{
}

sf::RenderWindow* Forest::InitializeGL(int width, int height, int style)
{
	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = true;
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(width, height), "Anthill simulation",
		style, contextSettings);
	window->setVerticalSyncEnabled(true);

	//инициализируем GLEW перед использованием каких-либо функций openGL
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return NULL;
	}

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClearColor(0.6f, 0.85f, 0.9f, 1.0f); //цвет, которым будет очищен экран
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	sf::Mouse::setPosition(sf::Vector2i(window->getPosition().x + width / 2, 
		window->getPosition().y + height / 2));
	return window;
}

void Forest::Update()
{
	//обновляем переменные времени
	float now = clock.getElapsedTime().asSeconds();
	deltaTime = now - lastFrame;
	lastFrame = now;
	std::cout << deltaTime << "    " << lastFrame << std::endl;




	//для каждого объекта в лесу вызываем Update()
	for (auto obj : objects)
	{
		obj->Update();
	}
	window->pushGLStates();
	canvas.Update();
	window->popGLStates();
}

void Forest::AddObject(ForestObject * obj)
{

}

int Forest::StartSimulation()
{
	////////////////////////////////////////////////////////////////////////
	////здесь заполняем сцену (интерфейс строим в конструкторе у Canvas)////
	////////////////////////////////////////////////////////////////////////
	
	camera->setPosition(vec3(-5, 0, 0));

	//добавим поверхность
	Landscape* landscape = new Landscape(window, camera, res);
	objects.push_back(landscape);
	landscape->setPosition(vec3(0, -5, 0));
	landscape->setRotation(vec3(90, 0, 0));

	//муравейка тест
	Ant* ant = new Ant(camera, res, window, vec3(-2, -5, 0));
	objects.push_back(ant);
	ant->setScale(vec3(0.25f, 0.25f, 0.25f));
	ant->setRotation(vec3(0, 30, 0));
	//objects.push_back(new Beetle(camera, res, window, vec3(0, -4, 0)));
	//objects.push_back(new Queen(camera, res, window, vec3(0, -8, 0)));

	//тест муравейника
	Anthill *anthill = new Anthill(window, camera, res);
	objects.push_back(anthill);
	anthill->setPosition(vec3(0, -5, 0));

	//User interface ebac
	float scrCenterX = window->getSize().x / 2.0f;
	float scrCenterY = window->getSize().y / 2.0f;

	UIImage* screenCenter = new UIImage(window, &(res->screenCenter));
	canvas.objects.push_back(screenCenter);
	screenCenter->setPosition(Vector2f(scrCenterX, scrCenterY));

	UIHotkeysInfo* hotkeysInfo = new UIHotkeysInfo(window, &(res->hotkeys));
	canvas.objects.push_back(hotkeysInfo);
	hotkeysInfo->setPosition(Vector2f(scrCenterX, scrCenterY));
	hotkeysInfo->isActive = false;

	UIAnthill* uiAnthill = new UIAnthill(window, &(res->anthillSprite));
	canvas.objects.push_back(uiAnthill);
	uiAnthill->setPosition(Vector2f(scrCenterX, scrCenterY));
	uiAnthill->isActive = false;
	




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
	else if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape))
	{
		window->close();
	}
	//C - hide/show cursor
	else if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::C))
	{
		isCursorVisible = !isCursorVisible;
		window->setMouseCursorVisible(!isCursorVisible);
	}

	



	//TODO: определенные события рассылаются всем объектам на сцене
	if (true) {
		for (auto obj : objects) {
			obj->HandleEvent(e);
		}
	}
	canvas.HandleEvent(e);
}
