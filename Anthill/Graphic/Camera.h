#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Objects/ForestObject.h"
//#include "../Time.h"

using glm::vec3;
using glm::mat4;

enum Camera_Movement {
	STAY,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	DOWN,
	UP
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float ROLL = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVTY = 0.1f;
const float ZOOM = 45.0f;

class Camera : public ForestObject
{
	// Camera options
	float movementSpeed;
	float mouseSensitivity;
	float zoom;
	int *windowWidth, *windowHeight;
	float FOV = 60;

	sf::RenderWindow* window;
	sf::Sprite screenCenter;

	//полезные матрицы
	mat4 viewMatrix;
	mat4 projectionMatrix;

	// движение
	bool up = false, down = false, left = false, right = false, forwardd = false, backward = false;
	float* deltaTime;
	int prevMouseX, prevMouseY;
	int mouseOffsetX, mouseOffsetY;

public:
	
	Camera(int* windowWidth_, int* windowHeight_, float* deltaTime_, sf::RenderWindow* window_); 
	void LookAt(vec3 position); // поворачивает камеру таким образом, что она смотрит на данный объект

	mat4 GetView() { return viewMatrix; }
	mat4 GetProjection() { return projectionMatrix; }

	virtual void HandleEvent(sf::Event e) override;
	virtual void Destroy() override;
	virtual void Update() override;
	
};

