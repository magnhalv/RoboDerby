#pragma once

#include <glm\glm.hpp>

#include "..\engine\include\GameObject.h"

class Card : public GameObject {
public:
	Card(glm::vec2 position, glm::vec2 size, Texture2D sprite, glm::vec3 color);
	~Card();
};
