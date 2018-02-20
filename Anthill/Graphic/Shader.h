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

	// ������������� ���������
	GLuint Program;

	void setFloat(const std::string &name, float value) const;

	// ����������� ��������� � �������� ������
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	// ������������� ���������
	void Use();
};