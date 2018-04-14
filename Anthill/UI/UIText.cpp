#include "UIText.h"
#include <iostream>


UIText::UIText(sf::RenderWindow* window_, std::string font_)
	:UIObject(window_)
{
	if (!(font).loadFromFile(font_))
	{
		std::cout << "Failed font loading\n";
	}
	text.setFont(font);
	text.setColor(sf::Color::Black);
	text.setString("");
	text.setOrigin(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
}

void UIText::setPosition(Vector2f position_)
{
	position = position_;
	text.setPosition(position_);
}

void UIText::setScale(Vector2f scale_)
{
	scale = scale_;
	text.setScale(scale_);
	text.setOrigin(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
}

void UIText::setFontSize(int fontSize)
{
	text.setCharacterSize(fontSize);
	text.setOrigin(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
}

void UIText::setText(std::string text_)
{
	text.setString(text_);
	text.setOrigin(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
}

void UIText::Update()
{
	if (isActive)
		Draw();
}

void UIText::Draw()
{
	window->draw(text);
}

void UIText::HandleEvent(sf::Event e)
{
	if (isActive && e.type == sf::Event::MouseButtonPressed)
	{

	}
	if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::K)
	{
		isActive = !isActive;
	}
}

void UIText::Destroy()
{
}


UIText::~UIText()
{
}