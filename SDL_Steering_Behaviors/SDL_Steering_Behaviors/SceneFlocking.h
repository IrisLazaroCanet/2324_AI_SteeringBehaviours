#pragma once
#include <vector>
#include "Scene.h"
#include "Agent.h"

//Include behaviors

class SceneFlocking : public Scene
{
public:
	SceneFlocking(int agentAmount);
	~SceneFlocking();
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();

private:
	std::vector<Agent*> agents;
	Vector2D target;
};