#include "Rotate.h"

Rotate::Rotate(Robot &robot, GLfloat degrees) : robot_(robot), final_(degrees), current_(0) {
	clockwise = degrees < 0;

	final_ = robot.getRotation() + degrees;

}

Rotate::~Rotate() {
}

void Rotate::update() {
}

bool Rotate::isComplete() {
}