#include "GameBoard.h"

GameBoard::GameBoard() {
}

GameBoard::~GameBoard() {
}

void GameBoard::Load(const std::string name, GLuint tileDim) {
	std::string path = "resources/levels/" + name + ".lvl";
	std::fstream levelFile(path);

	std::string line;

	std::vector<std::vector<GLuint>> tileData;

	if (levelFile) {
		while (std::getline(levelFile, line)) {
			std::cout << line << std::endl;
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

void GameBoard::Draw(SpriteRenderer &renderer) {
	for (GameObject &tile : Tiles) {
		tile.Draw(renderer);
	}
}

void GameBoard::init_(std::vector<std::vector<GLuint>> tiles, GLuint tileDim) {
	GLuint height = tiles.size();
	GLuint width = tiles[0].size();

	for (GLuint y = 0; y < height; y++) {
		for (GLuint x = 0; x < width; x++) {

			glm::vec2 pos(tileDim * x, tileDim * y);
			glm::vec2 size(tileDim, tileDim);

			GameObject obj(pos, size,
				ResourceManager::GetTexture("block_solid"),
				glm::vec3(0.8f, 0.8f, 0.7f)
			);

			Tiles.push_back(obj);
		}
	}
}
