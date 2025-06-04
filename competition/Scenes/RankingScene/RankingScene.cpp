#include "RankingScene.h"
#include "../../Utility/InputManager.h"
#include "../../Resource/ResourceManager.h"

RankingScene::RankingScene()
{
	//リソース管理インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	// 画像取得
}

RankingScene::~RankingScene()
{

}

void RankingScene::Initialize()
{

}

eSceneType RankingScene::Update(const float& delta_second)
{
	// 入力機能インスタンス取得
	InputManager* input = InputManager::GetInstance();

	// 入力情報の更新
	input->Update();

	// ゲーム終了
	if (input->GetKeyUp(KEY_INPUT_ESCAPE))
	{
		return eSceneType::eExit;
	}

	// 2キーでタイトルに戻る
	if (input->GetButtonDown(XINPUT_BUTTON_B) || input->GetKeyUp(KEY_INPUT_2))
	{
		return eSceneType::eTitle;
	}

	return GetNowSceneType();
}

void RankingScene::Draw() const
{
	DrawFormatString(10, 10, GetColor(255, 255, 255), "ランキングシーン");
	DrawFormatString(10, 110, GetColor(255, 255, 255), "Bボタンでタイトルに戻る");

}

void RankingScene::Finalize()
{
}

eSceneType RankingScene::GetNowSceneType() const
{
	return eSceneType::eRanking;
}
