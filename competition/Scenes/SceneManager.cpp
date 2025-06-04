#include"SceneManager.h"
#include"SceneFactory.h"

SceneManager::SceneManager() : 
	current_scene(nullptr)
{

}

SceneManager::~SceneManager()
{
	Finalize();
}

void SceneManager::Initialize()
{
	// 描画先を表画面に反映する
	SetDrawScreen(DX_SCREEN_BACK);

	// 最初のシーンをタイトル画面にする
	ChangeScene(eSceneType::eTitle);

	// 非アクティブ状態でも動作させる
	SetAlwaysRunFlag(TRUE);
}

bool SceneManager::Update(float delta_seconds)
{
	//シーンの更新
	eSceneType next_scene_type = current_scene->Update(delta_seconds);

	//描画処理
	Graph();

	// ゲームを終了するか確認する
	if (next_scene_type == eSceneType::eExit)
	{
		return TRUE;
	}

	// 現在のシーンタイプが次のシーンタイプと違っているか？
	if (current_scene->GetNowSceneType() != next_scene_type)
	{
		// シーン切り替え処理
		ChangeScene(next_scene_type);
	}

	return FALSE;
}

void SceneManager::Graph() const
{
	//画面の初期化
	ClearDrawScreen();

	//シーンの描画処理
	current_scene->Draw();

	//裏画面の内容を表画面に反映する
	ScreenFlip();
}

void SceneManager::Finalize()
{

}

bool SceneManager::ChangeScene(eSceneType next_type)
{
	// 次のシーンを生成する
	SceneBase* next_scene = SceneFactory::CreateScene(next_type);

	// エラーチェック
	if (next_scene == nullptr)
	{
		throw ("シーンが生成できませんでした\n");
	}

	// シーン情報が格納されていたら、削除する
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}

	// 次のシーンの初期化
	next_scene->Initialize();

	// 現在シーンの上書き
	current_scene = next_scene;
}