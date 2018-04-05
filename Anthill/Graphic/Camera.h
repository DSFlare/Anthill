#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Objects/ForestObject.h"

using glm::vec3;
using glm::mat4;

class Camera : public ForestObject
{
	// Camera options
	float movementSpeed;
	float mouseSensitivity;
	float zoom;
	int *windowWidth, *windowHeight;
	float FOV = 60;

	//sf::RenderWindow* window;
	sf::Sprite screenCenter;

	//полезные матрицы
	mat4 viewMatrix;
	mat4 projectionMatrix;

	// движение
	bool up = false, down = false, left = false, right = false, forwardd = false, backward = false;
	float* deltaTime;
	int prevMouseX, prevMouseY;
	int mouseOffsetX, mouseOffsetY;
	int mouseWheelDelta;

public:
	
	Camera(int* windowWidth_, int* windowHeight_, float* deltaTime_, sf::RenderWindow* window_, Parametres* par_,
		std::vector<ForestObject*>* allObjects_ );
	void lookAt(vec3 position); // поворачивает камеру таким образом, что она смотрит на данный объект

	mat4 getView() { return viewMatrix; }
	mat4 getProjection() { return projectionMatrix; }

	virtual void HandleEvent(sf::Event e) override;
	virtual void Destroy() override;
	virtual void Update() override;
	
};