#include "Enemy1.h"

Enemy1::Enemy1()
{

	//���\�[�X�Ǘ��C���X�^���X�擾
	ResourceManager* rm = ResourceManager::GetInstance();

	// �R���W�����ݒ�
	collision.is_blocking = true;
	collision.box_size = Vector2D(30, 30);							//�����蔻��̑傫��
	collision.object_type = eObjectType::eEnemy;					//�I�u�W�F�N�g�̃^�C�v
	collision.hit_object_type.push_back(eObjectType::ePlayer);		//�Ԃ���I�u�W�F�N�g�̃^�C�v
	collision.hit_object_type.push_back(eObjectType::ePlayerShot);	//�Ԃ���I�u�W�F�N�g�̃^�C�v
	// �����X�s�[�h
	// speed=200.0f;
	// �摜�ݒ�
	// ���C���[�ݒ�
	z_layer = 2;
	// �����ݒ�
	is_mobility = true;

	// �����擾(0: �G���j�󎞂̉� 1: �G���e�����������̉�)
	soundseffect[0] = rm->GetSounds("Resource/Sounds/SoundsEffect/Enemy/enemybreak.mp3");
	soundseffect[1] = rm->GetSounds("Resource/Sounds/SoundsEffect/Enemy/enemyshot.mp3");
}

Enemy1::~Enemy1()
{

}


void Enemy1::Initialize()
{
	int random = rand() % 2;
	if (random == 0)
		velocity.y = -1.0f;
	else
		velocity.y = 1.0f;

	velocity.x = -0.5f;

	//�摜�ǂݍ���
	image = LoadGraph("Resource/Images/enemy/ship1.png");
}

void Enemy1::Update(float delta_seconds)
{
	Movement(delta_seconds);
	Animation();

	//���͋@�\�C���X�^���X�擾
	InputManager* input = InputManager::GetInstance();

	//���Ԍo��
	shot_timer += delta_seconds;

	if (shot_timer>=shot_cooldown)
	{
		EnemyShot* shot = object_manager->CreateGameObject<EnemyShot>(this->location);
		shot->SetShotType(eEnemy1);
		PlaySoundMem(soundseffect[1], DX_PLAYTYPE_BACK, TRUE);

		//�^�C�}�[���Z�b�g
		shot_timer = 0.0f;

		int random_cool = rand() % 5;

		switch (random_cool)
		{
		case 0:
			shot_cooldown = 1.2f;
			break;
		case 1:
			shot_cooldown = 1.2f;
			break;
		case 2:
			shot_cooldown = 1.3f;
			break;
		case 3:
			shot_cooldown = 1.5f;
			break;
		case 4:
			shot_cooldown = 1.6f;
			break;
		default:
			break;
		}
	}

}

void Enemy1::Draw(const Vector2D& screeen_offset, bool file_flag) const
{
	if (image != -1)
	{
		DrawRotaGraphF(location.x, location.y, 1.0f, 0.0f, image, TRUE);
	}
	// ��(�����l�p��`�悷��)
	/*Vector2D t1 = location - (collision.box_size / 2.0f);
	Vector2D br = location + (collision.box_size / 2.0f);
	DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 255, 255), TRUE);
	DrawString(t1.x, t1.y, "1", GetColor(0, 0, 0), TRUE);*/
}

void Enemy1::Finalize()
{

}

void Enemy1::OnHitCollision(GameObject* hit_object)
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
		object_manager->CreateGameObject< ExperiencePoints>(this->location);
		object_manager->DestroyGameObject(this);
		hp -= player_stats.attack_power / 2;
		PlaySoundMem(soundseffect[0], DX_PLAYTYPE_BACK, TRUE);
		break;
	case eEnemyShot:
		break;
	case eItem:
		break;
	default:
		break;
	}
}

void Enemy1::Movement(float delta_seconds)
{
	float speed = 200.0f;

	if ((location.y + velocity.y) <= (65.0f + collision.box_size.y) || (location.y + velocity.y) >= (680 - collision.box_size.y))
	{
		
		if (velocity.y < 0)
			velocity.y = 1.0f;
		else
			velocity.y = -1.0f;
	}

	location += velocity * speed * delta_seconds;
}

void Enemy1::Animation()
{

}