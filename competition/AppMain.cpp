#include"Utility/Application.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR pCmdLine, _In_ int nShowCmd)
{
	try
	{
		Application application;

		//初期化処理
		application.WakeUp();

		//実行処理
		application.Run();

		//終了時処理
		application.Shutdown();
	}
	catch (std::string error_log)
	{
		//エラー内容を出力する
		//Log.txtにエラー内容を追加する
		ErrorLogFmtAdd(error_log.c_str());
		return D_FAILURE;
	}

	return D_SUCCESS;
}