#include "SceneFlocking.h"

using namespace std;

SceneFlocking::SceneFlocking(int agentAmount)
{
	for (int i = 0; i < agentAmount; i++)
	{
		Agent* agent = new Agent(/* new FlockingBehavior()*/);
		//Random position in range

	}
}

SceneFlocking::~SceneFlocking()
{
}

void SceneFlocking::update(float dtime, SDL_Event* event)
{
}

void SceneFlocking::draw()
{
}

const char* SceneFlocking::getTitle()
{
	return nullptr;
}
