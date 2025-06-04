#include"GameObjectManager.h"

GameObjectManager::GameObjectManager() :
	create_objects(),
	destroy_objects(),
	game_objects_list()
{

}

GameObjectManager::~GameObjectManager()
{
	// オブジェクトリストが空なら処理を終了する
	if (game_objects_list.empty())
	{
		return;
	}
	// オブジェクトリスト内のオブジェクトを削除する
	for (GameObject* obj : game_objects_list)
	{
		obj->Finalize();
		delete obj;
	}
	// 動的配列の解放
	game_objects_list.clear();

	// 動的配列の解放
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
	// 生成するオブジェクトがあれば、オブジェクトリスト内に挿入する
	if (!create_objects.empty())
	{
		for (GameObject* obj : create_objects)
		{
			// レイヤー情報を基に順番を入れ替える
			int z_layer = obj->GetZLayer();
			// オブジェクトリストの先頭
			std::vector<GameObject*>::iterator itr = game_objects_list.begin();
			// リストの末尾になるまで走査する
			for (; itr != game_objects_list.end(); itr++)
			{
				// Zレイヤーが大きい場所に要素を追加する
				// 例 itr->ZLayer{1, 1, 2, 3}、z_layer = 2 の時
				//    itr->ZLayer{1, 1, 2, z_layer, 3}とする
				if (z_layer < (*itr)->GetZLayer())
				{
					break;
				}
			}
			// リストの途中に挿入する
			game_objects_list.insert(itr, obj);
		}
		// 生成リストを解放する
		create_objects.clear();
	}
}

void GameObjectManager::CheckDestroyObject()
{
	// 破棄リスト内が空でない場合、リスト内のオブジェクトを破棄する
	if (!destroy_objects.empty())
	{
		for (GameObject* obj : destroy_objects)
		{
			std::vector<GameObject*>::iterator itr = game_objects_list.begin();	// オブジェクトリストの先頭
			// リストの末尾になるまで走査する
			for (; itr != game_objects_list.end(); itr++)
			{
				// リスト内にあれば、削除する
				if ((*itr) == obj)
				{
					game_objects_list.erase(itr);
					obj->Finalize();
					delete obj;
					break;
				}
			}
		}
		// 動的配列の開放
		destroy_objects.clear();
	}
}

const std::vector<GameObject*>& GameObjectManager::GetObjectList() const
{
	return game_objects_list;
}

void GameObjectManager::HitCheck(GameObject* a, GameObject* b)
{
	// ヌルポチェック
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

	//2つのオブジェクトの当たり判定の大きさを取得
	Vector2D box_sum = (a_col.box_size + b_col.box_size) / 2.0f;

	// 2つのオブジェクトの距離を取得
	Vector2D distance = a_loc - b_loc;

	//距離より大きさが大きい場合、Hit判定とする
	if ((fabs(distance.x) < box_sum.x) && (fabs(distance.y) < box_sum.y))
	{
		value = true;
	}

	return value;
}