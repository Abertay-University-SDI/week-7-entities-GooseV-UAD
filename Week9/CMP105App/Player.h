#pragma once
#include "Framework/GameObject.h"
class Player : public GameObject{
public:
	Player();
	~Player();
	void update(float dt) override;
	void handleInput(float dt) override;
private:
	sf::Texture tex;
	sf::Text name;
	sf::Font font;
	const float ACCELERATION{ 200.0f };
	const float MAXIMUM_VELOCITY{ 400.0f };
};

