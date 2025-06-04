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
		// 生成するゲームオブジェクトクラスを動的確保
		T* new_instance = new T();
		// GameObjectを継承しているか確認
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);
		// エラーチェック
		if (new_object == nullptr)
		{
			// 動的確保したメモリの開放
			delete new_instance;
			// 例外テキストを通知
			throw std::string("ゲームオブジェクトが生成できませんでした");
			return nullptr;
		}
		// 位置情報の設定
		new_object->SetLocation(generate_location);
		// 初期化処理
		new_object->Initialize();
		// 生成オブジェクトリストの末尾に格納する
		create_objects.push_back(new_object);
		// 生成したゲームオブジェクトのポインタを返す
		return new_instance;
	}

	void DestroyGameObject(GameObject* target)
	{
		// ヌルポチェック
		if (target == nullptr)
		{
			return;
		}

		// 破棄オブジェクトリスト内にあれば、追加しない
		for (GameObject* obj : destroy_objects)
		{
			if (obj == target)
			{
				return;
			}
		}

		// 破棄を行うオブジェクトリストに追加する
		destroy_objects.push_back(target);
	}

public:
	// 当たり判定確認処理
	void HitCheck(GameObject*, GameObject*);
	bool IsCheckCollision(Collision, Collision, Vector2D, Vector2D);
};