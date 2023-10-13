////SceneFlockingCollisionAvoidance.h
#pragma once
#include <vector>
#include "Scene.h"
#include "Agent.h"

#include "FlockingBehavior.h"
#include "CollisionAvoidanceBehavior.h"

struct TweakableValues
{
	float coneHalfAngle;
	float coneDistance;
};

class SceneFlockingCollisionAvoidance : public Scene
{
public:
	SceneFlockingCollisionAvoidance(int agentAmount);
	~SceneFlockingCollisionAvoidance();
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();

private:
	void UpdateConeHalfAngle(float increment);
	void UpdateAgentValues(int index);
	std::vector<Agent*> agents;
	Vector2D target;
	std::vector<CollisionAvoidanceBehavior::Obstacle> obstacles;
	TweakableValues tweakableValues;
};