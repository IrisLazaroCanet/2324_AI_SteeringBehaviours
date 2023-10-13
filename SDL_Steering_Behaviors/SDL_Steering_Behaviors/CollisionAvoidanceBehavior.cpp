//CollisionAvoidanceBehaviour.cpp
#include "CollisionAvoidanceBehavior.h"

CollisionAvoidanceBehavior::CollisionAvoidanceBehavior()
{
}

CollisionAvoidanceBehavior::CollisionAvoidanceBehavior(const std::vector<Obstacle>& obstacles)
{
    this->obstacles = obstacles;
}

CollisionAvoidanceBehavior::~CollisionAvoidanceBehavior()
{
}

void CollisionAvoidanceBehavior::setObstacles(const std::vector<Obstacle>& obstacles)
{
    this->obstacles = obstacles;
}

Vector2D CollisionAvoidanceBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
    // Get the list of obstacles (stored within the behavior class)
    std::vector<Obstacle>& obstacles = this->obstacles;

    // Set the cone vision parameters (you may adjust these)
    float coneHalfAngle = 180.0f;  // Half of the cone angle
    float coneDistance = 200.0f; // Maximum distance to check for obstacles

    // Get the agent's position and orientation
    Vector2D agentPosition = agent->getPosition();
    float agentOrientation = agent->getOrientation();

    // Initialize variables to track the nearest obstacle and distance
    Obstacle* nearestObstacle = nullptr;
    float shortestDistance = coneDistance;

    for (const Obstacle& obstacle : obstacles)
    {
        Vector2D obstaclePosition = obstacle.position;

        // Check if the obstacle is inside the agent's cone of vision
        if (Vector2DUtils::IsInsideCone(obstaclePosition, agentPosition, target, coneHalfAngle))
        {
            // Calculate the distance from the agent to the obstacle
            float distanceToObstacle = Vector2D::Distance(agentPosition, obstaclePosition);

            // Update the nearest obstacle if this one is closer
            if (distanceToObstacle < shortestDistance)
            {
                nearestObstacle = const_cast<Obstacle*>(&obstacle);  // Corrected line
                shortestDistance = distanceToObstacle;
            }
        }
    }

    // If a nearest obstacle is found, calculate the point to flee from and apply the Flee behavior
    if (nearestObstacle != nullptr)
    {
        // Calculate the point to flee from (the closest point on the obstacle)
        Vector2D closestPointOnObstacle = Vector2DUtils::GetClosestPoint(agentPosition, nearestObstacle->position, target);

        // Calculate the Flee force to move away from the closest point
        Vector2D fleeForce = agentPosition - closestPointOnObstacle;

        return fleeForce;
    }

    // No obstacle in vision cone, return zero force
    return Vector2D();
}

Vector2D CollisionAvoidanceBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->position, dtime);
}
