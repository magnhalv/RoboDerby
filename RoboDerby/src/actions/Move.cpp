#include "Move.h"

Move::Move(Robot &robot, GameObject &tile) : robot_(robot), tile_(tile) {

}

Move::~Move() {
}

void Move::update(GLfloat dt) {

	glm::vec2 velocity(50.0f*dt, 50.0f*dt);

	glm::vec2 diff = robot_.getPosition() - tile_.getPosition();

	velocity = glm::min(velocity, glm::abs(diff));

	glm::vec2 direction(diff.x < 0 ? 1 : -1, diff.y < 0 ? 1 : -1);

	velocity.x = direction.x*velocity.x;
	velocity.y = direction.y*velocity.y;

	glm::vec2 newPos = robot_.getPosition() + velocity;
	robot_.setPosition(newPos);
}

bool Move::isComplete() {	
	return robot_.getPosition() == tile_.getPosition();
}
