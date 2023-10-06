#pragma once
#include "SteeringBehavior.h"

class Agent;

class SeparationBehavior : public SteeringBehavior
{
public:
    SeparationBehavior(float separationRadius);
    virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
};


