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
	//All behaviors as friend classes
	friend class SteeringBehavior;
	friend class SeekBehavior;
	friend class FleeBehavior;
	friend class WeightedBlendingBehavior;
	friend class PriorityBlendingBehavior;
	friend class CohesionBehavior;
	friend class SeparationBehavior;
	friend class AllignmentBehavior;
	friend class FlockingBehavior;
	friend class CollisionAvoidanceBehavior;

private:
	SteeringBehavior* steering_behavior; // A pointer to the steering behavior used by the agent
	Vector2D position; // Current position of the agent
	Vector2D velocity; // Current velocity of the agent
	Vector2D target;   // Target position for the agent

	float mass;        // Mass of the agent
	float orientation; // Orientation of the agent
	float max_force;   // Maximum force the agent can apply
	float max_velocity; // Maximum velocity the agent can reach

	SDL_Color color;   // Color for rendering the agent

	SDL_Texture* sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

	float cohesionRadius;
	float separationRadius;
	float alignmentRadius;

	std::vector<Agent*> neighbors; // List of neighboring agents
	float maxForce; // Maximum force

public:
	Agent();
	// Constructor that takes a steering behavior
	Agent(SteeringBehavior* _steering_behavior);
	// Destructor
	~Agent();

	// Accessor for the steering behavior
	SteeringBehavior* Behavior();

	///////////////////////GETTERS///////////////////////////
	// Accessor for the agent's position
	Vector2D getPosition();

	// Accessor for the agent's target
	Vector2D getTarget();

	// Accessor for the agent's velocity
	Vector2D getVelocity();

	// Accessor for the agent's maximum velocity
	float getMaxVelocity();


	// Accessor for the maximum force the agent can apply
	float getMaxForce() const { return maxForce; }

	// Accessor for the list of neighbors
	const std::vector<Agent*>& getNeighbors() const { return neighbors; }

	// Accessor for the separation radius
	float getSeparationRadius() const;

	// Accessor for the alignment radius
	float getAlignmentRadius() const { return alignmentRadius; }

	// Set the cohesion, separation, and alignment radii
	void setRadius(float _cohesionRadius, float _separationRadius, float _alignmentRadius);

	// Accessor for the agent's orientation
	float getOrientation() const
	{
		return (float)(atan2(velocity.y, velocity.x) * RAD2DEG);
	}

	// Accessor for the agent's steering behavior
	SteeringBehavior* getBehavior() const { return steering_behavior; }

	///////////////////////SETTERS///////////////////////////
	// Mutator for the agent's position
	void setPosition(Vector2D position);

	// Mutator for the agent's target
	void setTarget(Vector2D target);

	// Mutator for the agent's velocity
	void setVelocity(Vector2D velocity);

	// Mutator for the agent's mass
	void setMass(float mass);

	// Mutator for the agent's color
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	///////////////////////OTHERS///////////////////////////
	// Update function to update the agent's state
	void update(float dtime, SDL_Event* event);

	// Draw function to render the agent
	void draw();

	// Load a sprite texture for the agent
	bool loadSpriteTexture(char* filename, int num_frames = 1);

	// Accessor for the cohesion radius
	float getCohesionRadius() const { return cohesionRadius; }

	// Add a neighbor to the agent's list of neighbors
	void addNeighbor(Agent* neighbor)
	{
		neighbors.push_back(neighbor);
	}
};
