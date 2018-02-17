#include "Camera.h"

void Camera::LookAt(vec3 position)
{

}

void Camera::HandleEvent(sf::Event e)
{
	if (e.type == sf::Event::MouseMoved)
	{

	}

	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::W)
		forwardd = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::A)
		backward = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::S)
		left = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::D)
		right = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::LShift)
		down = true;
	else if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Space)
		up = true;
}

void Camera::Destroy()
{
}

void Camera::Update()
{
	
}
