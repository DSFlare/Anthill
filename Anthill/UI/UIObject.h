#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

using sf::Vector2f;

class UIObject
{
protected:
	Vector2f position;
	Vector2f scale;
	std::vector<UIObject*>* allObjects;
	UIObject* parent;
	std::vector<UIObject*> childs;
	sf::RenderWindow* window;
public:
	bool isActive;

	UIObject(sf::RenderWindow* window_) { window = window_; isActive = true; }
	virtual ~UIObject();

	Vector2f getPosition() { return position; }
	Vector2f getScale() { return scale; }
	virtual void setPosition(Vector2f position_) { position = position_; }
	virtual void setScale(Vector2f scale_) { scale = scale_; }

	UIObject* getChild(int index) { return childs[index]; }
	UIObject* getParent() { return parent; }
	void setParent(UIObject* obj);
	bool findChild(std::string tag, UIObject* container);
	
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void HandleEvent(sf::Event e) = 0;
	virtual void Destroy() = 0;

	virtual void hiddenUpdate() final;
};

