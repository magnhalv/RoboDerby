#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Texture2D.h"
#include "SpriteRenderer.h"

class GameObject
{
public:
	GameObject();
	GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0,0));

	virtual void draw(SpriteRenderer &renderer);

	void setPosition(glm::vec2 position) { Position = position; }
	void setSize(glm::vec2 size) { Size = size; }
	void setVelocity(glm::vec2 velocity) { Velocity = velocity; }
	void setColor(glm::vec3 color) { Color = color; }
	void setRotation(GLfloat rotation) { Rotation = rotation; }

	glm::vec2 getPosition() { return Position; }
	glm::vec2 getSize() { return Size; }
	glm::vec2 getVelocity() { return Velocity; }
	glm::vec3 getColor() { return Color; }
	GLfloat getRotation() { return Rotation; }
private:
	glm::vec2   Position, Size, Velocity;
	glm::vec3   Color;
	GLfloat     Rotation;
	Texture2D   Sprite;
};
