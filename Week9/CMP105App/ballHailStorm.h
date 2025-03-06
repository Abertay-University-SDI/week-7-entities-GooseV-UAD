#pragma once
#include "BeachBall.h"
#include <math.h>
#include <vector>
#include <ctime>
#include <iostream>
class ballHailStorm{
public:
	ballHailStorm();
	~ballHailStorm();
	void spawn();
	void update(float dt);
	void areYouDead();
	void render(sf::RenderWindow* window);
private:
	std::vector<BeachBall> balls; //create vector to store all active balls
	sf::Vector2f spawnPoint; //default spawnpoint, should be const but who cares it's 9am
	sf::Texture tex;
};

