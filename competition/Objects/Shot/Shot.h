#pragma once

#include"../GameObject.h"
#include"../GameObjectManager.h"

enum eShotType
{
	ePlayer1,
	ePlayer2,
	ePlayer3,
	eEnemy1,	//�^��
	eEnemy2,	//�^��
	eEnemy3,	//�^��
	eEnemy4,	//���@�_��
	eEnemy5		//�O�l�O�l
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