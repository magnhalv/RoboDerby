#pragma once

#include <string>
#include <vector>
#include <glad\glad.h>

#include "..\engine\include\GameObject.h"
#include "..\engine\include\ResourceMananger.h"


class GameBoard
{
public:
	GameBoard();
	~GameBoard();

	void Load(const std::string name, GLuint tileDim);
	void Draw(SpriteRenderer &renderer);

	std::vector<GameObject> Tiles;
	const GLuint TILE_DIM = 40;

private:
	void init_(std::vector<std::vector<GLuint>> tiles, GLuint tileDim);
};

