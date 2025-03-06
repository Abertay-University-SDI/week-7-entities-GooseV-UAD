#include "ballHailStorm.h"

ballHailStorm::ballHailStorm()
{
	//spawnPoint = sf::Vector2f(rand() % 200, -200);
	tex.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 40; i++) { // limits to 40 balls here
		balls.push_back(BeachBall()); //push newly created ball to back of vector (append)
		balls[i].setAlive(false);
		balls[i].setTexture(&tex);
		balls[i].setSize(sf::Vector2f(100, 100));
	}

}

ballHailStorm::~ballHailStorm()
{
}

void ballHailStorm::spawn()
{
	for (int i = 0; i < balls.size(); i++) {
		if (!balls[i].isAlive()) {
			balls[i].setAlive(true);
			balls[i].setVelocity(0, rand()% 200 - 70);
			balls[i].setPosition(sf::Vector2f(rand() % 1100, -200));
			return;
		}
	}
}

void ballHailStorm::update(float dt)
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			balls[i].update(dt);
		}
	}
	areYouDead();
}

void ballHailStorm::areYouDead()
{
	for (int i = 0; i < balls.size(); i++){
		if (balls[i].getPosition().y > 700) {
			balls[i].setAlive(false);
		}
	}
}

void ballHailStorm::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {

			window->draw(balls[i]);
		}
	}
}
