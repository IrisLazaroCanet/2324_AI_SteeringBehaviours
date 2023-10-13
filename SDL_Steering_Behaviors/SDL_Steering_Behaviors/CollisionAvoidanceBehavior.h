#pragma once
#include "SteeringBehavior.h"

class Agent;

class CollisionAvoidanceBehavior : public SteeringBehavior
{
public:

	// Define a struct to represent obstacles
	struct Obstacle
	{
		Vector2D position;

		Obstacle(Vector2D pos) : position(pos) {}
	};

	//Constructors and Deconstructors
	CollisionAvoidanceBehavior();
	CollisionAvoidanceBehavior(const std::vector<Obstacle>& obstacles, float coneHalfAngle, float coneDistance);
	~CollisionAvoidanceBehavior();

	//Setters
	void SetObstacles(const std::vector<Obstacle>& obstacles);
	void SetConeValues(float coneHalfAngle, float coneDistance);

	/// Override the CalculateForces function for targeting a Vector2D
	virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	// Override the CalculateForces function for targeting another Agent
	virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;

private:
	float coneHalfAngle;
	float coneDistance;
	// List of obstacles
	std::vector<Obstacle> obstacles;
};