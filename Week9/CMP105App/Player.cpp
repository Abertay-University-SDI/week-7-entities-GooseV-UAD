#include "Player.h"

Player::Player()
{
	tex.loadFromFile("gfx/guy.png");
	setTexture(&tex);
	font.loadFromFile("font/arial.ttf");
	name.setFont(font);
	name.setCharacterSize(12);
	name.setString("Gunble, Destroyer of Worlds");
	setSize(sf::Vector2f(141, 196));
}

Player::~Player()
{
}

void Player::update(float dt)
{
	move(velocity * dt);
}

void Player::handleInput(float dt)
{
	float moveX = input->isKeyDown(sf::Keyboard::A) - input->isKeyDown(sf::Keyboard::D);
	float moveY;
}
