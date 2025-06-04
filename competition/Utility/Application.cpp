#include"Application.h"
#include"../Scenes/SceneManager.h"

LONGLONG old_time;		// �O��v���l
LONGLONG now_time;		// ���݌v���l

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
	// �E�B���h�E���[�h�ŋN������
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y�̐ݒ�
	SetGraphMode(D_WIN_MAX_X, D_WIN_MAX_Y, D_COLOR_BIT);

	// �E�B���h�E�^�C�g���̐ݒ�
	SetWindowText("competition 2025");

	// �t�H���g�T�C�Y�̐ݒ�
	SetFontSize(48);


	// �����������s��Ȃ�
	SetWaitVSyncFlag(FALSE);

	// Log.txt�t�@�C���̐�������iDebug���[�h�̂ݐ�������j
#if _DEBUG
	SetOutApplicationLogValidFlag(TRUE);
#else
	SetOutApplicationLogValidFlag(FALSE);
#endif // _DEBUG

	// Dx���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		throw std::string("Dx���C�u�����̏������Ɏ��s���܂����I\n");
	}

	// �`����\��ʂɔ��f����
	SetDrawScreen(DX_SCREEN_BACK);

	// ��A�N�e�B�u��Ԃł����삳����
	SetAlwaysRunFlag(TRUE);
}

void Application::Run()
{
	SceneManager scenemanager;

	scenemanager.Initialize();

	//���C�����[�v
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
	// Singleton�̃C���X�^���X���������
	InputManager::DeleteInstance();
	ResourceManager::DeleteInstance();

	// Dx���C�u�����̎g�p���I������
	DxLib_End();
}

void Application::UpdateDeltaTime()
{
	// ���ݎ��Ԃ̎擾�i�ʕb�j
	now_time = GetNowHiPerformanceCount();

	// �J�n���Ԃ��猻�ݎ��Ԃ܂łɌo�߂������Ԃ��v�Z����i�ʕb�j
	// ����\���ʕb���b�ɕϊ�����
	delta_seconds = (float)(now_time - old_time) * 1.0e-6f;

	// �v���J�n���Ԃ��X�V����
	old_time = now_time;

	// �f�B�X�v���C�̃��t���b�V�����[�g���擾����
	float refresh_rate = (float)GetRefreshRate();

	// �P�t���[��������̎��Ԃ�1/���t���b�V�����[�g�b�𒴂�����A������
	if (delta_seconds > (1.0f / refresh_rate))
	{
		delta_seconds = (1.0f / refresh_rate);
	}
}