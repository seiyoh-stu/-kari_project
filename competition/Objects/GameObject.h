#pragma once

#include"Collision.h"
#include"Character/Player/PlayerStats.h"

class GameObject
{
protected:
	Vector2D location;				//���W
	float speed;
	Collision collision;			//�R���W����
	int image;						//�摜
	int transparency;				//�����x
	unsigned char z_layer;			//���C���[
	bool is_mobility;				//����
	Vector2D player_location;		//�v���C���[���W
	Vector2D old_player_location;	//�������v���C���[���W
	PlayerStats player_stats;		//�v���C���[�X�e�[�^�X

	// �I�u�W�F�N�g�}�l�[�W���[�̃C���X�^���X
	class GameObjectManager* object_manager;

public:
	GameObject();
	~GameObject();

public:
	virtual void Initialize();
	virtual void Update(float);
	virtual void Draw(const Vector2D&, bool) const;
	virtual void Finalize();

	virtual void OnHitCollision(GameObject*);	//�����蔻��ʒm����
	const Vector2D& GetLocation() const;		//���W�擾����
	void SetLocation(const Vector2D);			//���W�ݒ菈��
	const Collision& GetCollision() const;		//�R���W�����擾����
	const unsigned char GetZLayer() const;		//���C���[�擾����
	const bool GetMobility() const;				//�����擾����


	void SetPlayerLocation(Vector2D location);	//�v���C���[���W�ݒ菈��
	void SetPlayerStats(PlayerStats stats);		//�v���C���[�X�e�[�^�X�ݒ菈��
	Vector2D Tracking(Vector2D A, Vector2D B);	//A��B��ǔ����鏈��

	const GameObjectManager* CheckInstance() const;	//�C���X�^���X�m�F����
	void SetInstance(GameObjectManager* instance);	//�C���X�^���X�ݒ菈��
};