#pragma once
class Action {
public:
	Action();
	~Action();

	virtual void update() = 0;
	virtual bool isComplete() = 0;
};

