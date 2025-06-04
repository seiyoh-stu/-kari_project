#include"GameObjectManager.h"

GameObjectManager::GameObjectManager() :
	create_objects(),
	destroy_objects(),
	game_objects_list()
{

}

GameObjectManager::~GameObjectManager()
{
	// �I�u�W�F�N�g���X�g����Ȃ珈�����I������
	if (game_objects_list.empty())
	{
		return;
	}
	// �I�u�W�F�N�g���X�g���̃I�u�W�F�N�g���폜����
	for (GameObject* obj : game_objects_list)
	{
		obj->Finalize();
		delete obj;
	}
	// ���I�z��̉��
	game_objects_list.clear();

	// ���I�z��̉��
	if (!create_objects.empty())
	{
		create_objects.clear();
	}
	if (!destroy_objects.empty())
	{
		destroy_objects.clear();
	}
}

void GameObjectManager::CheckCreateObject()
{
	// ��������I�u�W�F�N�g������΁A�I�u�W�F�N�g���X�g���ɑ}������
	if (!create_objects.empty())
	{
		for (GameObject* obj : create_objects)
		{
			// ���C���[������ɏ��Ԃ����ւ���
			int z_layer = obj->GetZLayer();
			// �I�u�W�F�N�g���X�g�̐擪
			std::vector<GameObject*>::iterator itr = game_objects_list.begin();
			// ���X�g�̖����ɂȂ�܂ő�������
			for (; itr != game_objects_list.end(); itr++)
			{
				// Z���C���[���傫���ꏊ�ɗv�f��ǉ�����
				// �� itr->ZLayer{1, 1, 2, 3}�Az_layer = 2 �̎�
				//    itr->ZLayer{1, 1, 2, z_layer, 3}�Ƃ���
				if (z_layer < (*itr)->GetZLayer())
				{
					break;
				}
			}
			// ���X�g�̓r���ɑ}������
			game_objects_list.insert(itr, obj);
		}
		// �������X�g���������
		create_objects.clear();
	}
}

void GameObjectManager::CheckDestroyObject()
{
	// �j�����X�g������łȂ��ꍇ�A���X�g���̃I�u�W�F�N�g��j������
	if (!destroy_objects.empty())
	{
		for (GameObject* obj : destroy_objects)
		{
			std::vector<GameObject*>::iterator itr = game_objects_list.begin();	// �I�u�W�F�N�g���X�g�̐擪
			// ���X�g�̖����ɂȂ�܂ő�������
			for (; itr != game_objects_list.end(); itr++)
			{
				// ���X�g���ɂ���΁A�폜����
				if ((*itr) == obj)
				{
					game_objects_list.erase(itr);
					obj->Finalize();
					delete obj;
					break;
				}
			}
		}
		// ���I�z��̊J��
		destroy_objects.clear();
	}
}

const std::vector<GameObject*>& GameObjectManager::GetObjectList() const
{
	return game_objects_list;
}

void GameObjectManager::HitCheck(GameObject* a, GameObject* b)
{
	// �k���|�`�F�b�N
	if (a == nullptr || b == nullptr)
	{
		return;
	}

	Collision a_col = a->GetCollision();
	Collision b_col = b->GetCollision();
	Vector2D a_loc = a->GetLocation();
	Vector2D b_loc = b->GetLocation();

	if (a_col.IsCheckHitTarget(b_col.object_type) || b_col.IsCheckHitTarget(a_col.object_type))
	{
		if (IsCheckCollision(a_col, b_col, a_loc, b_loc))
		{
			a->OnHitCollision(b);
			b->OnHitCollision(a);
		}
	}

}


bool GameObjectManager::IsCheckCollision(Collision a_col, Collision b_col, Vector2D a_loc, Vector2D b_loc)
{
	bool value = false;

	//2�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_sum = (a_col.box_size + b_col.box_size) / 2.0f;

	// 2�̃I�u�W�F�N�g�̋������擾
	Vector2D distance = a_loc - b_loc;

	//�������傫�����傫���ꍇ�AHit����Ƃ���
	if ((fabs(distance.x) < box_sum.x) && (fabs(distance.y) < box_sum.y))
	{
		value = true;
	}

	return value;
}