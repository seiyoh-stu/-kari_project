#include "Enemy5.h"

Enemy5::Enemy5() :
	shot_num(0),
	cool_down_2(2.0f),
	cool_down_2_count(0.0f)
{
	//���\�[�X�Ǘ��C���X�^���X�擾
	ResourceManager* rm = ResourceManager::GetInstance();

	// �R���W�����ݒ�
	collision.is_blocking = true;
	collision.box_size = Vector2D(30, 30);							//�����蔻��̑傫��
	collision.object_type = eObjectType::eEnemy;					//�I�u�W�F�N�g�̃^�C�v
	collision.hit_object_type.push_back(eObjectType::ePlayer);		//�Ԃ���I�u�W�F�N�g�̃^�C�v
	collision.hit_object_type.push_back(eObjectType::ePlayerShot);	//�Ԃ���I�u�W�F�N�g�̃^�C�v
	// �摜�ݒ�
	// ���C���[�ݒ�
	z_layer = 2;
	// �����ݒ�
	is_mobility = true;
	// �����擾(0: �G���j�󎞂̉� 1: �G���e�����������̉�)
	soundseffect[0] = rm->GetSounds("Resource/Sounds/SoundsEffect/Enemy/enemybreak.mp3");
	soundseffect[1] = rm->GetSounds("Resource/Sounds/SoundsEffect/Enemy/enemyshot.mp3");

}

Enemy5::~Enemy5()
{
}

void Enemy5::Initialize()
{
	//�@���G2�̃T�C�Y(�傫��)
	collision.box_size = Vector2D(20.0f, 20.0f);
	//box_size = Vector2D(20.0fs, 20.0f);
	// ���e�L�̑���
	speed = 200.0f;

	//�摜�ǂݍ���
	image = LoadGraph("Resource/Images/enemy/ship5.png");

	hp = 6.0f;

	velocity.x = -0.8f;
}

void Enemy5::Update(float delta_seconds)
{
	Movement(delta_seconds);
	Animation();

	float shot_cooldown = 0.4f;

	int shot_num_max = 3;

	//���Ԍo��
	shot_timer += delta_seconds;
	
	if(shot_num > shot_num_max)
	{
		cool_down_2_count += delta_seconds;
	}
	if (cool_down_2_count >= cool_down_2)
	{
		shot_num = 0;
		cool_down_2_count = 0.0f;
	}

	if (shot_timer >= shot_cooldown && shot_num <= shot_num_max
		&& player_location.x < location.x)
	{
		EnemyShot* shot = object_manager->CreateGameObject<EnemyShot>(this->location);
		shot->SetShotType(eEnemy4);

		shot_num++;

		PlaySoundMem(soundseffect[1], DX_PLAYTYPE_BACK, TRUE);

		//�^�C�}�[���Z�b�g
		shot_timer = 0.0f;
	}
}

void Enemy5::Draw(const Vector2D&, bool) const
{

	if (image != -1)
	{
		DrawRotaGraphF(location.x, location.y, 1.0f, 0.0f, image, TRUE);
	}

}

void Enemy5::Finalize()
{
}

void Enemy5::OnHitCollision(GameObject* hit_object)
{
	eObjectType type = hit_object->GetCollision().object_type;

	switch (type)
	{
	case eNone:
		break;
	case ePlayer:
		break;
	case eEnemy:
		break;
	case ePlayerShot:
		hp -= player_stats.attack_power / 2;
		break;
	case eEnemyShot:
		break;
	case eItem:
		break;
	default:
		break;
	}
	if (hp <= 0.0)
	{
		object_manager->CreateGameObject< ExperiencePoints>(this->location);
		object_manager->DestroyGameObject(this);
		PlaySoundMem(soundseffect[0], DX_PLAYTYPE_BACK, TRUE);
	}
}

void Enemy5::Movement(float delta_seconds)
{
	if (location.x <= 1180)
	{
		velocity.x = -0.2f;
	}

	location += velocity * speed * delta_seconds;
}

void Enemy5::Animation()
{
}