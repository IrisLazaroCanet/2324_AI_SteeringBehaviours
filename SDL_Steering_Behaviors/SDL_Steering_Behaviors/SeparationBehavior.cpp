#include "SeparationBehavior.h"
#include "Agent.h"

SeparationBehavior::SeparationBehavior(float separationRadius)
{
    // Additional initialization code if needed
}

Vector2D SeparationBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    Vector2D separationForce;
    int neighborCount = 0;

    for (Agent* neighbor : agent->getNeighbors())
    {
        // Calculate the distance to the neighbor
        float distance = Vector2D::Distance(agent->getPosition(), neighbor->getPosition());

        // Check if the neighbor is within the separation radius (avoid division by zero)
        if (distance > 0 && distance < agent->getSeparationRadius())
        {
            // Calculate the separation vector from the neighbor
            Vector2D separation = agent->getPosition() - neighbor->getPosition();
            separation.Normalize();

            // Weight the separation vector by the inverse of the distance
            separation /= distance;

            separationForce += separation;
            neighborCount++;
        }
    }

    if (neighborCount > 0)
    {
        // Average the separation force based on the number of neighbors
        separationForce /= static_cast<float>(neighborCount);

        // Normalize and scale the separation force by the maximum force
        separationForce.Normalize();
        separationForce *= agent->getMaxForce();

        return separationForce;
    }

    return Vector2D(0, 0);
}

Vector2D SeparationBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}

