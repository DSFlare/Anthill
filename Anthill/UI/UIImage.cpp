#include "UIImage.h"

UIImage::UIImage(sf::RenderWindow* window_, sf::Texture * texture_) :
	UIObject(window_)
{
	texture = texture_;
	sprite.setTexture(*texture);
	sprite.setOrigin(texture->getSize().x / 2, texture->getSize().x / 2);
}

void UIImage::setPosition(Vector2f position_)
{
	position = position_;
	sprite.setPosition(position_);
}

void UIImage::setScale(Vector2f scale_)
{
	scale = scale_;
}

void UIImage::Update()
{
	if (isActive)
		Draw();
}

void UIImage::Draw()
{
	window->draw(sprite);
}

void UIImage::HandleEvent(sf::Event e)
{
	if (isActive && e.type == sf::Event::MouseButtonPressed)
	{

	}
}

void UIImage::Destroy()
{
}
