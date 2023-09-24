#include "SeekBehavior.h"

SeekBehavior::SeekBehavior()
{
}

SeekBehavior::~SeekBehavior()
{
}

Vector2D SeekBehavior::CalculateForce(Agent* agent, Vector2D target, float dtime)
{
	//Desired velocity
	Vector2D desiredVelocity = target - agent->getPosition();
	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();

	//Steering force, without acceleration
	Vector2D steeringForce = (desiredVelocity - agent->getVelocity());
	steeringForce /= agent->getMaxVelocity();

	//Steering force, with acceleration
	steeringForce /= agent->getMass();

	return steeringForce * agent->getMaxForce();
}

Vector2D SeekBehavior::CalculateForce(Agent* agent, Agent* target, float dtime)
{
	return CalculateForce(agent, target->getPosition(), dtime);
}
