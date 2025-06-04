#pragma once

#include"../GameObject.h"
#include"../GameObjectManager.h"

enum eItemType
{
	eExp
};

class Item : public GameObject
{
protected:
	Vector2D velocity = 0.0f;
	int anime_count = 0;

	eItemType item_type;

public:
	bool flip_flag = false;

	eItemType GetItemType()
	{
		return this->item_type;
	}
};