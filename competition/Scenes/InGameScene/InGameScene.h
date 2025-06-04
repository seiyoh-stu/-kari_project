#pragma once
#include"../SceneBase.h"
#include"../UI/LevelUpUI.h"
#include"../UI/HpUI.h"
#include"../UI/LevelUI.h"

#include"../../Objects/GameObject.h"
#include"../../Objects/Character/Player/Player.h"
#include"../../Objects/Character/Enemy/Enemy1/Enemy1.h"
#include"../../Objects/Character/Enemy/Enemy2/Enemy2.h"
#include"../../Objects/Character/Enemy/Enemy3/Enemy3.h"
#include"../../Objects/Character/Enemy/Enemy4/Enemy4.h"
#include"../../Objects/Character/Enemy/Enemy5/Enemy5.h"
#include"../../Objects/Character/Enemy/Enemy6/Enemy6.h"
#include "../../Objects/Character/Enemy/Boss1/Boss1.h"
#include "../../Objects/Character/Enemy/Boss2/Boss2.h"
#include"../../Objects/Shot/PlayerShot/PlayerShot.h"
#include"../../Objects/Shot/EnemyShot/EnemyShot.h"
#include"../../Objects/Item/ExperiencePoints/ExperiencePoints.h"

struct Planet
{
	float x;
	float y;
	double size;
	double angle;
	int image;
};

class InGameScene : public SceneBase
{
protected:

public:
	std::vector<GameObject*> scene_objects_list;//�I�u�W�F�N�g���X�g
	class GameObjectManager* object_manager;	//�I�u�W�F�N�g�}�l�[�W���[�C���X�^���X
	class Player* player;						//�v���C���[�C���X�^���X
	class Boss1* boss1;							//�{�X�C���X�^���X1
	class Boss2* boss2;							//�{�X�C���X�^���X2
	LevelUpUI* level_up_ui;						//���x���A�b�vUI
	HpUI* hp_ui;								//HPUI
	LevelUI* level_ui;							//���x��UI

	int stage_level;							//�X�e�[�W���x��

	int back_ground_image[3];					//�w�i�摜
	Vector2D back_ground_location;				//�w�i���W
	int planets_image[4];						//�f���摜
	Planet pla1;								//�f��1
	Planet pla2;								//�f��2

	int enemy_random;							//
	int enemy_random_y;							//
	float spawn_timer;							//�G�����N�[���^�C��
	float pattern_timer;						//case�̎��Ԍo��
	bool boss_flag;								//�{�X�`��t���O

	int player_old_level;						//�v���C���[�ߋ����x��
	int up_grade_stock;							//�A�b�v�O���[�h�X�g�b�N
	bool level_up_flg;							//���x���A�b�v�t���O
	bool time_stop;								//�ꎞ��~�t���O
	float time_count;							//���ԃJ�E���g
	int bgm[3];
	int soundseffect[10];



public:
	InGameScene();	//�R���X�g���N�^
	~InGameScene();	//�f�X�g���N�^

public:
	virtual void Initialize() override;						//����������
	virtual eSceneType Update(const float& delta_second);	//�X�V����
	virtual void Draw() const override;						//�`�揈��
	virtual void Finalize() override;						//�I������

public:
	virtual eSceneType GetNowSceneType() const override;	//���݃V�[���擾����

private:
	void BackGroundManager(const float& delta_second);		//�w�i�Ǘ�����

	void EnemyManager(const float& delta_second);			//�G�����Ǘ�����
	void TestSpawn();										//�e�X�g����
	void Spawn1();											//�G������1
	void Spawn2();											//�G������2
	void BossManager();										//�{�X�����Ǘ�����

};