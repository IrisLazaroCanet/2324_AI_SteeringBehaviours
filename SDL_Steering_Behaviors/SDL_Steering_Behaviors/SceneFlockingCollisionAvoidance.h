#pragma once
#include <vector>
#include "Scene.h"
#include "Agent.h"

#include "FlockingBehavior.h"
#include "CollisionAvoidanceBehavior.h"

class SceneFlockingCollisionAvoidance : public Scene
{
public:
	SceneFlockingCollisionAvoidance(int agentAmount);
	~SceneFlockingCollisionAvoidance();
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();

private:
	std::vector<Agent*> agents;
	Vector2D target;
};