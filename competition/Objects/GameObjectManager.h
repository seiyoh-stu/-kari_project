#pragma once

#include<vector>
#include<stdio.h>

#include"GameObject.h"
#include"../Utility/Singleton.h"
#include"../Utility/Vector2D.h"
#include"../Resource/ResourceManager.h"

class GameObjectManager : public Singleton
{
private:
	std::vector<GameObject*> create_objects;
	std::vector<GameObject*> destroy_objects;
	std::vector<GameObject*> game_objects_list;

public:
	GameObjectManager();
	~GameObjectManager();

public:
	void CheckCreateObject();
	void CheckDestroyObject();
	const std::vector<GameObject*>& GetObjectList() const;
	
	template <class T>
	T* CreateGameObject(const Vector2D& generate_location)
	{
		// ��������Q�[���I�u�W�F�N�g�N���X�𓮓I�m��
		T* new_instance = new T();
		// GameObject���p�����Ă��邩�m�F
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);
		// �G���[�`�F�b�N
		if (new_object == nullptr)
		{
			// ���I�m�ۂ����������̊J��
			delete new_instance;
			// ��O�e�L�X�g��ʒm
			throw std::string("�Q�[���I�u�W�F�N�g�������ł��܂���ł���");
			return nullptr;
		}
		// �ʒu���̐ݒ�
		new_object->SetLocation(generate_location);
		// ����������
		new_object->Initialize();
		// �����I�u�W�F�N�g���X�g�̖����Ɋi�[����
		create_objects.push_back(new_object);
		// ���������Q�[���I�u�W�F�N�g�̃|�C���^��Ԃ�
		return new_instance;
	}

	void DestroyGameObject(GameObject* target)
	{
		// �k���|�`�F�b�N
		if (target == nullptr)
		{
			return;
		}

		// �j���I�u�W�F�N�g���X�g���ɂ���΁A�ǉ����Ȃ�
		for (GameObject* obj : destroy_objects)
		{
			if (obj == target)
			{
				return;
			}
		}

		// �j�����s���I�u�W�F�N�g���X�g�ɒǉ�����
		destroy_objects.push_back(target);
	}

public:
	// �����蔻��m�F����
	void HitCheck(GameObject*, GameObject*);
	bool IsCheckCollision(Collision, Collision, Vector2D, Vector2D);
};