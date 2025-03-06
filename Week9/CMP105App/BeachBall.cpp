#include "BeachBall.h"

BeachBall::BeachBall()
{
}

BeachBall::~BeachBall()
{
}

void BeachBall::update(float dt)
{
	move(velocity * dt);
}
