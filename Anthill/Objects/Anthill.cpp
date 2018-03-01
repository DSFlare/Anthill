#include "Anthill.h"


Anthill::Anthill(sf::RenderWindow * window_, Camera * camera_, Resources * res_)
	:Drawable3D(window_, camera_, res_, &position, &rotation, &scale)
{
	shader = &(res->standartShader);
	texture = &(res->anthillTex);
	model = new Model3D(res->anthillModel, texture);
}

Anthill::~Anthill()
{
}

void Anthill::Update()
{
	glm::mat4 view;
	view = camera->GetView();

	glm::mat4 projection;
	projection = camera->GetProjection();

	glm::mat4 modelMatrix;
	modelMatrix = glm::translate(modelMatrix, getPosition());
	modelMatrix = glm::scale(modelMatrix, getScale());

	GLint modelLoc = glGetUniformLocation(shader->Program, "model");
	GLint viewLoc = glGetUniformLocation(shader->Program, "view");
	GLint projLoc = glGetUniformLocation(shader->Program, "projection");

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	model->Draw(*shader);
}
