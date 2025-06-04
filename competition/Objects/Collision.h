#pragma once

#include<vector>
#include<stdio.h>

#include"../Utility/Vector2D.h"

enum eObjectType
{
	eNone,
	ePlayer,
	eEnemy,
	ePlayerShot,
	eEnemyShot,
	eItem,
	eBlockDrone
};

class Collision
{
public:
	bool is_blocking;
	Vector2D box_size;
	Vector2D pivot;
	eObjectType object_type;
	std::vector<eObjectType> hit_object_type;

public:
	Collision();
	~Collision();

public:
	bool IsCheckHitTarget(eObjectType) const;
};