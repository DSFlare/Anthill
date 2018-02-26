#pragma once
#include "UIObject.h"

class UIImage : public UIObject
{
private:
	sf::Sprite sprite;
	sf::Texture* texture;

public:
	UIImage(sf::RenderWindow* window_, sf::Texture* texture_);

	virtual void setPosition(Vector2f position) override;
	virtual void setScale(Vector2f scale) override;

	virtual void Update() override;
	virtual void Draw() override;
	virtual void HandleEvent(sf::Event e) override;
	virtual void Destroy() override;

};
