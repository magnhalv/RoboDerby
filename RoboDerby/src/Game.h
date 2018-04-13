#pragma once

#include "../engine/include/ResourceMananger.h"
#include "../engine/include/SpriteRenderer.h"
#include "GameBoard.h"
#include "Robot.h"
#include "actions\Move.h"
#include "actions\Rotate.h"
#include "actions\Action.h"
#include "actions\Push.h"
#include "ActionContainer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <tuple>

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game
{
public:
	GameState  State;
	GLboolean  Keys[1024];
	GLuint	   Width, Height;
	GLuint Level;

	SpriteRenderer *TriangleRenderer;
	SpriteRenderer *RectangleRenderer;
	GameBoard *Board;	

	Game(GLuint width, GLuint height);
	~Game();
	void Init();

	// Game loop
	void DoCollisions();
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
private:	
	std::vector<Robot*> robots_;	

	ActionContainer actions_;

	const GLuint TILE_SIZE = 50;
	const GLuint ROBOT_SIZE = 40;

};