#pragma once
#include "SteeringBehavior.h"

class SeekBehavior : public SteeringBehavior
{
public:
	SeekBehavior();
	~SeekBehavior();
	virtual Vector2D CalculateForce(Agent* agent, Vector2D target, float dtime) override;
	virtual Vector2D CalculateForce(Agent* agent, Agent* target, float dtime) override;
};