#pragma once

#include <glm\glm.hpp>

#include "..\engine\include\GameObject.h"
#include "actions/Action.h";

class Card : public GameObject {
public:
	Card(std::string cardSymbol, glm::vec2 position, glm::vec2 size, Texture2D sprite, glm::vec3 color);
	~Card();
	void AddAction(Action *action);
	Action* GetAction();
	void ProcessMouseInput(GLdouble x, GLdouble y, GLboolean isButtonPressed);
	GLboolean getIsSelected();
	void SetIsSelected(bool isSelected);
	const std::string& GetSymbol();
private:
	GLboolean isSelected;
	GLboolean wasButtonPressedPreviously;
	std::string Symbol;
	Action *action;
};
