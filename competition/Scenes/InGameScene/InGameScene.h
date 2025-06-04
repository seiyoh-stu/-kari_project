#pragma once
#include"../SceneBase.h"
#include"../UI/LevelUpUI.h"
#include"../UI/HpUI.h"
#include"../UI/LevelUI.h"

#include"../../Objects/GameObject.h"
#include"../../Objects/Character/Player/Player.h"
#include"../../Objects/Character/Enemy/Enemy1/Enemy1.h"
#include"../../Objects/Character/Enemy/Enemy2/Enemy2.h"
#include"../../Objects/Character/Enemy/Enemy3/Enemy3.h"
#include"../../Objects/Character/Enemy/Enemy4/Enemy4.h"
#include"../../Objects/Character/Enemy/Enemy5/Enemy5.h"
#include"../../Objects/Character/Enemy/Enemy6/Enemy6.h"
#include "../../Objects/Character/Enemy/Boss1/Boss1.h"
#include "../../Objects/Character/Enemy/Boss2/Boss2.h"
#include"../../Objects/Shot/PlayerShot/PlayerShot.h"
#include"../../Objects/Shot/EnemyShot/EnemyShot.h"
#include"../../Objects/Item/ExperiencePoints/ExperiencePoints.h"

struct Planet
{
	float x;
	float y;
	double size;
	double angle;
	int image;
};

class InGameScene : public SceneBase
{
protected:

public:
	std::vector<GameObject*> scene_objects_list;//オブジェクトリスト
	class GameObjectManager* object_manager;	//オブジェクトマネージャーインスタンス
	class Player* player;						//プレイヤーインスタンス
	class Boss1* boss1;							//ボスインスタンス1
	class Boss2* boss2;							//ボスインスタンス2
	LevelUpUI* level_up_ui;						//レベルアップUI
	HpUI* hp_ui;								//HPUI
	LevelUI* level_ui;							//レベルUI

	int stage_level;							//ステージレベル

	int back_ground_image[3];					//背景画像
	Vector2D back_ground_location;				//背景座標
	int planets_image[4];						//惑星画像
	Planet pla1;								//惑星1
	Planet pla2;								//惑星2

	int enemy_random;							//
	int enemy_random_y;							//
	float spawn_timer;							//敵生成クールタイム
	float pattern_timer;						//caseの時間経過
	bool boss_flag;								//ボス描画フラグ

	int player_old_level;						//プレイヤー過去レベル
	int up_grade_stock;							//アップグレードストック
	bool level_up_flg;							//レベルアップフラグ
	bool time_stop;								//一時停止フラグ
	float time_count;							//時間カウント
	int bgm[3];
	int soundseffect[10];



public:
	InGameScene();	//コンストラクタ
	~InGameScene();	//デストラクタ

public:
	virtual void Initialize() override;						//初期化処理
	virtual eSceneType Update(const float& delta_second);	//更新処理
	virtual void Draw() const override;						//描画処理
	virtual void Finalize() override;						//終了処理

public:
	virtual eSceneType GetNowSceneType() const override;	//現在シーン取得処理

private:
	void BackGroundManager(const float& delta_second);		//背景管理処理

	void EnemyManager(const float& delta_second);			//敵生成管理処理
	void TestSpawn();										//テスト生成
	void Spawn1();											//雑魚生成1
	void Spawn2();											//雑魚生成2
	void BossManager();										//ボス生成管理処理

};