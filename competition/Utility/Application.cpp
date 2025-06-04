#include"Application.h"
#include"../Scenes/SceneManager.h"

LONGLONG old_time;		// 前回計測値
LONGLONG now_time;		// 現在計測値

Application::Application() :
	delta_seconds(),
	is_finalize(FALSE)
{

}

Application::~Application()
{
	Shutdown();
}

void Application::WakeUp()
{
	// ウィンドウモードで起動する
	ChangeWindowMode(TRUE);

	// ウィンドウサイズの設定
	SetGraphMode(D_WIN_MAX_X, D_WIN_MAX_Y, D_COLOR_BIT);

	// ウィンドウタイトルの設定
	SetWindowText("competition 2025");

	// フォントサイズの設定
	SetFontSize(48);


	// 垂直同期を行わない
	SetWaitVSyncFlag(FALSE);

	// Log.txtファイルの生成制御（Debugモードのみ生成する）
#if _DEBUG
	SetOutApplicationLogValidFlag(TRUE);
#else
	SetOutApplicationLogValidFlag(FALSE);
#endif // _DEBUG

	// Dxライブラリの初期化
	if (DxLib_Init() == -1)
	{
		throw std::string("Dxライブラリの初期化に失敗しました！\n");
	}

	// 描画先を表画面に反映する
	SetDrawScreen(DX_SCREEN_BACK);

	// 非アクティブ状態でも動作させる
	SetAlwaysRunFlag(TRUE);
}

void Application::Run()
{
	SceneManager scenemanager;

	scenemanager.Initialize();

	//メインループ
	while (ProcessMessage() == D_SUCCESS)
	{
		UpdateDeltaTime();

		is_finalize = scenemanager.Update(delta_seconds);

		if (is_finalize == TRUE)
		{
			break;
		}
	}

	scenemanager.Finalize();
}

void Application::Shutdown()
{
	// Singletonのインスタンスを解放する
	InputManager::DeleteInstance();
	ResourceManager::DeleteInstance();

	// Dxライブラリの使用を終了する
	DxLib_End();
}

void Application::UpdateDeltaTime()
{
	// 現在時間の取得（μ秒）
	now_time = GetNowHiPerformanceCount();

	// 開始時間から現在時間までに経過した時間を計算する（μ秒）
	// 分解能をμ秒→秒に変換する
	delta_seconds = (float)(now_time - old_time) * 1.0e-6f;

	// 計測開始時間を更新する
	old_time = now_time;

	// ディスプレイのリフレッシュレートを取得する
	float refresh_rate = (float)GetRefreshRate();

	// １フレーム当たりの時間が1/リフレッシュレート秒を超えたら、整える
	if (delta_seconds > (1.0f / refresh_rate))
	{
		delta_seconds = (1.0f / refresh_rate);
	}
}