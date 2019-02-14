#include "Card.h"

Card::Card(std::string symbol, glm::vec2 position, glm::vec2 size, Texture2D sprite, glm::vec3 color) :
	GameObject(position, size, sprite, color), Symbol(std::move(symbol)) {
	isSelected = false;
	wasButtonPressedPreviously = false;
}

Card::~Card() {
}

Action* Card::GetAction() {
	return action;
}

void Card::AddAction(Action *action) {
	this->action = action;
}

GLboolean Card::getIsSelected(){
	return this->isSelected;
}

void Card::SetIsSelected(bool isSelected) {
	this->isSelected = isSelected;
}

void Card::ProcessMouseInput(GLdouble x, GLdouble y, GLboolean isButtonPressed)
{
	if (isInObject(x, y)) {
		if (isButtonPressed && !wasButtonPressedPreviously) {
			isSelected = !isSelected;
		}
	}

	if (isSelected) {
		setColor(glm::vec3(0.5f, 1.0f, 0.5f));
	}	
	else if (isInObject(x, y)) {			
		setColor(glm::vec3(0.9f, 0.5f, 0.5f));		
	}
	else {
		setColor(glm::vec3(0.5f, 0.5f, 0.5f));
	}
	wasButtonPressedPreviously = isButtonPressed;
}

const std::string& Card::GetSymbol() {
	return Symbol;
}
