#include "ActionContainer.h"

ActionContainer::ActionContainer() : actions_(0) {
	current_ = actions_.begin();
}

ActionContainer::~ActionContainer() {

}

void ActionContainer::add(Action *action) {
	actions_.push_back(action);
}

void ActionContainer::start() {
	current_ = actions_.begin();
}

void ActionContainer::update(GLfloat dt) {
	if (isCompleted()) 
		return;
	
	if ((*current_)->isComplete())
		current_++;
	else
		(*current_)->update(dt);
}

void ActionContainer::clear() {
	actions_.clear();
	current_ = actions_.begin();
}

bool ActionContainer::isCompleted() {
	return current_ == actions_.end();
}


