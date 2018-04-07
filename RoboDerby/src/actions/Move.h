#pragma once

#include <cmath>

#include "../Robot.h"
#include "../../engine/include/GameObject.h"

class Move {
public:
	Move(Robot &robot, GameObject &tile);
	~Move();

	void update(GLfloat dt);
	bool isComplete();
private:
	Robot &robot_;
	GameObject tile_;
};

