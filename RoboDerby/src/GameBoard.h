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

	void load(const std::string name, GLuint tileDim);
	void draw(SpriteRenderer &renderer);

	std::vector<GameObject> tiles_;
	const GLuint TILE_DIM = 40;

	GLuint getWidth() { return width_; }
	GLuint getHeight() { return height_; }

private:

	GLuint width_;
	GLuint height_;

	void init_(std::vector<std::vector<GLuint>> tiles, GLuint tileDim);
};

