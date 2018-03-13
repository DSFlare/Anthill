#include "Ant.h"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"


void Ant::Death()
{
}

void Ant::Update()
{
	//Organism::Update();
	(this->*action)();
	ForestObject::Draw();
}

Ant::Ant(Camera * camera_, Resources * res_, sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, window_, position_,  rotation_, scale_)
{
	shader = &(res->standartShader);
	texture = &(res->antTex);
	model = new Model3D(res->antModel, texture);

	Scout();
}

Ant::~Ant()
{
}

//движение

vec3 Ant::followTowards(vec3 target)
{
	vec3 steering = glm::normalize(target - position) * maxVelosity - velosity;
	if (glm::length(steering) > maxForce)
	{
		steering = glm::normalize(steering) * maxForce;
	}
	float a = maxForce;
	a = maxVelosity;
	return steering;
}


//методы scout

void Ant::Scout()	//стартовый
{
	velosity = vec3(maxVelosity, 0, 0);
	glm::rotateY(velosity, (rand() % 360) * 1.0f);
	action = action = &Ant::explore;
}

void Ant::explore()
{
	changeDirTimer++;
	if (changeDirTimer > 5)
	{
		changeDirTimer = 0;
		vec3 circlePos = position + glm::normalize(velosity) * circkeDistance;
		vec3 target = circlePos + glm::rotateY(vec3(circleRadius, 0, 0), (rand() % 360) * 1.0f);
		acceler = followTowards(target);

		velosity += acceler;
	}
	if (glm::length(velosity) > maxVelosity)
	{
		velosity = glm::normalize(velosity) * maxVelosity;
	}
	position += velosity;

	if (velosity.z < 0)
	{
		rotation.y = glm::degrees(acos(glm::dot(vec3(1, 0, 0), velosity) / glm::length(velosity)));
	}
	else
	{
		rotation.y = 360 - glm::degrees(acos(glm::dot(vec3(1, 0, 0), velosity) / glm::length(velosity)));
	}
}
