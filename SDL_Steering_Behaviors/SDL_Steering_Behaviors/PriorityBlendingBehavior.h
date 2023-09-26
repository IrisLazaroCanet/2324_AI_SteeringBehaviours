#pragma once
#include "SteeringBehavior.h"
#include <vector>

class PriorityBlendingBehavior : public SteeringBehavior
{
public:
    PriorityBlendingBehavior(std::initializer_list<SteeringBehavior*> behaviors);
    ~PriorityBlendingBehavior();

    Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;

private:
    std::vector<SteeringBehavior*> behaviors;
};


