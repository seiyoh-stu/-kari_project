#pragma once

#include"../Character.h"
#include"../../Shot/EnemyShot/EnemyShot.h"
#include"../../../Utility/InputManager.h"
#include"../../Item/ExperiencePoints/ExperiencePoints.h"

class EnemyBase : public Character
{
public:
	int image;					//�摜
	float radian = 0;			//�p�x

	float hp;					//HP
	int max_hp = 0;				//�ő�HP
	int ratio = 100;			//HP����

	float shot_timer = 0.0f;	//���Ԍo��
	float shot_cooldown = 1.5f;	//�N�[���^�C��
	int atack_pattern = 0;		//�U���p�^�[��

	float death_count = 3.0f;	//���ʂ܂ł̎���
	bool death_flag = false;	//��

	int soundseffect[2];

	//���\�[�X�Ǘ��C���X�^���X�擾
	ResourceManager* rm = ResourceManager::GetInstance();

	int hp_bar1 = rm->GetImages("Resource/Images/HPUi/Boss_HP_Bar_1.png")[0];
	int hp_bar2 = rm->GetImages("Resource/Images/HPUi/Boss_HP_Bar_3.png")[0];

};