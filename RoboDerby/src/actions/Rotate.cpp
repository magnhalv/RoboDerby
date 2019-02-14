#include "Rotate.h"

Rotate::Rotate(Robot &robot, GLfloat degrees) : robot_(robot), final_(abs(degrees)), current_(0) {
	GLint direction = degrees < 0 ? 1 : -1;
	rotationVelocity_ = direction * 120.0f;	
}

Rotate::~Rotate() {
}

void Rotate::update(GLfloat dt) {
	if (isComplete()) return;	
	current_ += abs(rotationVelocity_*dt);		
	robot_.setRotation(robot_.getRotation() + (rotationVelocity_*dt));
}

bool Rotate::isComplete() {
	return current_ >= final_;
}