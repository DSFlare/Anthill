#include "Drawable3D.h"


Drawable3D::Drawable3D(sf::RenderWindow * window_, Camera * camera_, Resources * res_, vec3 *position_, vec3 *rotation_, vec3 *scale_)
	:window(window_), camera(camera_), res(res_), positionFO(position_), rotationFO(rotation_), scaleFO(scale_)
{
}

Drawable3D::~Drawable3D()
{
}

void Drawable3D::Draw()
{
	glm::mat4 view;
	view = camera->GetView();

	glm::mat4 projection;
	projection = camera->GetProjection();
	
	glm::mat4 modelMatrix;
	modelMatrix = glm::translate(modelMatrix, *positionFO);
//	modelMatrix = glm::rotate(modelMatrix, 10.0f,  *rotationFO);
	modelMatrix = glm::scale(modelMatrix, *scaleFO);

	vec3 *pos = positionFO;
	vec3 *pos1 = rotationFO;
	vec3 *pos2 = scaleFO;
	GLint modelLoc = glGetUniformLocation(shader->Program, "model");
	GLint viewLoc = glGetUniformLocation(shader->Program, "view");
	GLint projLoc = glGetUniformLocation(shader->Program, "projection");

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	model->Draw(*shader);
}
