#pragma once

#include "../engine/include/ResourceMananger.h"
#include "../engine/include/SpriteRenderer.h"
#include "GameBoard.h"
#include "Robot.h"
#include "actions\Move.h"
#include "actions\Action.h"

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
	Robot * robot_;	

	GLboolean actionsCompleted_;
	GLuint currentActionIndex_;
	std::vector<Action*> actions_;

};