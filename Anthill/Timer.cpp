#include "Timer.h"


sf::Clock Timer::clock;

int Timer::getTimeAsSec()
{
	return (int)clock.getElapsedTime().asSeconds();
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