#pragma once

#include"../GameObject.h"
#include"../GameObjectManager.h"

enum eShotType
{
	ePlayer1,
	ePlayer2,
	ePlayer3,
	eEnemy1,	//真左
	eEnemy2,	//真上
	eEnemy3,	//真下
	eEnemy4,	//自機狙い
	eEnemy5		//グネグネ
};

class Shot : public GameObject
{
protected:
	Vector2D velocity = 0.0f;
	int anime_count = 0;

	eShotType shot_type;
	int shot_power = 0;

public:
	bool flip_flag = false;

	void SetShotType(eShotType type)
	{
		shot_type = type;
	}
	void SetShowPower(int power)
	{
		shot_power = power;
	}
	
};