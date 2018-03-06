#pragma once
#include <GL\glew.h>
#include <SFML\Graphics.hpp>

#include "Model3D.h"
#include "Shader.h"
#include "Camera.h"
#include "glm\glm.hpp"
#include "../Resources/Resources.h"

class Drawable3D
{
protected:
	Model3D* model;
	Shader* shader;
	sf::Texture* texture;
	sf::RenderWindow* window;
	Camera* camera;
	Resources* res;

	vec3 *positionFO;
	vec3 *rotationFO; //крен, рыскание, тангаж (roll, yaw, pitch) - все углами эйлера
	vec3 *scaleFO;
public:
	Drawable3D(sf::RenderWindow* window_, Camera* camera_, Resources* res_, vec3 *position_, vec3 *rotation_, vec3 *scale_);
	~Drawable3D();

	//объекты отрисовывают сами себя (этот метод вызывается из Update() у объекта)
	void Draw(); 
};