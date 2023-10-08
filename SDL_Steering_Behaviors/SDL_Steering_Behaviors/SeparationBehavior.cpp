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
            //separation.Normalize();

            // Weight the separation vector by the inverse of the distance

            separation /= distance;
            separation *= 10000.0f;

            separationForce += separation;
            
            neighborCount++;

        }
    }

    if (neighborCount > 0)
    {
        // Average the separation force based on the number of neighbors
        separationForce /= static_cast<float>(neighborCount);

        // Normalize and scale the separation force by the maximum force
        //separationForce.Normalize();
       // separationForce = (5, 5);

        //std::cout << separationForce.x << separationForce.y << std::endl;
        //separationForce *= agent->getMaxForce();
        //separationForce.x *= 1.f;
       // separationForce.y *= 1.f;

       // std::cout << separationForce.x << separationForce.y << std::endl;
       // std::cout << separationForce.x << separationForce.y << std::endl;
        return separationForce;

    }

    return Vector2D(0, 0);
}

Vector2D SeparationBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
    return CalculateForces(agent, target->getPosition(), dtime);
}

