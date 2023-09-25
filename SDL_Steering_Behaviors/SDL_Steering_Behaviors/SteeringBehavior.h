#pragma once
#include "Agent.h"
#include "Vector2D.h"

class Agent;

class SteeringBehavior
{
public:
	SteeringBehavior();
	~SteeringBehavior();

	//Vector2D CalculateForce(...);
	//Totes les classes filles estaran obligades a cridar aquesta funci�
	//Totes elles calculen una for�a
	//Que la informaci� estigui dins la classe agent, a CalculateForce li passem *agent i float dtime si �s necessari

	virtual Vector2D CalculateForces(Agent *agent, Vector2D target, float dtime) = 0;
	virtual Vector2D CalculateForces(Agent *agent, Agent *target, float dtime) = 0;
	Vector2D Flee(Agent *agent, Vector2D target, float dtime);
	Vector2D Flee(Agent *agent, Agent *target, float dtime);
	//etc...

};

//Passar la classe steering behaviour a abstracta
