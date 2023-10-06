#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "Vector2D.h"
#include "utils.h"
#include "SteeringBehavior.h"

#include <vector>

class Agent
{
	friend class SteeringBehavior;
	friend class SeekBehavior;
	friend class FleeBehavior;
	friend class WeightedBlendingBehavior;
///////////////////////////////////////////////////////////////////////////////Added
	friend class PriorityBlendingBehavior;
	friend class CohesionBehavior;


private:
	SteeringBehavior *steering_behavior;
	Vector2D position;
	Vector2D velocity;
	Vector2D target;


	float mass;
	float orientation;
	float max_force;
	float max_velocity;

	SDL_Color color;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

///////////////////////////////////////////////////////////////////////////////Added
		// Add a member variable for the cohesion radius
	float cohesionRadius;

	// Add a member variable to store a list of neighboring agents
	std::vector<Agent*> neighbors;
	float maxForce; // Add a member variable for maximum force


public:
	Agent();
	Agent(SteeringBehavior* _steering_behavior);
	~Agent();
	SteeringBehavior *Behavior();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getMaxVelocity();
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void setMass(float mass);
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void update(float dtime, SDL_Event *event);
	void draw();
	bool Agent::loadSpriteTexture(char* filename, int num_frames=1);
	

	///////////////////////////////////////////////////////////////////////////////Added
		// Add functions to get the cohesion radius and neighbors
	float getCohesionRadius() const { return cohesionRadius; }

	// Add a function to add neighboring agents
	void addNeighbor(Agent* neighbor)
	{
		neighbors.push_back(neighbor);
	}

	// Implement a function to get the maximum force
	float getMaxForce() const { return maxForce; }

	// Implement the getNeighbors function
	const std::vector<Agent*>& getNeighbors() const { return neighbors; }
	// ...
};
