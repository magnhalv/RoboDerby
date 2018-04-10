#include "GameBoard.h"

GameBoard::GameBoard() {
}

GameBoard::~GameBoard() {
}

void GameBoard::load(const std::string name, GLuint tileDim) {
	std::string path = "resources/levels/" + name + ".lvl";
	std::fstream levelFile(path);

	std::string line;

	std::vector<std::vector<GLuint>> tileData;

	if (levelFile) {
		while (std::getline(levelFile, line)) {
			std::istringstream sstream(line);
			std::vector<GLuint> row;
			GLuint tileCode;
			while (sstream >> tileCode) // Read each word seperated by spaces
				row.push_back(tileCode);
			tileData.push_back(row);
		}

		if (tileData.size() > 0) {
			init_(tileData, tileDim);
		}

	}
	else {
		//report error
	}
}

void GameBoard::draw(SpriteRenderer &renderer) {
	for (GameObject &tile : tiles_) {
		tile.draw(renderer);
	}
}

void GameBoard::init_(std::vector<std::vector<GLuint>> tiles, GLuint tileDim) {
	height_ = tiles.size();
	width_ = tiles[0].size();

	for (GLuint y = 0; y < height_; y++) {
		for (GLuint x = 0; x < width_; x++) {

			glm::vec2 pos(tileDim * x, tileDim * y);
			glm::vec2 size(tileDim, tileDim);

			GameObject obj(pos, size,
				ResourceManager::GetTexture("block_solid"),
				glm::vec3(0.8f, 0.8f, 0.7f)
			);

			tiles_.push_back(obj);
		}
	}
}
