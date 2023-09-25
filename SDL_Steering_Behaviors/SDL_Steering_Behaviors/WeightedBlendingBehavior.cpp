#include "WeightedBlendingBehavior.h"

WeightedBlendingBehavior::WeightedBlendingBehavior(map<SteeringBehavior*, float> _behaviors)
{
	behaviors = _behaviors;
}

WeightedBlendingBehavior::~WeightedBlendingBehavior()
{
}

Vector2D WeightedBlendingBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
	//Cridar el CalculateForces de tots els seus behaviors
	//Llavors fer la suma ponderada
	//I return d'una sola força
	
	return Vector2D();
}

Vector2D WeightedBlendingBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->position, dtime);
}
