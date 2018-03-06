#include "ForestObject.h"
#include "glm\glm.hpp"


ForestObject::ForestObject(sf::RenderWindow* window_, Camera* camera_, Resources* res_,
	vec3 position_ = vec3(0, 0, 0),
	vec3 rotation_ = vec3(0, 0, 0),
	vec3 scale_ = vec3(1, 1, 1))
	:window(window_), camera(camera_), res(res_), position(position_), rotation(rotation_), scale(scale_)
{
}

ForestObject::ForestObject(sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:window(window_), position(position_), rotation(rotation_), scale(scale_)
{
}

ForestObject::~ForestObject()
{
}

void ForestObject::HandleEvent(sf::Event e)
{
}

void ForestObject::Destroy()
{
}

void ForestObject::Draw()
{
	glm::mat4 view;
	view = camera->GetView();

	glm::mat4 projection;
	projection = camera->GetProjection();

	glm::mat4 modelMatrix;
	modelMatrix = glm::translate(modelMatrix, position);
	//	modelMatrix = glm::rotate(modelMatrix, 10.0f,  *rotationFO);
	modelMatrix = glm::scale(modelMatrix, scale);


	GLint modelLoc = glGetUniformLocation(shader->Program, "model");
	GLint viewLoc = glGetUniformLocation(shader->Program, "view");
	GLint projLoc = glGetUniformLocation(shader->Program, "projection");

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	model->Draw(*shader);
}

void ForestObject::SetParent(ForestObject * obj)
{
	parent = obj;
}

void ForestObject::Update()
{

}

void ForestObject::HiddenUpdate()
{

}