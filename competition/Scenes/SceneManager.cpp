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
	// �`����\��ʂɔ��f����
	SetDrawScreen(DX_SCREEN_BACK);

	// �ŏ��̃V�[�����^�C�g����ʂɂ���
	ChangeScene(eSceneType::eTitle);

	// ��A�N�e�B�u��Ԃł����삳����
	SetAlwaysRunFlag(TRUE);
}

bool SceneManager::Update(float delta_seconds)
{
	//�V�[���̍X�V
	eSceneType next_scene_type = current_scene->Update(delta_seconds);

	//�`�揈��
	Graph();

	// �Q�[�����I�����邩�m�F����
	if (next_scene_type == eSceneType::eExit)
	{
		return TRUE;
	}

	// ���݂̃V�[���^�C�v�����̃V�[���^�C�v�ƈ���Ă��邩�H
	if (current_scene->GetNowSceneType() != next_scene_type)
	{
		// �V�[���؂�ւ�����
		ChangeScene(next_scene_type);
	}

	return FALSE;
}

void SceneManager::Graph() const
{
	//��ʂ̏�����
	ClearDrawScreen();

	//�V�[���̕`�揈��
	current_scene->Draw();

	//����ʂ̓��e��\��ʂɔ��f����
	ScreenFlip();
}

void SceneManager::Finalize()
{

}

bool SceneManager::ChangeScene(eSceneType next_type)
{
	// ���̃V�[���𐶐�����
	SceneBase* next_scene = SceneFactory::CreateScene(next_type);

	// �G���[�`�F�b�N
	if (next_scene == nullptr)
	{
		throw ("�V�[���������ł��܂���ł���\n");
	}

	// �V�[����񂪊i�[����Ă�����A�폜����
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}

	// ���̃V�[���̏�����
	next_scene->Initialize();

	// ���݃V�[���̏㏑��
	current_scene = next_scene;
}