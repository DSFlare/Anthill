#include "Notificator.h"

std::deque<sf::Text> Notificator::notifications;
sf::Font Notificator::font;
sf::RenderWindow* Notificator::window;

void Notificator::initialize(sf::RenderWindow* window_)
{
	window = window_;
	if (!(font).loadFromFile("Resources/UI/font.ttf"))
	{
		std::cout << "Failed font loading\n";
	}
}

void Notificator::notificate(std::string str, sf::Color color)
{
	sf::Text text;
	text.setString(str);
	text.setColor(color);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setOrigin(text.getLocalBounds().width, text.getLocalBounds().height / 2.0f);
	if (notifications.size() == 3)
	{
		notifications.pop_front();
	}
	notifications.push_front(text);
}

void Notificator::update()
{
	draw();
}

void Notificator::draw()
{
	int y = window->getSize().y - 120;
	for (sf::Text text : notifications)
	{
		text.setPosition(window->getSize().x - 20, y);
		window->draw(text);
		y -= 40;
	}
}