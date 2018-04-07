#include "Robot.h"

Robot::Robot(glm::vec2 position, glm::vec2 size, Texture2D sprite, glm::vec3 color) : 
	GameObject(position, size, sprite, color) {

}

Robot::~Robot() {
}

void Robot::setPosition(glm::vec2 position) {
	Position.x = position.x;
	Position.y = position.y;
	std::cout << Position.x << ", " << Position.y << std::endl;
}

glm::vec2 Robot::getPosition() {
	return Position;
}

void Robot::draw(SpriteRenderer &renderer) {
	renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}
