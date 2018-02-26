#pragma once
#include <SFML\Graphics.hpp>

class Drawable2D
{
	sf::RenderWindow* window;
public:
	Drawable2D(sf::RenderWindow* window_) { window = window_; }
	~Drawable2D();
	virtual void Draw() = 0;
};	

