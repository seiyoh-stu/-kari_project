#pragma once

#include"../GameObject.h"
#include"../GameObjectManager.h"

class Character : public GameObject
{
protected:
	Vector2D velocity = 0.0f;
	int hit_point = 0;
	int anime_count = 0;

public:
	bool flip_flag = false;
};