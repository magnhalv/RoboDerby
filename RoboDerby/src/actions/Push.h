#pragma once

#include <math.h>

#include "Action.h"
#include "../Robot.h"

class Push : public Action {
public:
	Push(Robot &pushee, GameObject &pusheeDestination, Robot &pushed, GameObject &pushedDestination);
	~Push();

	void update(GLfloat dt);
	bool isComplete();

private:
	Robot & pushee_, &pushed_;
	GameObject &pusheeDestination_, &pushedDestination_;
	bool reachedContact_;

	void moveRobot_(Robot &robot, GameObject &tile, GLfloat dt);
};