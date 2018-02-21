#pragma once
#include <GL\glew.h>
#include <SFML\Graphics.hpp>

#include "Model3D.h"
#include "Shader.h"
#include "Camera.h"
#include "../Resources/Resources.h"

#include "glm\glm.hpp"



class Drawable3D
{
protected:
	Model3D* model;
	Shader* shader;
	sf::Texture texture;
	sf::RenderWindow* window;
	Camera* camera;
	Resources* res;
public:
	Drawable3D(sf::RenderWindow* window_, Camera* camera_, Resources* res_) 
	{ window = window_; camera = camera_; res = res_; }
	~Drawable3D();

	//объекты отрисовывают сами себя (этот метод вызывается из Update() у объекта)
	void Draw(); 
};

