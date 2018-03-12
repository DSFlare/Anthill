#pragma once
#include <stack>
#include "../Objects/Animals/Ant.h"

typedef void(Ant::*Function)();

class AntStateMachine
{
private:
	std::stack<Function> states;	//���� ���������
public:
	AntStateMachine();
	~AntStateMachine();
	void pushState(Function task);

	Function getCurrentState();

	void popState();

	void update(Ant * ant);
};