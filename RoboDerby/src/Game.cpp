#include "Game.h"

Game::Game(GLuint width, GLuint height)
	: State(GAME_ACTIVE), Keys(), screenWidth_(width), screenHeight_(height)
{}

Game::~Game()
{
	delete RectangleRenderer;
	delete TriangleRenderer;
	delete Board;
	delete textRenderer_;
}

void Game::Init()
{
	// Load shaders
	ResourceManager::LoadShader("engine/shaders/sprite.vs", "engine/shaders/sprite.frag", nullptr, "sprite");
	ResourceManager::LoadShader("engine/shaders/character.vs", "engine/shaders/character.frag", nullptr, "character");

	//Load Textures
	ResourceManager::LoadTexture("resources/textures/background.jpg", GL_FALSE, "background");
	ResourceManager::LoadTexture("resources/textures/block_solid.png", GL_FALSE, "block_solid");
	ResourceManager::LoadTexture("resources/textures/block.png", GL_FALSE, "block");

	// Configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(screenWidth_), static_cast<GLfloat>(screenHeight_), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("sprite", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

	//Create renderer
	auto spriteShader = ResourceManager::GetShader("sprite");
	TriangleRenderer = new SpriteRenderer(spriteShader, TRIANGLE);
	RectangleRenderer = new SpriteRenderer(spriteShader, RECTANGLE);
	textRenderer_ = new TextRenderer(screenWidth_, screenHeight_);
	textRenderer_->init();
	


	auto blockTexture = ResourceManager::GetTexture("block");
	robots_.push_back(new Robot(glm::vec2(0, 0), glm::vec2(ROBOT_SIZE, ROBOT_SIZE), blockTexture, glm::vec3(0, 0.5f, 0.5f)));
	robots_.push_back(new Robot(glm::vec2(0, TILE_SIZE), glm::vec2(ROBOT_SIZE, ROBOT_SIZE), blockTexture, glm::vec3(0, 0.5f, 0.5f)));

	cards_.push_back(new Card(glm::vec2(0, TILE_SIZE), glm::vec2(CARD_HEIGHT, CARD_HEIGHT), blockTexture, glm::vec3(0.5f, 0.5f, 0.5f)));


	Board = new GameBoard(); 
	Board->load("one", TILE_SIZE);
	
	actions_.add(new Rotate(*robots_[1], 180.0f));
	actions_.add(new Push(*robots_[0], Board->getTile(0, 1), *robots_[1], Board->getTile(0, 2)));	
	actions_.start();
}

void Game::DoCollisions()
{
}

void Game::ProcessInput(GLfloat dt)
{
}

void Game::ProcessMouseInput(GLdouble x, GLdouble y) 
{
	for (auto card : cards_) {
		if (card->isInObject(x, y)) {
			card->setColor(glm::vec3(0.9f, 0.5f, 0.5f));
		}
		else {
			card->setColor(glm::vec3(0.5f, 0.5f, 0.5f));
		}
	}
}

void Game::Update(GLfloat dt)
{
	actions_.update(dt);
}

void Game::Render()
{
	auto background = ResourceManager::GetTexture("background");
	RectangleRenderer->DrawSprite(background, glm::vec2(0, 0), glm::vec2(screenWidth_, screenHeight_), 0.0f);	
	Board->draw(*RectangleRenderer);	

	for (auto robot : robots_) {
		robot->draw(*TriangleRenderer);
	}
	for (auto card : cards_) {
		card->draw(*RectangleRenderer);
	}

	
	auto shader = ResourceManager::GetShader("character");
	textRenderer_->renderText(shader, "This is sample text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
	textRenderer_->renderText(shader, "(C) LearnOpenGL.com", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));

}
