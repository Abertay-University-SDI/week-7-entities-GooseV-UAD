#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)) {
		ballManager.spawn();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {
		ballSnow.spawn();
	}
	//keyboard events are inaccurate due to a lack of time between button presses
	//may be solved with different input handling or with a time-based delay (sf::Clock ?)
}

// Update game objects
void Level::update(float dt)
{
	ballManager.update(dt);
	ballManager.areYouDead();
	ballSnow.update(dt);
	ballSnow.areYouDead();
}

// Render level
void Level::render()
{
	

	beginDraw();
	ballManager.render(window);
	ballSnow.render(window);
	endDraw();
}
