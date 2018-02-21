#include "Ant.h"



void Ant::Death()
{
}

void Ant::Update()
{
	glm::mat4 view;
	view = camera->GetView();

	glm::mat4 projection;
	projection = camera->GetProjection();

	glm::mat4 modelMatrix;
	modelMatrix = glm::translate(modelMatrix, getPosition());

	GLint modelLoc = glGetUniformLocation(shader->Program, "model");
	GLint viewLoc = glGetUniformLocation(shader->Program, "view");
	GLint projLoc = glGetUniformLocation(shader->Program, "projection");

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	model->Draw(*shader);
	
}

Role * Ant::getRole()
{
	return role;
}

Ant::Ant(Camera * camera_, Resources * res_, sf::RenderWindow * window_, vec3 position_, vec3 rotation_, vec3 scale_)
	:Organism(camera_, res_, window_, position_,  rotation_, scale_)
{
	shader = &(res->standartShader);
	model = new Model3D(res->antModel);
}


Ant::~Ant()
{
}
