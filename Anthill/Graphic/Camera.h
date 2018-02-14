#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../ForestObject.h"

using glm::vec3;

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
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
public:
	
	void LookAt(vec3 position); // ������������ ������ ����� �������, ��� ��� ������� �� ������ ������

	virtual void HandleEvent(sf::Event e) override;
	virtual void Destroy() override;
	virtual void Update() override;
	
};

