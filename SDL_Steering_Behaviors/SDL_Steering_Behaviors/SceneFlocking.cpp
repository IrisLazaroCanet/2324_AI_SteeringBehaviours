#include "SceneFlocking.h"

using namespace std;

SceneFlocking::SceneFlocking(int agentAmount)
{
	int x_max, x_min, y_max, y_min, xPosition, yPosition;
	for (int i = 0; i < agentAmount; i++)
	{
		Agent* agent = new Agent(new FlockingBehavior(0.8f, 0.4f, 0.4f, 5.f));

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

SceneFlocking::~SceneFlocking()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneFlocking::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			
			for(int i = 0; i < (int)agents.size(); i++)
				agents[i]->setTarget(target);
		}
		break;
	default:
		break;
	}

	for(int i = 0; i < (int)agents.size(); i++)
		agents[i]->update(dtime, event);
}

void SceneFlocking::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	
	for (int i = 0; i < (int)agents.size(); i++)
		agents[i]->draw();
}

const char* SceneFlocking::getTitle()
{
	return "SDL Steering Behaviors :: Flocking Demo";
}
