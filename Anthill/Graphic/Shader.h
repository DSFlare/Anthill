#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>;

class Shader
{
public:
	unsigned int ID;

	// Идентификатор программы
	GLuint Program;

	void setFloat(const std::string &name, float value) const;

	// Конструктор считывает и собирает шейдер
	Shader() {} //для того чтобы статически объявлять без инициализации
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	// Использование программы
	void Use();
};