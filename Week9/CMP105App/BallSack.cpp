#include "BallSack.h"

BallSack::BallSack()
{
	spawnPoint = sf::Vector2f(300, 200);
	tex.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 20; i++) { // limits to 20 balls here
		balls.push_back(BeachBall()); //push newly created ball to back of vector (append)
		balls[i].setAlive(false);
		balls[i].setTexture(&tex);
		balls[i].setSize(sf::Vector2f(100, 100));
	}

}

BallSack::~BallSack()
{
}

void BallSack::spawn()
{
	
	for (int i = 0; i < balls.size(); i++) { //don't ask questions
		if (!balls[i].isAlive()) {

			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			return;
		}

		else {
			balls.push_back(BeachBall());

		}
	}
}

void BallSack::update(float dt)
{
	//go through every index value of balls and only update those that are alive
	for (int i = 0; i < balls.size(); i++) {

		if (balls[i].isAlive()) {
			balls[i].update(dt);
		}
	}
	areYouDead();
}

void BallSack::areYouDead()
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {
			if (balls[i].getPosition().x < - 100 || balls[i].getPosition().x > 800) {
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y < -100 || balls[i].getPosition().y > 600) {
				balls[i].setAlive(false);
			}
		}
	}
}

void BallSack::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++) {
		if (balls[i].isAlive()) {

			window->draw(balls[i]);
		}
	}
}
