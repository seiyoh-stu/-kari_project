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
/// 初期化処理
/// </summary>
void GameObject::Initialize()
{

}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="delta_second">1フレームあたりの時間</param>
void GameObject::Update(float delta_second)
{

}

/// <summary>
/// 描画処理
/// </summary>
/// <param name="screen_offset">オフセット値</param>
void GameObject::Draw(const Vector2D& screen_offset, bool flip_flag) const
{
	// オフセット値を基に画像の描画を行う
	Vector2D graph_location = this->location + screen_offset;
	DrawRotaGraphF(graph_location.x, graph_location.y, SIZE, 0.0, image, TRUE, flip_flag);
}

/// <summary>
/// 終了時処理
/// </summary>
void GameObject::Finalize()
{

}

//当たり判定通知処理
void GameObject::OnHitCollision(GameObject* hit_object)
{

}

//座標取得処理
const Vector2D& GameObject::GetLocation() const
{
	return location;
}

//座標設定処理
void GameObject::SetLocation(const Vector2D location)
{
	this->location = location;
}

//コリジョン取得処理
const Collision& GameObject::GetCollision() const
{
	return collision;
}

//レイヤー取得処理
const unsigned char GameObject::GetZLayer() const
{
	return z_layer;
}

//可動性取得処理
const bool GameObject::GetMobility() const
{
	return is_mobility;
}

//プレイヤー座標設定処理
void GameObject::SetPlayerLocation(Vector2D location)
{
	if (player_location.x == 0.0f && player_location.y == 0.0f)
	{
		old_player_location = location;
	}
	player_location = location;
}

//プレイヤーステータス設定処理
void GameObject::SetPlayerStats(PlayerStats stats)
{
	player_stats = stats;
}


//AがBを追尾する処理
Vector2D GameObject::Tracking(Vector2D A, Vector2D B)
{
	Vector2D velocity;	//加速度
	float distance;		//距離

	velocity.x = A.x - B.x;
	velocity.y = A.y - B.y;

	distance = sqrt(pow(velocity.x, 2.0) + pow(velocity.y, 2.0));

	velocity.x /= distance;
	velocity.y /= distance;

	velocity *= -1;

	return velocity;

}

//オブジェクトマネージャー設定処理
const GameObjectManager* GameObject::CheckInstance() const
{
	return object_manager;
}
void GameObject::SetInstance(GameObjectManager* instance)
{
	object_manager = instance;
}