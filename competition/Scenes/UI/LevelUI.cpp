#include"LevelUI.h"
#define MAX_BAR		(31)
LevelUI::LevelUI() :
	// level_bar(),
	exp(0),
	max_exp(0),
	level_ui1(0),
	level_ui2(0),
	level(0)
{
	// ���\�[�X�Ǘ��C���X�^���X�擾
	ResourceManager* rm = ResourceManager::GetInstance();
	// level_bar = rm->GetImages("Resource/Images/LevelUi/level_ui3.png", 10, 10, 1, 32, 32);
	level_ui1 = rm->GetImages("Resource/Images/LevelUi/level_ui1.png")[0];
	level_ui2 = rm->GetImages("Resource/Images/LevelUi/level_ui2.png")[0];
}

LevelUI::~LevelUI()
{

}

void LevelUI::Initialize()
{

}

void LevelUI::Update()
{
	// max�o���l�̊���(���݂̌o���l�ʂɑ΂��Ă�)
	level = (exp * 100) / max_exp;
}

void LevelUI::Draw() const
{
	// �e�X�g�p�`��
	if (level != 0)
	{
		DrawRotaGraph(30, 700, 0.9, 0, level_ui1, 1, 0);
	}
	for (int i = 0; i < level; i++)			
	{
		DrawRotaGraph((70 + (i * 12)), 700, 0.9, 0, level_ui2, 1, 0);	// max�`���31(��ʍ�����E�[�܂� �E�[��������̂�30)
	}

	// DrawFormatString(640, 80, 0xff00ff, "%d", exp);
	// DrawFormatString(640, 80, 0xff00ff, "%d", level);
	// DrawRotaGraph(58, 700, 0.9, 0, level_bar[1], 1, 0);

}

void LevelUI::Finalize()
{

}

void LevelUI::SetExperience(int exp, int max_exp)
{
	this->exp = exp;
	this->max_exp = max_exp;
}
