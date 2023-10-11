#include "CollisionAvoidanceBehavior.h"

CollisionAvoidanceBehavior::CollisionAvoidanceBehavior()
{
}

CollisionAvoidanceBehavior::~CollisionAvoidanceBehavior()
{
}

Vector2D CollisionAvoidanceBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
	//TODO: Fer aquí el codi de collision avoidance
	return Vector2D();
}

Vector2D CollisionAvoidanceBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->position, dtime);
}
