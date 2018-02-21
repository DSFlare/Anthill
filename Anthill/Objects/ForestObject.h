#pragma once
#include <SFML\Graphics.hpp>
#include "glm\glm.hpp"
#include <vector>
#include <string>

using glm::vec3;

class ForestObject
{
	vec3 position;
	vec3 rotation; //крен, рыскание, тангаж (roll, yaw, pitch) - все углами эйлера
	vec3 scale;
	std::vector<ForestObject*>* others;
	ForestObject* parent;
	std::vector<ForestObject*> childs;
	std::string tag = "";

public:
	ForestObject(vec3 position_ = vec3(0, 0, 0), 
				 vec3 rotation_ = vec3(0, 0, 0), 
				 vec3 scale_    = vec3(1, 1, 1));
	virtual ~ForestObject();

	vec3 getPosition() { return position; }
	vec3 getRotation() { return rotation; }
	vec3 getScale()	   { return scale; }
	void setPosition(vec3 position_) { position = position_; }
	void setRotation(vec3 rotation_) { rotation = rotation_; }
	void setScale   (vec3 scale_)	 { scale = scale_; }
	
	ForestObject* GetChild(int index) { return childs[index]; }
	ForestObject* GetParent() { return parent; }
	void SetParent(ForestObject* obj);
	bool FindChild(std::string tag, ForestObject* container);
	
	bool CompareTag(std::string tag) { return this->tag == tag; }
	
	virtual void Update();
	virtual void HandleEvent(sf::Event e);
	virtual void Destroy();

	// здесь происходят все вычисления, которые не должны быть переопределены в потомках
	virtual void HiddenUpdate() final; 
};

