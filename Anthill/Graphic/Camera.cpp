#include "Camera.h"
#include <iostream>

Camera::Camera(int * windowWidth_, int * windowHeight_, float* deltaTime_, sf::RenderWindow* window_,
	Parametres* par_, std::vector<ForestObject*>* allObjects_)
	:ForestObject(window_, NULL, NULL, par_, allObjects_, vec3(0, 5, 0))
{
	deltaTime = deltaTime_;
	windowWidth = windowWidth_; 
	windowHeight = windowHeight_; 
	window = window_;

	movementSpeed = 4;
	mouseSensitivity = 0.15;
	prevMouseX = 0;
	prevMouseY = 0;
	mouseOffsetX = 0;
	mouseOffsetY = 0;
	mouseWheelDelta = 0;

	Update();
}

void Camera::lookAt(vec3 position)
{

}


void Camera::HandleEvent(sf::Event e)
{
	//��������
	if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::W)
		forwardd = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::S)
		backward = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::A)
		left = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::D)
		right = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::LShift)
		down = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Space)
		up = true;
	//����������� ��������
	else if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::W)
		forwardd = false;
	else if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::S)
		backward = false;
	else if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::A)
		left = false;
	else if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::D)
		right = false;
	else if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::LShift)
		down = false;
	else if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Space)
		up = false;
	//��������� �������� ��������
	else if (e.type == sf::Event::MouseWheelMoved)
	{
		mouseWheelDelta += e.mouseWheel.delta;
	}
	//breakpoint
	else if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::B)
	{
		int i = 0;
	}

}

void Camera::Destroy()
{
}

void Camera::Update()
{
	//�������----------------------------

	int mx = sf::Mouse::getPosition().x;
	int my = sf::Mouse::getPosition().y;
	int statex = window->getPosition().x + *windowWidth / 2;
	int statey = window->getPosition().y + *windowHeight / 2;

	mouseOffsetX = statex - mx;
	mouseOffsetY = statey - my;
	vec3 newRot = getRotation() + vec3(0, -mouseOffsetX * mouseSensitivity, mouseOffsetY * mouseSensitivity);
	if (abs(newRot.z) >= 80)
	{
		newRot = vec3(newRot.x, newRot.y, 80 * abs(newRot.z) / newRot.z);
	}
	setRotation(newRot);
	sf::Mouse::setPosition(sf::Vector2i(statex, statey));

	//��������---------------------------
	vec3 deltaPos(0, 0, 0);
	vec3 rot = getRotation();
	if (up)
   		deltaPos += vec3(0, 1, 0);
	else if (down)
		deltaPos -= vec3(0, 1, 0);
	if (left)
		deltaPos -= vec3(cos(glm::radians(rot.y + 90)), 0, sin(glm::radians(rot.y + 90)));
	else if (right)
		deltaPos += vec3(cos(glm::radians(rot.y + 90)), 0, sin(glm::radians(rot.y + 90)));
	if (forwardd)
		deltaPos += vec3(cos(glm::radians(rot.y)), 0, sin(glm::radians(rot.y)));
	else if (backward)
		deltaPos -= vec3(cos(glm::radians(rot.y)), 0, sin(glm::radians(rot.y)));
	
	if (deltaPos != vec3(0, 0, 0)) 
		deltaPos = glm::normalize(deltaPos);
	setPosition(getPosition() + deltaPos * (*deltaTime) * movementSpeed);

	//�������� �������� ��������
	if (mouseWheelDelta != 0)
	{
		int sign = 1;
		if (mouseWheelDelta < 0) sign = -1;

		for (int i = 0; i < abs(mouseWheelDelta); i++)
			movementSpeed += sign * 0.3 * movementSpeed;

		mouseWheelDelta = 0;
	}
	
	//������������ ������� ���� � ��������
	vec3 purpose;
	purpose.x = cos(glm::radians(rot.z)) * cos(glm::radians(rot.y));
	purpose.y = sin(glm::radians(rot.z));
	purpose.z = cos(glm::radians(rot.z)) * sin(glm::radians(rot.y));

	viewMatrix = glm::lookAt(getPosition(), getPosition() + purpose, vec3(0, 1, 0));
	projectionMatrix = glm::perspective(glm::radians(FOV), 
		(float)(*windowWidth) / (*windowHeight), 0.1f, 100.0f);
}
