#include "Move.h"

Move::Move(Robot &robot, GameObject &tile) : robot_(robot), tile_(tile) {

}

Move::~Move() {
}

void Move::update(GLfloat dt) {

	GLfloat velocityX = 5.0f;

	GLfloat diff = robot_.getPosition().x - tile_.Position.x;

	GLfloat diffX = abs(diff);
	bool left = diff > 0.0f;

	if (diffX < velocityX)
		velocityX = diffX;

	if (left)
		velocityX *= -1.0f;

	GLfloat newX = robot_.getPosition().x + velocityX;
	
	//x
	GLfloat velocityY = 5.0f;

	diff = robot_.getPosition().y - tile_.Position.y;

	GLfloat diffY = abs(diff);
	left = diff > 0.0f;

	if (diffY < velocityY)
		velocityY = diffY;

	if (left)
		velocityY *= -1.0f;

	GLfloat newY = robot_.getPosition().y + velocityY;


	glm::vec2 newPos(newX, newY);
	robot_.setPosition(newPos);
}

bool Move::isComplete() {	
	return robot_.getPosition() == tile_.Position;
}
