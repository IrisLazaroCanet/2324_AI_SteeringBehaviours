#pragma once
#include "SteeringBehavior.h"
#include <vector>

class PriorityBlendingBehavior : public SteeringBehavior
{
public:
    PriorityBlendingBehavior(std::initializer_list<SteeringBehavior*> behaviors);
    ~PriorityBlendingBehavior();

    virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
    virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;

    SteeringBehavior* getBehavior(int index) const { return behaviors[index]; }

private:
    std::vector<SteeringBehavior*> behaviors;
    float threshold; // Threshold value for behavior force
};


