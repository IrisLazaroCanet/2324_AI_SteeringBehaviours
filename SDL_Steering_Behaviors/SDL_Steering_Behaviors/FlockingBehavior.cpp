#include "FlockingBehavior.h"

FlockingBehavior::FlockingBehavior(float _cohesionWeight, float _separationWeight, float _alignmentWeight, float _separationRadius)
{
	//Weighted blending: flocking
	
	
	weightedBlending = new WeightedBlendingBehavior({
		{new CohesionBehavior(), _cohesionWeight},
		{new SeparationBehavior(_separationRadius), _separationWeight},
		{new AlignmentBehavior(), _alignmentWeight}
		});
	

	//Weighted blending: seek & flee (test)
	/*
	weightedBlending = new WeightedBlendingBehavior({
		{new FleeBehavior(), _cohesionWeight},
		{new SeekBehavior(), _separationWeight},
		});
		*/

		
	//Priority blending: seek & flee (test)
	priorityBlending = new PriorityBlendingBehavior({
		{new FleeBehavior(),new SeekBehavior()},
	});
			

}

FlockingBehavior::~FlockingBehavior()
{
	//TODO: Maybe delete behaviors inside weightedBlending? (they are pointers)
}

Vector2D FlockingBehavior::CalculateForces(Agent* agent, Vector2D target, float dtime)
{
	return weightedBlending->CalculateForces(agent, target, dtime);
	//return priorityBlending->CalculateForces(agent, target, dtime);
}

Vector2D FlockingBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return weightedBlending->CalculateForces(agent, target, dtime);
	//return priorityBlending->CalculateForces(agent, target, dtime);
}
