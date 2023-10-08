#include "AllignmentBehavior.h"

AlignmentBehavior::AlignmentBehavior()
{
    // Additional initialization code if needed
}

Vector2D AlignmentBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D averageVelocity;
    int agentCount = 0;

    for (Agent* neighbor : agent->getNeighbors())
    {
        // Calculate distance to neighbor
        float distance = Vector2D::Distance(agent->getPosition(), neighbor->getPosition());

        // Check if the neighbor is within the alignment radius
        if (distance > 0 && distance < agent->getAlignmentRadius())
        {
            averageVelocity += neighbor->getVelocity();
            agentCount++;
        }
    }

    if (agentCount > 0)
    {
        averageVelocity /= agentCount;

        // Calculate the steering force towards the average velocity
        Vector2D alignmentForce = (averageVelocity - agent->getVelocity()).Normalize() * 2000;
        std::cout << alignmentForce.x << alignmentForce.y << std::endl;
        return alignmentForce;
    }

    return Vector2D(0, 0);
}

Vector2D AlignmentBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}