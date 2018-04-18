#pragma once
#include "d:\Projects\Anthill\Anthill\UI\UIText.h"
#include <iostream>
#include <deque>

class Notificator
{
private:
	static std::deque<sf::Text> notifications;
	static sf::Font font;
	static sf::RenderWindow* window;
public:
	static void notificate(std::string str, sf::Color color = sf::Color::Black);
	static void initialize(sf::RenderWindow* window);
	static void update();
	static void draw();
};