#pragma once
#include "Framework/GameObject.h"
class BeachBall : public GameObject {
public:
	BeachBall();
	~BeachBall();
	void update(float dt) override;
private:
};

