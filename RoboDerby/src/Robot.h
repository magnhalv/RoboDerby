#pragma once

#include <glm\glm.hpp>

#include "..\engine\include\GameObject.h"

class Robot : GameObject {
public:
	Robot(glm::vec2 position, glm::vec2 size, Texture2D sprite, glm::vec3 color);
	~Robot();	

	void setPosition(glm::vec2 position);
	glm::vec2 getPosition();
	void draw(SpriteRenderer &renderer);
};

