#include"Utility/Application.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR pCmdLine, _In_ int nShowCmd)
{
	try
	{
		Application application;

		//����������
		application.WakeUp();

		//���s����
		application.Run();

		//�I��������
		application.Shutdown();
	}
	catch (std::string error_log)
	{
		//�G���[���e���o�͂���
		//Log.txt�ɃG���[���e��ǉ�����
		ErrorLogFmtAdd(error_log.c_str());
		return D_FAILURE;
	}

	return D_SUCCESS;
}