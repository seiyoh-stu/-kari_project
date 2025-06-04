#include"PlayerShot.h"
#include"../../../Utility/InputManager.h"

PlayerShot::PlayerShot() :
	screen_velocity(0.0f),
	Color(),
	Shotmode()
{

	//���\�[�X�Ǘ��C���X�^���X�擾
	ResourceManager* rm = ResourceManager::GetInstance();

	// ���W
	location = Vector2D(D_WIN_MAX_X / 2, D_WIN_MAX_Y / 2);
	// �R���W�����ݒ�
	collision.is_blocking = true;
	collision.box_size = Vector2D(5 + player_stats.player_shot_hitrange_up, 5 + player_stats.player_shot_hitrange_up);
	collision.object_type = eObjectType::ePlayerShot;
	collision.hit_object_type.push_back(eObjectType::eEnemy);
	// �摜�ݒ�
	// ���C���[�ݒ�
	z_layer = 2;
	// �����ݒ�
	is_mobility = true;
}

PlayerShot::~PlayerShot()
{

}

void PlayerShot::Initialize()
{

}

void PlayerShot::Update(float delta_seconds)
{
	Movement(delta_seconds);

	Animation();

	ShotModeChange();
}

void PlayerShot::Draw(const Vector2D& screen_offset, bool flip_flag) const
{
	__super::Draw(0.0f, this->flip_flag);
	DrawBox((location.x - collision.box_size.x / 2) - player_stats.player_shot_hitrange_up, (location.y - collision.box_size.y / 2) - player_stats.player_shot_hitrange_up, (location.x + collision.box_size.x / 2) + player_stats.player_shot_hitrange_up, (location.y + collision.box_size.y / 2) + player_stats.player_shot_hitrange_up, Color, TRUE);
}

void PlayerShot::Finalize()
{

}

void PlayerShot::OnHitCollision(GameObject* hit_object)
{
	eObjectType type = hit_object->GetCollision().object_type;

	switch (type)
	{
	case eNone:
		break;
	case ePlayer:
		break;
	case eEnemy:
		object_manager->DestroyGameObject(this);
		break;
	case ePlayerShot:
		break;
	case eEnemyShot:
		break;
	case eItem:
		break;
	default:
		break;
	}
}

Vector2D PlayerShot::GetScreenVelocity()
{
	Vector2D value = 0.0f;
	value.x = screen_velocity;
	screen_velocity = 0.0f;
	return value;
}

Vector2D PlayerShot::GetVelocity()
{
	return this->velocity;
}

void PlayerShot::SetVelocity(Vector2D velocity)
{
	this->velocity += velocity;
}

void PlayerShot::Movement(float delta_seconds)
{
	// �ړ��X�s�[�h
	float speed = 800.0f;
	// �ړ�����
	float direction = 0.0f;

	switch (shot_type)
	{
	case ePlayer1:
		Color = GetColor(0, 255, 255);
		velocity.x = 1.0f;
		break;
	case ePlayer2:
		Color = GetColor(255, 0, 255);
		velocity.x += 0.00045f;
		break;
	case ePlayer3:
		Color = GetColor(200, 200, 200);
		velocity.x = 1.0f;
		break;
	}

	//�ʒu���W�������x�����炷
	location += velocity * speed * delta_seconds;
}

void PlayerShot::Animation()
{

}

void PlayerShot::ShotModeChange()
{

}

void PlayerShot::SetAngle(float degree)
{
    float radian = degree * (3.14f / 180.0f);
    this->velocity.x = cosf(radian);
    this->velocity.y = -sinf(radian); // y�����������ɐ��Ȃ�}�C�i�X
}