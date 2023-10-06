#include "CohesionBehavior.h"
#include "Agent.h"

CohesionBehavior::CohesionBehavior()
{
    // Additional initialization code if needed
}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D centerOfMass;
    int agentCount = 0;

    for (Agent* neighbor : agent->getNeighbors())
    {
        // Calculate distance to neighbor
        float distance = Vector2D::Distance(agent->getPosition(), neighbor->getPosition());

        // Check if the neighbor is within the cohesion radius
        if (distance > 0 && distance < agent->getCohesionRadius())
        {
            centerOfMass += neighbor->getPosition();
            agentCount++;
        }
    }

    if (agentCount > 0)
    {
        centerOfMass /= agentCount;

        // Calculate the steering force towards the center of mass
        Vector2D cohesionForce = (centerOfMass - agent->getPosition()).Normalize() * agent->getMaxForce();
        return cohesionForce;
    }

    return Vector2D(0, 0);
}

Vector2D CohesionBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}

