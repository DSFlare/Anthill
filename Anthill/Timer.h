#pragma once
#include <SFML/Graphics.hpp>

class Timer
{
private:
	static sf::Clock clock;
public:
	static float getTimeAsSec();
	static int getTimeAsMs();
	static long getTimeAsMicroS();
	Timer();
	~Timer();
};