#include "ForestObject.h"
#include "glm\glm.hpp"
#include "../Graphic/Camera.h"


ForestObject::ForestObject(sf::RenderWindow* window_, Camera* camera_, Resources* res_, Parametres* par_, std::vector<ForestObject*>* allObjects_,
	vec3 position_, vec3 rotation_, vec3 scale_)
	:window(window_), camera(camera_), res(res_), position(position_), rotation(rotation_),
		scale(scale_), allObjects(allObjects_), par(par_)
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

	auto it = std::find(allObjects->begin(), allObjects->end(), this);
	if (it != allObjects->end())
		allObjects->erase(it);
	delete this;
}

void ForestObject::Draw()
{
	if (isDrawn)
	{
		glm::mat4 view;
		view = camera->GetView();

		glm::mat4 projection;
		projection = camera->GetProjection();

		glm::mat4 modelMatrix;
		modelMatrix = glm::translate(modelMatrix, position);
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0, 0.0, 1.0));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
		modelMatrix = glm::scale(modelMatrix, scale);


		GLint modelLoc = glGetUniformLocation(shader->Program, "model");
		GLint viewLoc = glGetUniformLocation(shader->Program, "view");
		GLint projLoc = glGetUniformLocation(shader->Program, "projection");

		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));

		model->Draw(*shader);
	}
}

void ForestObject::SetParent(ForestObject * obj)
{
	parent = obj;
}

string ForestObject::GetTag()
{
	return tag;
}

bool ForestObject::isObjDrawn()
{
	return isDrawn;
}

void ForestObject::setDrawn(bool isDrawn_)
{
	isDrawn = isDrawn_;
}

void ForestObject::Update()
{
	if (parent != NULL)
	{
		position = parent->getPosition();
	}
}

void ForestObject::HiddenUpdate()
{

}