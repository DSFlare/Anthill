#include "Landscape.h"
#include "../Graphic/Camera.h"
using namespace glm;

Landscape::Landscape(sf::RenderWindow * window_, Camera * camera_, Resources * res_, int landscapeWidth, int landscapeHeight)
	:ForestObject(window_, camera_, res_)
{
	float vertices[] = {
		-landscapeWidth, -landscapeHeight, -0.0f,  0.0f, 0.0f,
		landscapeWidth, -landscapeHeight, -0.0f,  landscapeWidth, 0.0f,
		landscapeWidth,  landscapeHeight, -0.0f,  landscapeWidth, landscapeHeight,
		landscapeWidth,  landscapeHeight, -0.0f,  landscapeWidth, landscapeHeight,
		-landscapeWidth,  landscapeHeight, -0.0f,  0.0f, landscapeHeight,
		-landscapeWidth, -landscapeHeight, -0.0f,  0.0f, 0.0f
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// Атрибут с координатами
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Атрибут с текстурными координатами
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	//Отвязываем VAO [И VBO!!!!!!!!!!!!!!!!] и все готово
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	shader = &(res->standartShader);
	texture = &(res->dirtTex);
	texture->generateMipmap();
	texture->setSmooth(true);
	texture->setRepeated(true);
}

Landscape::~Landscape()
{

}

void Landscape::Update()
{
	shader->Use();
	mat4 model = glm::translate(mat4(), getPosition());
	vec3 rot = getRotation();
	model = glm::rotate(model, glm::radians(rot.x), vec3(1, 0, 0));
	model = glm::rotate(model, glm::radians(rot.y), vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(rot.z), vec3(0, 0, 1));
	mat4 view = camera->GetView();
	mat4 proj = camera->GetProjection();

	sf::Texture::bind(texture);
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "projection"), 1, GL_FALSE, glm::value_ptr(proj));
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}
