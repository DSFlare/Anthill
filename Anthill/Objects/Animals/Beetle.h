#pragma once
#include "Organism.h"
class Beetle :
	public Organism
{
private:
	int changeDirTimer = 0;
	void(Beetle::*action)();	//функци€, выполн€юща€с€ каждый кадр
	Organism* target = NULL;
public:
	Beetle(Camera * camera_, Resources * res_, Parametres* par_, std::vector<ForestObject*>* allObjects_, 
		sf::RenderWindow * window_,
		vec3 position_ = vec3(0, 0, 0),
		vec3 rotation_ = vec3(0, 0, 0),
		vec3 scale_ = vec3(0.1, 0.1, 0.1));
	virtual void Destroy() override;
	virtual void Update() override;
	~Beetle();

private:
	vec3 followTowards(vec3 target);
	void checkAnts();
	void explore();
	void fight();
};