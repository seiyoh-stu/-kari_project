#pragma once
#include"../../Utility/Singleton.h"
#include"../../Resource/ResourceManager.h"
#include"../../Utility/InputManager.h"
#include"../../Objects/Character/Player/PlayerStats.h"

#define	LOT_MAX			(7)	//最大抽選数

#define	STATS_HP		(0)
#define STATS_DAMAGE	(1)
#define STATS_SPEED		(2)
#define WAPON_SPEED		(3)
#define WAPON_SIZE		(4)
#define WAPON_3WAY		(5)
#define WAPON_DRONE		(6)

class LevelUpUI
{
public:
	bool old_flag;
	int cursor;
private:
	//画像
	int window[4];
	int power[LOT_MAX];
	int power_icon[LOT_MAX];

	ePowerUp lot[LOT_MAX];		//強化内容抽選
	int lot_str[LOT_MAX];		//強化内容文字
	int lot_icon[LOT_MAX];		//強化内容アイコン

	PlayerStats player_stats;	//プレイヤーステータス

	//各確率(合計100%)
	int proba[LOT_MAX] = { 20,15,15,15,15,10,10 };
	//int proba[LOT_MAX] = { 0,10,10,0,10,20,50 };	////tset
	int bility[LOT_MAX] = { 0,0,0,0,0,0,0 };


public:
	LevelUpUI();
	~LevelUpUI();

public:
	void Initialize();							//初期化処理
	void Update(bool flag, PlayerStats stats);	//更新処理
	void Draw() const;							//描画処理
	void Finalize();							//終了処理
	
	int Probability();							//確率調整
	void Lottery(int* nums);					//抽選
	ePowerUp GetLottery();						//抽選内容取得
};