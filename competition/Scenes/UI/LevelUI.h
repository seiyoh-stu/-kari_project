#pragma once
#include"../../Utility/Singleton.h"
#include"../../Resource/ResourceManager.h"

class LevelUI
{	
private:
	int exp;
	int max_exp;
	int level_ui1;
	int level_ui2;
	int level;
	std::vector<int> level_bar;			// レベル増加の画像

public:
	LevelUI();
	~LevelUI();

public:
	void Initialize();			//初期化処理
	void Update();				//更新処理
	void Draw() const;			//描画処理
	void Finalize();			//終了処理

	void SetExperience(int, int);	// プレイヤーから増加されたレベル(累計)の取得処理
};