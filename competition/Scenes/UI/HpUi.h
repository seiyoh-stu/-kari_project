#pragma once
#include"../../Utility/Singleton.h"
#include"../../Resource/ResourceManager.h"

class HpUI
{
private:
	// int hp_table;
	int hp_bar1;			// HPバー(左端)
	int hp_bar2;			// HPバー(右端)
	int hp;					// 
	int max_hp;				// 最大HP
public:
	HpUI();
	~HpUI();

public:
	void Initialize();			//初期化処理
	void Update();				//更新処理
	void Draw() const;			//描画処理
	void Finalize();			//終了処理

	void SetHp(int, int);
};