#pragma once
#include <SFML\Graphics.hpp>
#include "glm\glm.hpp"
#include <vector>
#include <string>
#include "../Graphic/Model3D.h"
#include "../Graphic/Shader.h"
#include "../Resources/Resources.h"
#include "../Parametres.h"

using glm::vec3;
class Camera;


class ForestObject
{
	
protected:
	std::vector<ForestObject*>* allObjects;
	ForestObject* parent = NULL;
	std::vector<ForestObject*> childs;

	/*Ant, Leaf, Stick и тд. - типы*/
	std::string tag = "";
	bool isDrawn = true;

	//Drawable
	Model3D* model;
	Shader* shader;
	sf::Texture* texture;
	sf::RenderWindow* window;
	Camera* camera;
	Resources* res;
	Parametres* par;

	vec3 position;
	vec3 rotation; //крен, рыскание, тангаж (roll, yaw, pitch) - все углами эйлера
	vec3 scale;

public:

	ForestObject(sf::RenderWindow* window_, Camera* camera_, Resources* res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));

	virtual ~ForestObject();

	vec3 getPosition() { return position; }
	vec3 getRotation() { return rotation; }
	vec3 getScale()	   { return scale; }
	void setPosition(vec3 position_) { position = position_; }
	void setRotation(vec3 rotation_) { rotation = rotation_; }
	void setScale   (vec3 scale_)	 { scale = scale_; }
	
	ForestObject* getChild(int index) { return childs[index]; }
	ForestObject* getParent() { return parent; }
	void setParent(ForestObject* obj);
	bool findChild(std::string tag, ForestObject* container);
	
	bool compareTag(std::string tag) { return this->tag == tag; }
	void setTag(std::string newTag) { tag = newTag;  }
	string getTag();

	bool isObjDrawn();
	void setDrawn(bool isDrawn_);
	
	virtual void Update();
	virtual void HandleEvent(sf::Event e);
	virtual void Destroy();
	
	//объекты отрисовывают сами себя (этот метод вызывается из Update() у объекта)
	void Draw();

	// здесь происходят все вычисления, которые не должны быть переопределены в потомках
	virtual void hiddenUpdate() final; 
};