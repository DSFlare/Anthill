#include "AntStateMachine.h"

AntStateMachine::AntStateMachine()
{
}


AntStateMachine::~AntStateMachine()
{
}

void AntStateMachine::pushState(Function task) {
	if (task != this->getCurrentState())
		states.push(task);
}

Function AntStateMachine::getCurrentState() {
	return states.top();
}

void AntStateMachine::popState() {
	states.pop();
}

void AntStateMachine::update(Ant * ant)
{
	Function curr = getCurrentState();
	if (curr != NULL) {
		(ant->*curr)();
	}
}