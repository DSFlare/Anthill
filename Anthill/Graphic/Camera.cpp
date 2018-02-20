#include "Camera.h"
#include <iostream>

Camera::Camera(int * windowWidth_, int * windowHeight_, float* deltaTime_)
{
	deltaTime = deltaTime_;
	windowWidth = windowWidth_; 
	windowHeight = windowHeight_; 
	setPosition(vec3(1, 0, 3));

	movementSpeed = 2;

	Update();
}

void Camera::LookAt(vec3 position)
{

}

void Camera::HandleEvent(sf::Event e)
{
	if (e.type == sf::Event::MouseMoved){}

	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::W)
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
}

void Camera::Destroy()
{
}

void Camera::Update()
{
	//движение
	vec3 deltaPos(0, 0, 0);
	if (up)
   		deltaPos += vec3(0, 1, 0);
	else if (down)
		deltaPos -= vec3(0, 1, 0);
	if (left)
		deltaPos -= vec3(1, 0, 0);
	else if (right)
		deltaPos += vec3(1, 0, 0);
	if (forwardd)
		deltaPos -= vec3(0, 0, 1);
	else if (backward)
		deltaPos += vec3(0, 0, 1);

	if (deltaPos != vec3(0, 0, 0)) {
		deltaPos = glm::normalize(deltaPos);
	}

	setPosition(getPosition() + deltaPos * (*deltaTime) * movementSpeed);


	//просчитываем матрицы вида и проекции
	vec3 frontVec;
	viewMatrix = glm::lookAt(getPosition(), getPosition() + vec3(0, 0, -1), vec3(0, 1, 0));
	projectionMatrix = glm::perspective(glm::radians(FOV), 
		(float)(*windowWidth) / (*windowHeight), 0.1f, 100.0f);
}
