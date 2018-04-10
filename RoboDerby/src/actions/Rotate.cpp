#include "Rotate.h"

Rotate::Rotate(Robot &robot, GLfloat degrees) : robot_(robot), final_(degrees), current_(0) {
	GLint direction = degrees < 0 ? 1 : -1;
	rotationVelocity_ = direction * 0.5f;	
}

Rotate::~Rotate() {
}

void Rotate::update(GLfloat dt) {
	if (isComplete()) return;	
	current_ += abs(rotationVelocity_);		
	robot_.setRotation(robot_.getRotation() + rotationVelocity_);
}

bool Rotate::isComplete() {
	return current_ >= final_;
}