#pragma once

#include <math.h>

#include "Action.h"
#include "../Robot.h"

class Rotate : public Action {
public:
	Rotate(Robot &robot, GLfloat degrees); 
	~Rotate();

	void update(GLfloat dt);
	bool isComplete();

private:
	GLfloat rotationVelocity_;
	GLfloat final_, current_;
	Robot &robot_;
};