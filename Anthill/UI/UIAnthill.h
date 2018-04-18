#pragma once
#include "UIImage.h"
#include "../Objects/Anthill.h"
#include "UIText.h"

class UIAnthill: public UIImage 
{
private:
	Anthill* anthill;
	UIText* text;

	void drawAnthillInformation();
public:
	UIAnthill(sf::RenderWindow* window_, sf::Texture* texture_, Anthill* anthill);
	virtual ~UIAnthill();

	virtual void setPosition(Vector2f position) override;
	virtual void setScale(Vector2f scale) override;

	void setText(std::string text);

	virtual void Update() override;
	virtual void Draw() override;
	virtual void HandleEvent(sf::Event e) override;
	virtual void Destroy() override;
};

