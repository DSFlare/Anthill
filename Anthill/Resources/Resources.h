#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "../Graphic/Shader.h"

namespace resources
{
	//static void loadTextures();
	/*
	namespace textures
	{
		sf::Texture ant;
		sf::Texture queen;
		sf::Texture caterpillar;
		sf::Texture beetle;
		sf::Texture anthill;

		sf::Texture stick;
		sf::Texture leaf;

	}*/

	namespace audio
	{

	}

	namespace models
	{

	}

	namespace gui
	{

	}

	namespace shaders
	{
		GLchar anthill_vertex[] = "Resources\\land_vertex.glsl";
		GLchar anthill_fragment[] = "Resources\\land_fragment.glsl";

	}
}
