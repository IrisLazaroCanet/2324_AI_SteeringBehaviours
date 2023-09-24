#include "SeekBehavior.h"

SeekBehavior::SeekBehavior() : SteeringBehavior()
{
}

SeekBehavior::~SeekBehavior()
{
}

Vector2D SeekBehavior::CalculateForce(Agent* agent, Vector2D target, float dtime)
{
	//Desired velocity
	Vector2D desiredVelocity = target - agent->position;
	desiredVelocity.Normalize();
	desiredVelocity *= agent->max_velocity;

	//Steering force, without acceleration
	Vector2D steeringForce = (desiredVelocity - agent->velocity);
	steeringForce /= agent->max_velocity;

	//Steering force, with acceleration
	steeringForce /= agent->mass;

	return steeringForce * agent->max_force;
}

Vector2D SeekBehavior::CalculateForce(Agent* agent, Agent* target, float dtime)
{
	return Seek(agent, target->position, dtime);
}
