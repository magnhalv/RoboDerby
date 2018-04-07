#pragma once

#include <vector>

#include "actions\Action.h"

class ActionContainer {
public:
	ActionContainer();
	~ActionContainer();

	void add(Action *action);
	void start();
	void update(GLfloat dt);	
	void clear();
	bool isCompleted();

private:
	std::vector<Action*>::iterator current_;
	std::vector<Action*> actions_;

};

