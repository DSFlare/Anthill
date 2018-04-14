#include "UIAnthill.h"
#include <iomanip>


UIAnthill::UIAnthill(sf::RenderWindow* window_, sf::Texture* texture_, Anthill* anthill_)
	: UIImage(window_, texture_), anthill(anthill_)
{
	text = new UIText(window_, "Resources/UI/font.ttf");
	text->setParent(this);
	this->childs.push_back(text);
	text->setFontSize(50);
}

void UIAnthill::drawAnthillInformation()
{
	std::stringstream ss;
	//ss << line << std::fixed << std::setprecision(2) << t1 << " " << t2;

	text->setPosition(position + Vector2f(-0, -180));
	ss << std::fixed << std::setprecision(1) << anthill->getStockFullness() << "/" 
		<< anthill->getStockSize();
	text->setText(ss.str());
	ss.str(std::string());
	text->Draw();

	text->setPosition(position + Vector2f(-80, -30));
	text->setText(std::to_string(anthill->getEggsNumber()) + "/" + std::to_string(anthill->getChildRoomSize()));
	text->Draw();

	text->setPosition(position + Vector2f(85, -30));
	ss << std::fixed << std::setprecision(1) << anthill->getFoodAmount() << "/" 
		<< anthill->getFoodStorageSize();
	text->setText(ss.str());
	ss.str(std::string());
	text->Draw();

	text->setPosition(position + Vector2f(0, 130));
	text->setText(std::to_string(anthill->getWorkersNumber()) + "/" + std::to_string(anthill->getAntsInColony())
		+ "/" + std::to_string(anthill->getMainRoomSize()));
	text->Draw();
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


void UIAnthill::setText(std::string text_)
{
	text->setText(text_);
}

void UIAnthill::Update()
{
	if (isActive)
	{
		Draw();
	}
}

void UIAnthill::Draw()
{
	window->draw(sprite);
	drawAnthillInformation();
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