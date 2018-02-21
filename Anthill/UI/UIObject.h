#pragma once
#include "glm\glm.hpp"
#include <vector>
#include <SFML\Graphics.hpp>

using glm::vec3;

class UIObject
{
	vec3 position;
	vec3 scale;
	std::vector<UIObject*>* others;
	UIObject* parent;
	std::vector<UIObject*> childs;

public:
	UIObject();
	virtual ~UIObject();

	vec3 getPosition() { return position; }
	vec3 getScale() { return scale; }
	void setPosition(vec3 position_) { position = position_; }
	void setScale(vec3 scale_) { scale = scale_; }

	UIObject* GetChild(int index) { return childs[index]; }
	UIObject* GetParent() { return parent; }
	void SetParent(UIObject* obj);
	bool FindChild(std::string tag, UIObject* container);

	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void HandleEvent(sf::Event e) = 0;
	virtual void Destroy() = 0;

	virtual void HiddenUpdate() final;
};

