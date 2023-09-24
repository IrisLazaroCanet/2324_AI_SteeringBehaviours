#pragma once
#include "Agent.h"
#include "Vector2D.h"

class SteeringBehavior
{
public:
	virtual Vector2D CalculateForce(Agent* agent, Vector2D target, float dtime) = 0;
	virtual Vector2D CalculateForce(Agent* agent, Agent* target, float dtime) = 0;
};
