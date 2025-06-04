#include"ResultScene.h"
#include"../../Utility/InputManager.h"
#include"../../Resource/ResourceManager.h"


ResultScene::ResultScene(): m_selectedbutton(selectedbutton::Title), menu_num(0), is_button(true)			//初期はタイトル選択
{
	//リソース管理インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	//画像取得
}

ResultScene::~ResultScene()
{

}

void ResultScene::Initialize()
{
	//選択状態リセット
	m_selectedbutton = selectedbutton::Title;
}

eSceneType ResultScene::Update(const float& delta_second)
{
	//入力機能インスタンス取得
	InputManager* input = InputManager::GetInstance();

	//入力情報の更新
	input->Update();

	// カーソル右移動
	if (input->GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT) && is_button == true)
	{
		menu_num--;
		if (menu_num < 0)
		{
			menu_num = 1;
		}
	}

	// カーソル左移動
	if (input->GetButtonDown(XINPUT_BUTTON_DPAD_LEFT) && is_button == true)
	{
		menu_num++;
		if (menu_num > 1)
		{
			menu_num = 0;
		}
	}


	if (input->GetButtonDown(XINPUT_BUTTON_A) && is_button == true)
	{
		switch (menu_num)
		{
		case 0:
			//タイトルシーンへ遷移
			return eSceneType::eExit;
			break;
		case 1:
			//ゲームを終了
			return eSceneType::eTitle;
			break;
		default:
			break;

		}
	}
	return GetNowSceneType();
}

void ResultScene::Draw() const
{
		/*		リザルト画面案*/
		// ランク
		DrawBox(50, 20, 615, 550, 0xffffff, TRUE);
		DrawFormatString(50, 270, 0x000000, "スコアランク");

		// スコア結果
		DrawBox(665, 20, 1230, 550, 0xffffff, TRUE);
		DrawFormatString(665, 270, 0x000000, "スコア結果");

		// エンドボタン
		int endColor = (m_selectedbutton == selectedbutton::End) ? GetColor(255, 0, 0):GetColor(128,128,128);
		DrawBox(25, 600, 325, 700, 0xffffff, TRUE);
		DrawFormatString(25, 630, endColor, "End");

		// タイトルボタン
		int titleColor = (m_selectedbutton == selectedbutton::Title) ? GetColor(255, 0, 0) : GetColor(128,128,128);
		DrawBox(955, 600, 1255, 700, 0xffffff, TRUE);
		DrawFormatString(955, 630, titleColor, "Title");
	
		switch (menu_num)
		{
		case 0:
			DrawTriangle(5, 640, 5, 660, 25, 650, GetColor(255, 0, 0), TRUE);
			break;
		case 1:
			DrawTriangle(935, 640, 935, 660, 955, 650, GetColor(255, 0, 0), TRUE);
			break;
		default:
			break;
		}
}

void ResultScene::Finalize()
{

}

eSceneType ResultScene::GetNowSceneType()const
{
	return eSceneType::eResult;
}