#pragma once

#include "Action.h"
#include "../Robot.h"

class Rotate : public Action {
	Rotate(Robot &robot, GLfloat degrees); 
	~Rotate();

	void update();
	bool isComplete();

private:
	GLfloat final_;
	GLfloat current_;
	Robot &robot_;
};