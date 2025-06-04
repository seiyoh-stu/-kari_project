#include"DxLib.h"
#include"GameObject.h"
#include"GameObjectManager.h"

GameObject::GameObject() :
	location(0.0f),
	speed(0),
	image(NULL),
	transparency(255),
	z_layer(0),
	is_mobility(false),
	player_location(0.0f),
	player_stats(),
	object_manager(nullptr)
{

}

GameObject::~GameObject()
{

}

/// <summary>
/// ����������
/// </summary>
void GameObject::Initialize()
{

}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="delta_second">1�t���[��������̎���</param>
void GameObject::Update(float delta_second)
{

}

/// <summary>
/// �`�揈��
/// </summary>
/// <param name="screen_offset">�I�t�Z�b�g�l</param>
void GameObject::Draw(const Vector2D& screen_offset, bool flip_flag) const
{
	// �I�t�Z�b�g�l����ɉ摜�̕`����s��
	Vector2D graph_location = this->location + screen_offset;
	DrawRotaGraphF(graph_location.x, graph_location.y, SIZE, 0.0, image, TRUE, flip_flag);
}

/// <summary>
/// �I��������
/// </summary>
void GameObject::Finalize()
{

}

//�����蔻��ʒm����
void GameObject::OnHitCollision(GameObject* hit_object)
{

}

//���W�擾����
const Vector2D& GameObject::GetLocation() const
{
	return location;
}

//���W�ݒ菈��
void GameObject::SetLocation(const Vector2D location)
{
	this->location = location;
}

//�R���W�����擾����
const Collision& GameObject::GetCollision() const
{
	return collision;
}

//���C���[�擾����
const unsigned char GameObject::GetZLayer() const
{
	return z_layer;
}

//�����擾����
const bool GameObject::GetMobility() const
{
	return is_mobility;
}

//�v���C���[���W�ݒ菈��
void GameObject::SetPlayerLocation(Vector2D location)
{
	if (player_location.x == 0.0f && player_location.y == 0.0f)
	{
		old_player_location = location;
	}
	player_location = location;
}

//�v���C���[�X�e�[�^�X�ݒ菈��
void GameObject::SetPlayerStats(PlayerStats stats)
{
	player_stats = stats;
}


//A��B��ǔ����鏈��
Vector2D GameObject::Tracking(Vector2D A, Vector2D B)
{
	Vector2D velocity;	//�����x
	float distance;		//����

	velocity.x = A.x - B.x;
	velocity.y = A.y - B.y;

	distance = sqrt(pow(velocity.x, 2.0) + pow(velocity.y, 2.0));

	velocity.x /= distance;
	velocity.y /= distance;

	velocity *= -1;

	return velocity;

}

//�I�u�W�F�N�g�}�l�[�W���[�ݒ菈��
const GameObjectManager* GameObject::CheckInstance() const
{
	return object_manager;
}
void GameObject::SetInstance(GameObjectManager* instance)
{
	object_manager = instance;
}