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
	std::string antModel;
	std::string queenModel;
	std::string catherpillarModel;
	std::string beetleModel;

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

	//���������
	sf::Sprite button;
	sf::Sprite textfield;
	sf::Sprite anthillSprite;

	//�����
	sf::Sound music;
	sf::Sound warSound;

	//�������
	Shader standartShader;
	Shader selectedShader; //��� ��������, �� ������� �������� �����������

	void LoadTextures(string dirt, string wood, string ant, string queen, string cath, string beetle,
					  string leaf, string stick, string anthill);
	void LoadShaders(string vertexSTD, string fragmentSTD, string vertexSelected, string fragmentSelected);

	Resources();
	~Resources();
};

