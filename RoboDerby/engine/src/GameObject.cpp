#include "../include/GameObject.h"

GameObject::GameObject()
	: Position(0, 0), Size(1, 1), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite() { }

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity)
	: Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite) { }

void GameObject::draw(SpriteRenderer &renderer)
{
	renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}

GLboolean GameObject::isInObject(GLdouble x, GLdouble y)
{
	GLboolean isWithinX = ((x >= Position.x) && (x <= (Position.x + Size.x)));
	GLboolean isWithinY = y >= Position.y && y <= (Position.y + Size.y);	
	return isWithinX && isWithinY;
}
