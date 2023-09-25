#include "SeekBehavior.h"

SeekBehavior::SeekBehavior()
{
}

SeekBehavior::~SeekBehavior()
{
}

Vector2D SeekBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
	Vector2D steering = target - agent->position;
	steering.Normalize();
	return steering * agent->max_velocity;

	//FALTEN COSES:
	//No volem que sigui un m�tode de steeringbehaviour, sin� que sigui una classe filla a part
	//El codi ha de ser correcte -> falta el c�lcul d'acceleraci�
}

Vector2D SeekBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->position, dtime);
}
