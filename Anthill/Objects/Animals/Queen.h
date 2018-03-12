#pragma once
#include "Ant.h"
class Queen :
	public Ant
{
private:
public:
	Queen(Camera * camera_, Resources * res_, sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(1, 1, 1));
	virtual void Update() override;
	~Queen();

};

