#include "Boss2.h"

Boss2::Boss2()
{
	// �R���W�����ݒ�
	collision.is_blocking = true;
	collision.box_size = Vector2D(150, 150);						//�����蔻��̑傫��
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

	//�ő�HP�ݒ�
	max_hp = 150;
	hp = float(max_hp);
}

Boss2::~Boss2()
{
}

void Boss2::Initialize()
{
	int random = rand() % 2;
	if (random == 0)
		velocity.y = -0.7f;
	else
		velocity.y = 0.7f;

	//�摜�ǂݍ���
	image = LoadGraph("Resource/Images/enemy/ship3_col2.png");
}

void Boss2::Update(float delta_seconds)
{
	Movement(delta_seconds);
	Animation();

	//HP�����v�Z
	ratio = (hp * 100) / max_hp;
	if (ratio <= 0)
	{
		ratio = 0;
	}

	//���Ԍo��
	shot_timer += delta_seconds;

	EnemyShot* shot;

	//�U��
	if (hp > 0 && shot_timer >= 0.6f)
	{
		switch (atack_pattern)
		{
		case 0:
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y + 230));
			shot->SetShotType(eEnemy5);
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y));
			shot->SetShotType(eEnemy5);
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y - 230));
			shot->SetShotType(eEnemy5);
			atack_pattern = 1;
			break;
		case 1:
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y + 180));
			shot->SetShotType(eEnemy4);
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y - 180));
			shot->SetShotType(eEnemy4);
			atack_pattern = 2;
			break;
		case 2:
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y + 230));
			shot->SetShotType(eEnemy5);
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y));
			shot->SetShotType(eEnemy5);
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y - 230));
			shot->SetShotType(eEnemy5);
			atack_pattern = 3;
			break;
		case 3:
			object_manager->CreateGameObject<Enemy2>(Vector2D(1300, location.y + 7))->SetTrans();
			object_manager->CreateGameObject<Enemy2>(Vector2D(1300, location.y - 7));
			atack_pattern = 4;
			break;
		case 4:
			object_manager->CreateGameObject<Enemy4>(Vector2D(1300, location.y + 205));
			object_manager->CreateGameObject<Enemy4>(Vector2D(1300, location.y - 205));
			atack_pattern = 0;
			break;
		default:
			break;
		}

		//�^�C�}�[���Z�b�g
		shot_timer = 0.0f;
	}

	//��
	if (hp <= 0.0f)
	{
		death_count -= (delta_seconds * 1.0f);
	}
	if (death_count <= 0.0)
	{
		death_flag = true;
	}

}

void Boss2::Draw(const Vector2D& screen_offset, bool flip_flag) const
{
	if (image != -1)
	{
		DrawRotaGraphF(location.x, location.y, 10.0f, 0.0f, image, TRUE);
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	// ���݂�HP�̃o�[�̕`��
	if (ratio != 0)
	{
		DrawRotaGraph(100, 670, 1.0, 0, hp_bar1, 1, 0);
	}
	for (int i = 0; i < ratio; i++)
	{
		DrawRotaGraph((105 + (i * 11)), 670, 1.0, 0, hp_bar2, 1, 0);
	}
	if (ratio != 0)
	{
		SetFontSize(26);
		DrawFormatString(7, 657, GetColor(255, 0, 255), "BOSS");
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Boss2::Finalize()
{
}

void Boss2::OnHitCollision(GameObject* hit_object)
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
}

void Boss2::Movement(float delta_seconds)
{
	float speed = 200.0f;

	if ((location.y + velocity.y) <= (65.0f + collision.box_size.y) || (location.y + velocity.y) >= (680 - collision.box_size.y))
	{

		if (velocity.y < 0)
			velocity.y = 0.7f;
		else
			velocity.y = -0.7f;
	}

	location += velocity * speed * delta_seconds;
}

void Boss2::Animation()
{
}

int Boss2::GetBoss2Hp()
{
	return ratio;
}

bool Boss2::GetDeathFlag()
{
	return death_flag;
}