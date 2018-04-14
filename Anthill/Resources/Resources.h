#pragma once
#include "../Graphic/Model3D.h"
#include "../Graphic/Shader.h"
#include <SFML/Audio/Sound.hpp>
#include <string>
#include "SFML\Graphics.hpp"

using std::string;

class Resources
{
public:

	//������
	char * antModel;
	char * queenModel;
	char * catherpillarModel;
	char * beetleModel;
	char * anthillModel;
	char * leafModel;
	char * stickModel;
	char * fenceModel;

	//��������
	sf::Texture testTex;
	sf::Texture dirtTex;
	sf::Texture woodTex;
	sf::Texture antTex;
	sf::Texture queenTex;
	sf::Texture catherpillarTex;
	sf::Texture beetleTex;
	sf::Texture leafTex;
	sf::Texture stickTex;
	sf::Texture anthillTex;
	sf::Texture fenceTex;

	//���������
	sf::Texture button;
	sf::Texture textfield;
	sf::Texture anthillSprite;
	sf::Texture screenCenter;
	sf::Texture hotkeys;
	sf::Font anthillFontNumbers;

	//�����
	sf::Sound music;
	sf::Sound warSound;

	//�������
	Shader standartShader;
	Shader selectedShader; //��� ��������, �� ������� �������� �����������

	void LoadTextures(string dirt, string wood, string ant, string queen, string cath, string beetle,
					  string leaf, string stick, string anthill, string fence);
	void LoadShaders(string vertexSTD, string fragmentSTD, string vertexSelected, string fragmentSelected);

	void LoadModels(char * ant, char * queen, char * catherpillar, char * beetle, char * anthill, char * leaf, char * stick, char * fence);

	void LoadFonts(string uiAnthillNumbers);

	Resources();
	~Resources();
};