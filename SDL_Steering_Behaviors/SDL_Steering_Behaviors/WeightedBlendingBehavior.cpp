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
    Vector2D totalForce;

    // Iterate through each behavior and calculate its force
    for (const auto& behaviorWeightPair : behaviors)
    {
        SteeringBehavior* behavior = behaviorWeightPair.first;
        float weight = behaviorWeightPair.second;

        // Calculate the force from the behavior
        Vector2D behaviorForce = behavior->CalculateForces(agent, target, dtime);
        // Add the weighted force to the total force
        totalForce += behaviorForce * weight;
    }

    //Mirar si es pot fer amb vectors
    //Posar acceleracio a fora

    return totalForce;
}

Vector2D WeightedBlendingBehavior::CalculateForces(Agent* agent, Agent* target, float dtime)
{
	return CalculateForces(agent, target->position, dtime);
}

//EXPLICACION PARA LOS DEMAS

/*Tenim els weights i llavors els comportaments en si, llavors a continuaci�, itera cada comportament i calcula la for�a produ�da per aquest comportament, 
llavors la cosa �s que la for�a calculada per cada comportament osea el behaviorForce es multiplica pel seu weight i la for�a resultant s'afegeix a la for�a total.
Fent aix� per a tots els comportaments tenim la totalForce, que �s el resultat combinat de tots els comportaments, amb cada comportament que contribueix segons el seu pes.*/