#include "UIHotkeysInfo.h"



UIHotkeysInfo::UIHotkeysInfo(sf::RenderWindow* window_, sf::Texture* texture_)
	: UIImage(window_, texture_)
{
}


UIHotkeysInfo::~UIHotkeysInfo()
{
}

void UIHotkeysInfo::setPosition(Vector2f position_)
{
	position = position_;
	sprite.setPosition(position_);
}

void UIHotkeysInfo::setScale(Vector2f scale_)
{
	scale = scale_;
}

void UIHotkeysInfo::Update()
{
	if (isActive)
		Draw();
}

void UIHotkeysInfo::Draw()
{
	window->draw(sprite);
}

void UIHotkeysInfo::HandleEvent(sf::Event e)
{
	if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::I))
	{
		isActive = !isActive;
	}
}

void UIHotkeysInfo::Destroy()
{
}