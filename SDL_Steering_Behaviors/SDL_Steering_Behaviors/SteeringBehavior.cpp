#include "SteeringBehavior.h"



SteeringBehavior::SteeringBehavior()
{
}


SteeringBehavior::~SteeringBehavior()
{
}

/*
Vector2D SteeringBehavior::CalculateForces(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = target - agent->position;
	steering.Normalize();
	return steering * agent->max_velocity;

	//FALTEN COSES:
	//No volem que sigui un mètode de steeringbehaviour, sinó que sigui una classe filla a part
	//El codi ha de ser correcte -> falta el càlcul d'acceleració


	return Vector2D();
}

Vector2D SteeringBehavior::CalculateForces(Agent *agent, Agent *target, float dtime)
{
	//return CalculateForces(agent, target->position, dtime);
	return Vector2D();
}
*/

Vector2D SteeringBehavior::Flee(Agent *agent, Vector2D target, float dtime)
{
	Vector2D steering = agent->position - target;
	steering.Normalize();
	return steering * agent->max_velocity;

	//FALTEN COSES:
	//No volem que sigui un mètode de steeringbehaviour, sinó que sigui una classe filla a part
	//El codi ha de ser correcte -> falta el càlcul d'acceleració
}

Vector2D SteeringBehavior::Flee(Agent *agent, Agent *target, float dtime)
{
	return Flee(agent, target->position, dtime);
}

