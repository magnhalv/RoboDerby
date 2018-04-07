#pragma once

#include <string>
#include <vector>
#include <glad\glad.h>

#include "engine\include\GameObject.h"


class GameBoard
{
public:
	GameBoard();
	~GameBoard();

	void Load(const std::string name, GLint screenWidth, GLint screenHeight);

	std::vector<GameObject> Bricks;
};

