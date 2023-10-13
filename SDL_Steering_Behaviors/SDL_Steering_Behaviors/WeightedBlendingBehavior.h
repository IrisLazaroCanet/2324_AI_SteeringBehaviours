#pragma once
#include "SteeringBehavior.h"
#include <map>

using namespace std;

class Agent;

class WeightedBlendingBehavior : public SteeringBehavior
{
public:
	WeightedBlendingBehavior(map<SteeringBehavior*, float> _behaviors);
	~WeightedBlendingBehavior();

	virtual Vector2D CalculateForces(Agent* agent, Vector2D target, float dtime) override;
	virtual Vector2D CalculateForces(Agent* agent, Agent* target, float dtime) override;
	
private:
	//Un map ens permet tenir associat a cada behavior el seu weight
	//Millor que tenir dos vectors per separat
	map<SteeringBehavior*, float> behaviors;
};