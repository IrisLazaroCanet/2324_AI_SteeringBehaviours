#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "Vector2D.h"
#include "utils.h"
#include "SeekBehavior.h"


//Agent fa:
//BM->current_behavior->CalculateForces();

//Segons la tecla SDL que es premi (el mode / escena / el que sigui...), canvia el current_behavior
//Com que el BM �s un singleton, pot setejar-se aquesta variable des de qualsevol part del codi

//D'aquesta manera, Agent no ha de dependre de cap classe SteeringBehavior
//doncs no �s ella qui es guarda el seu behavior

//Tot i que aix� t� un problema: l'escalabilitat
//Si volgu�ssim tenir diversos agents, com ho far�em? Ja que tots els Agent executarien el behaviour de l'�nic BM
//Aquest problema sortir� al flocking

//Potser el singleton no �s la millor idea


//Una altra opci� �s fer el struct
//Hi hauria un AgentStruct.h
//Que inclourien tant Agent.h com els SteeringBehavior s
//Cada agent tindria un struct amb les seves variables
//I les funcions de SteeringBehavior rebrien un AgentStruct enlloc d'un Agent

//Una altra opci� �s simplement passar totes les varaibles a sac com a par�metres
//Per� aix� pot donar problemes per la diversitat dels comportaments
//Potser no tots els comportaments necessiten totes les variables?
//Llavors les funcions override rebrien par�metres que no necessiten
//(no �s elegant)

//Potser el millor �s el struct (?)



class Agent
{
private:
	SteeringBehavior* steering_behavior;
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

public:
	Agent();
	~Agent();
	SteeringBehavior* Behavior();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getMass();
	float getMaxForce();
	float getMaxVelocity();
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void setMass(float mass);
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void update(float dtime, SDL_Event *event);
	void draw();
	bool Agent::loadSpriteTexture(char* filename, int num_frames=1);
	
};
