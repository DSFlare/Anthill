#pragma once
#include "UIImage.h"

class UIAnthill: public UIImage 
{
public:
	UIAnthill(sf::RenderWindow* window_, sf::Texture* texture_);
	~UIAnthill();

	virtual void setPosition(Vector2f position) override;
	virtual void setScale(Vector2f scale) override;

	virtual void Update() override;
	virtual void Draw() override;
	virtual void HandleEvent(sf::Event e) override;
	virtual void Destroy() override;
};

