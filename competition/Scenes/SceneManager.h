#pragma once
#include"../Utility/Singleton.h"
#include"SceneBase.h"

class SceneManager : public Singleton
{
private:
	//現在のシーン情報のポインタ
	SceneBase* current_scene;

public:
	SceneManager();
	~SceneManager();


	//初期化処理
	void Initialize();

	//更新処理
	bool Update(float);

	//描画処理
	void Graph() const;

	//終了時処理
	void Finalize();

private:
	bool ChangeScene(eSceneType);
};