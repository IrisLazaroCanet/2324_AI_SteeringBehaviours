//SceneFlockingCollisionAvoidance.cpp
#include "SceneFlockingCollisionAvoidance.h"
using namespace std;

SceneFlockingCollisionAvoidance::SceneFlockingCollisionAvoidance(int agentAmount)
{

	// Create and add obstacles to the list of obstacles
	obstacles.push_back(CollisionAvoidanceBehavior::Obstacle(Vector2D(200, 200)));
	obstacles.push_back(CollisionAvoidanceBehavior::Obstacle(Vector2D(500, 300)));
	obstacles.push_back(CollisionAvoidanceBehavior::Obstacle(Vector2D(800, 400)));

	//Default values
	tweakableValues.coneHalfAngle = 180.f;
	tweakableValues.coneDistance = 200.f;

	int x_max, x_min, y_max, y_min, xPosition, yPosition;
	for (int i = 0; i < agentAmount; i++)
	{
		Agent* agent = new Agent(new PriorityBlendingBehavior({
			new CollisionAvoidanceBehavior(obstacles, tweakableValues.coneHalfAngle, tweakableValues.coneDistance),
			new FlockingBehavior(0.8f, 0.4f, 0.4f)
			}));

		x_max = 1275;
		x_min = 5;
		y_max = 715;
		y_min = 5;
		xPosition = (rand() % (x_max - x_min + 1)) + x_min;
		yPosition = (rand() % (y_max - y_min + 1)) + y_min;

		agent->setPosition(Vector2D((float)xPosition, (float)yPosition));
		agent->setTarget(Vector2D((float)xPosition, (float)yPosition));
		agent->setRadius(200.f, 100.f, 150.f);
		agents.push_back(agent);

		//Agents will go to the middle of the screen by default
		target = Vector2D(640, 360);
	}

	for (int i = 0; i < agentAmount; i++)
	{
		for (int j = 0; j < (int)agents.size(); j++)
		{
			agents[i]->addNeighbor(agents[j]);
		}
	}
}

SceneFlockingCollisionAvoidance::~SceneFlockingCollisionAvoidance()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneFlockingCollisionAvoidance::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));

			for (int i = 0; i < (int)agents.size(); i++)
				agents[i]->setTarget(target);
		}
		break;
	case SDL_KEYDOWN:
	{
		if (event->key.keysym.scancode == SDL_SCANCODE_Z && tweakableValues.coneHalfAngle < MAX_ANGLE)
		{
			UpdateValue(tweakableValues.coneHalfAngle, ANGLE_INCREMENT);
			std::cout << "Collision avoidance cone angle = " << tweakableValues.coneHalfAngle << std::endl;
		}
		if (event->key.keysym.scancode == SDL_SCANCODE_X && tweakableValues.coneHalfAngle > MIN_ANGLE)
		{
			UpdateValue(tweakableValues.coneHalfAngle, -ANGLE_INCREMENT);
			std::cout << "Collision avoidance cone angle = " << tweakableValues.coneHalfAngle << std::endl;
		}
		if (event->key.keysym.scancode == SDL_SCANCODE_C && tweakableValues.coneDistance < MAX_DISTANCE)
		{
			UpdateValue(tweakableValues.coneDistance, DISTANCE_INCREMENT);
			std::cout << "Collision avoidance cone distance = " << tweakableValues.coneDistance << std::endl;
		}
		if (event->key.keysym.scancode == SDL_SCANCODE_V && tweakableValues.coneDistance > MIN_DISTANCE)
		{
			UpdateValue(tweakableValues.coneDistance, -DISTANCE_INCREMENT);
			std::cout << "Collision avoidance cone distance = " << tweakableValues.coneDistance << std::endl;
		}
		break;
	}
	default:
		break;
	}

	for (int i = 0; i < (int)agents.size(); i++)
	{
		agents[i]->update(dtime, event);
	}

	for (int i = 0; i < (int)agents.size(); i++)
		UpdateAgentValues(i);
}

void SceneFlockingCollisionAvoidance::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);

	draw_circle(TheApp::Instance()->getRenderer(), (int)(obstacles[0].position.x), (int)(obstacles[0].position.y), 30, 255, 0, 0, 255);
	draw_circle(TheApp::Instance()->getRenderer(), (int)(obstacles[1].position.x), (int)(obstacles[1].position.y), 30, 255, 0, 0, 255);
	draw_circle(TheApp::Instance()->getRenderer(), (int)(obstacles[2].position.x), (int)(obstacles[2].position.y), 30, 255, 0, 0, 255);

	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->draw();
}

const char* SceneFlockingCollisionAvoidance::getTitle()
{
	return "SDL Steering Behaviors :: Flocking with Collision avoidance Demo";
}

void SceneFlockingCollisionAvoidance::UpdateValue(float& value, float increment)
{
	value += increment;
}

void SceneFlockingCollisionAvoidance::UpdateAgentValues(int index)
{
	dynamic_cast<CollisionAvoidanceBehavior*>(
		dynamic_cast<PriorityBlendingBehavior*>(agents[index]->getBehavior())->getBehavior(0)
		)->SetConeValues(
			tweakableValues.coneHalfAngle,
			tweakableValues.coneDistance
		);
}
