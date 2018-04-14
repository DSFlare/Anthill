#include "Timer.h"


sf::Clock Timer::clock;

float Timer::getTimeAsSec()
{
	return clock.getElapsedTime().asSeconds();
}

int Timer::getTimeAsMs()
{
	return clock.getElapsedTime().asMilliseconds();
}

long Timer::getTimeAsMicroS()
{
	return clock.getElapsedTime().asMicroseconds();
}

Timer::Timer()
{
}


Timer::~Timer()
{
}
