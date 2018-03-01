#pragma once
#include "UIImage.h"

class UIHotkeysInfo : public UIImage
{
public:
	UIHotkeysInfo(sf::RenderWindow* window_, sf::Texture* texture_);
	~UIHotkeysInfo();

	virtual void setPosition(Vector2f position) override;
	virtual void setScale(Vector2f scale) override;

	virtual void Update() override;
	virtual void Draw() override;
	virtual void HandleEvent(sf::Event e) override;
	virtual void Destroy() override;
};

