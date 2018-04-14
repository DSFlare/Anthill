#pragma once
#include "d:\Projects\Anthill\Anthill\UI\UIObject.h"

class UIText :
	public UIObject
{
protected:
	sf::Font font;
	sf::Text text;
public:
	UIText(sf::RenderWindow* window_, std::string font_);
	~UIText();

	virtual void setPosition(Vector2f position) override;
	virtual void setScale(Vector2f scale) override;
	void setFontSize(int fontSize);

	void setText(std::string text);

	virtual void Update() override;
	virtual void Draw() override;
	virtual void HandleEvent(sf::Event e) override;
	virtual void Destroy() override;
};