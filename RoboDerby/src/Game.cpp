#include "Game.h"

Game::Game(GLuint width, GLuint height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{}

Game::~Game()
{
	delete RectangleRenderer;
	delete TriangleRenderer;
	delete Board;
}

void Game::Init()
{
	// Load shaders
	ResourceManager::LoadShader("resources/shaders/sprite.vs", "resources/shaders/sprite.frag", nullptr, "sprite");

	//Load Textures
	ResourceManager::LoadTexture("resources/textures/background.jpg", GL_FALSE, "background");
	ResourceManager::LoadTexture("resources/textures/block_solid.png", GL_FALSE, "block_solid");
	ResourceManager::LoadTexture("resources/textures/block.png", GL_FALSE, "block");

	// Configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(Width), static_cast<GLfloat>(Height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("sprite", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

	//Create renderer
	auto spriteShader = ResourceManager::GetShader("sprite");
	TriangleRenderer = new SpriteRenderer(spriteShader, TRIANGLE);
	RectangleRenderer = new SpriteRenderer(spriteShader, RECTANGLE);

	auto robotTexture = ResourceManager::GetTexture("block");
	robot_ = new Robot(glm::vec2(0, 0), glm::vec2(50, 50), robotTexture, glm::vec3(0, 0.5f, 0.5f));

	Board = new GameBoard(); 
	Board->load("one", 50);
		
	actions_.add(new Move(*robot_, Board->getTile(2, 2)));
	actions_.add(new Move(*robot_, Board->getTile(5, 2)));
	actions_.add(new Move(*robot_, Board->getTile(1, 1)));
	actions_.start();
}

void Game::DoCollisions()
{
}

void Game::ProcessInput(GLfloat dt)
{
}

void Game::Update(GLfloat dt)
{
	actions_.update(dt);
}

void Game::Render()
{
	auto background = ResourceManager::GetTexture("background");
	RectangleRenderer->DrawSprite(background, glm::vec2(0, 0), glm::vec2(Width, Height), 0.0f);	
	Board->draw(*RectangleRenderer);	
	robot_->draw(*TriangleRenderer);
}
