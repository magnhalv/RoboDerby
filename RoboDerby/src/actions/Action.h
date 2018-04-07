#pragma once

#include <glad\glad.h>

class Action {
public:
	Action() {};
	~Action() {};

	virtual void update(GLfloat dt) = 0;
	virtual bool isComplete() = 0;
};

