#include "RankingScene.h"
#include "../../Utility/InputManager.h"
#include "../../Resource/ResourceManager.h"

RankingScene::RankingScene()
{
	//���\�[�X�Ǘ��C���X�^���X�擾
	ResourceManager* rm = ResourceManager::GetInstance();

	// �摜�擾
}

RankingScene::~RankingScene()
{

}

void RankingScene::Initialize()
{

}

eSceneType RankingScene::Update(const float& delta_second)
{
	// ���͋@�\�C���X�^���X�擾
	InputManager* input = InputManager::GetInstance();

	// ���͏��̍X�V
	input->Update();

	// �Q�[���I��
	if (input->GetKeyUp(KEY_INPUT_ESCAPE))
	{
		return eSceneType::eExit;
	}

	// 2�L�[�Ń^�C�g���ɖ߂�
	if (input->GetButtonDown(XINPUT_BUTTON_B) || input->GetKeyUp(KEY_INPUT_2))
	{
		return eSceneType::eTitle;
	}

	return GetNowSceneType();
}

void RankingScene::Draw() const
{
	DrawFormatString(10, 10, GetColor(255, 255, 255), "�����L���O�V�[��");
	DrawFormatString(10, 110, GetColor(255, 255, 255), "B�{�^���Ń^�C�g���ɖ߂�");

}

void RankingScene::Finalize()
{
}

eSceneType RankingScene::GetNowSceneType() const
{
	return eSceneType::eRanking;
}
