#include "FlockingBehavior.h"

FlockingBehavior::FlockingBehavior(float _cohesionWeight, float _separationWeight, float _alignmentWeight, float _separationRadius)
{
	weightedBlending = new WeightedBlendingBehavior({
		{new CohesionBehavior(), _cohesionWeight},
		{new SeparationBehavior(_separationRadius), _separationWeight},
		{new AlignmentBehavior(), _alignmentWeight}
		});

}

FlockingBehavior::~FlockingBehavior()
{
	//TODO: Maybe delete behaviors inside weightedBlending? (they are pointers)
}

Vector2D FlockingBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
	return weightedBlending->CalculateForces(agent, target, dtime);
}

Vector2D FlockingBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return weightedBlending->CalculateForces(agent, target, dtime);
}
