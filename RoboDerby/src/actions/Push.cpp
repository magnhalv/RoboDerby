#include "Push.h"

Push::Push(Robot &pushee, GameObject &pusheeDestination, Robot &pushed, GameObject &pushedDestination) 
	: pushee_(pushee), pusheeDestination_(pusheeDestination), pushed_(pushed), pushedDestination_(pushedDestination) {
	reachedContact_ = false;
}

Push::~Push() {
}

void Push::update(GLfloat dt) {	
	moveRobot_(pushee_, pusheeDestination_, dt);
	moveRobot_(pushed_, pushedDestination_, dt);
}

bool Push::isComplete() {
	return pushee_.getPosition() == pusheeDestination_.getPosition() 
		&& pushed_.getPosition() == pushedDestination_.getPosition();
}

void Push::moveRobot_(Robot &robot, GameObject &tile, GLfloat dt) {
	glm::vec2 velocity(50.0f*dt, 50.0f*dt);

	glm::vec2 diff = robot.getPosition() - tile.getPosition();

	velocity = glm::min(velocity, glm::abs(diff));

	glm::vec2 direction(diff.x < 0 ? 1 : -1, diff.y < 0 ? 1 : -1);

	velocity.x = direction.x*velocity.x;
	velocity.y = direction.y*velocity.y;

	glm::vec2 newPos = robot.getPosition() + velocity;
	robot.setPosition(newPos);
}