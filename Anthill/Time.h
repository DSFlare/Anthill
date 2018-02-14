#pragma once
#include <SFML\System.hpp>

namespace t
{
	static sf::Clock clock;
	static float lastFrame = 0;
	static float deltaTime = 0;

	static void update()
	{
		float now = clock.getElapsedTime().asSeconds();
		deltaTime = now - lastFrame;
		lastFrame = now;
	}
}