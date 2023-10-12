#pragma once
#include "SteeringBehavior.h"
//#include "Agent.h"

//CollisionAvoidanceBehaviour.h
class Agent;

class CollisionAvoidanceBehavior : public SteeringBehavior
{
public:
	CollisionAvoidanceBehavior();
	~CollisionAvoidanceBehavior();

	// Define a struct to represent obstacles
	struct Obstacle
	{
		Vector2D position;

		Obstacle(Vector2D pos) : position(pos) {}
	};

	void setObstacles(const std::vector<Obstacle>& obstacles);

	virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;


	// List of obstacles
	std::vector<Obstacle> obstacles;
};