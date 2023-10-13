
#include "SceneSeek.h"

using namespace std;

SceneSeek::SceneSeek()
{
	Agent *agent = new Agent(new SeekBehavior());
	agent->setPosition(Vector2D(640,360));
	agent->setTarget(Vector2D(640, 360));
	agents.push_back(agent);
	target = Vector2D(640, 360);
}

SceneSeek::~SceneSeek()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneSeek::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			agents[0]->setTarget(target);
		}
		break;
	default:
		break;
	}
	
	agents[0]->update(dtime, event);
}

void SceneSeek::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	agents[0]->draw();	//If more than one agent, iterate through all the array
}

const char* SceneSeek::getTitle()
{
	return "SDL Steering Behaviors :: KinematicSeek Demo";
}