#include "UIAnthill.h"



UIAnthill::UIAnthill(sf::RenderWindow* window_, sf::Texture* texture_)
	: UIImage(window_, texture_)
{
}


UIAnthill::~UIAnthill()
{
}

void UIAnthill::setPosition(Vector2f position_)
{
	position = position_;
	sprite.setPosition(position_);
}

void UIAnthill::setScale(Vector2f scale_)
{
	scale = scale_;
}

void UIAnthill::Update()
{
	if (isActive)
		Draw();
}

void UIAnthill::Draw()
{
	window->draw(sprite);
}

void UIAnthill::HandleEvent(sf::Event e)
{
	if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::P))
	{
		isActive = !isActive;
	}
}

void UIAnthill::Destroy()
{
}

