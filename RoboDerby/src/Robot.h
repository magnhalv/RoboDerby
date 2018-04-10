#pragma once

#include <glm\glm.hpp>

#include "..\engine\include\GameObject.h"

class Robot : public GameObject {
public:
	Robot(glm::vec2 position, glm::vec2 size, Texture2D sprite, glm::vec3 color);
	~Robot();	
};

