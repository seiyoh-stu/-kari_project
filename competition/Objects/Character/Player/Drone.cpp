#include "Drone.h"
#include"../../../Utility/InputManager.h"
#include "UserTemplate.h"

Drone::Drone() : 
	rotation_angle(0.0f),
	shot_timer(0.3f),
	SHOT_INTERVAL(0.75f),
	drone_hp(1)
{

	ResourceManager* rm = ResourceManager::GetInstance();
	
	// 座標
	location = Vector2D(D_WIN_MAX_X / 2, D_WIN_MAX_Y / 2);
	// コリジョン設定
	collision.is_blocking = true;
	collision.box_size = Vector2D(15, 15);
	collision.object_type = eObjectType::eBlockDrone;
	collision.hit_object_type.push_back(eObjectType::eEnemy);
	collision.hit_object_type.push_back(eObjectType::eEnemyShot);
	// 画像設定
	// レイヤー設定
	z_layer = 2;
	// 可動性設定
	is_mobility = true;
	// 音源取得

}

Drone::~Drone()
{

}

void Drone::Initialize()
{
	//画像読み込み
	//image = LoadGraph("Resource/Images/player/player.png");
}

void Drone::Update(float delta_seconds)
{
	if (shot_timer > 0.0f)
	{
		shot_timer -= delta_seconds;
	}

	//InputManager* input = InputManager::GetInstance();
	//if ((InputManager::GetInstance()->GetButton(13) || CheckHitKey(KEY_INPUT_B)) && shot_timer <= 0.0f)
	if (shot_timer <= 0.0f)	//自動で撃つ場合
	{
		PlayerShot* shot = object_manager->CreateGameObject<PlayerShot>(this->location);

		shot_timer = SHOT_INTERVAL;
		player_stats.shot_speed = SHOT_INTERVAL;

	}
}

void Drone::Draw(const Vector2D& screen_offset, bool flip_flag) const
{
	__super::Draw(0.0f, this->flip_flag);
	//DrawBox(location.x - 10, location.y - 10, location.x + 10, location.y + 10, GetColor(255, 0, 0), TRUE);
	DrawCircle(location.x, location.y, 12, GetColor(243, 136, 19), true);
}

void Drone::Finalize()
{

}

void Drone::OnHitCollision(GameObject* hit_object)
{
	eObjectType type = hit_object->GetCollision().object_type;

	switch (type)
	{
	case eNone:
		break;
	case ePlayer:
		break;
	case eEnemy:
		drone_hp--;
		break;
	case ePlayerShot:
		break;
	case eEnemyShot:
		drone_hp--;
		break;
	case eItem:
		break;
	default:
		break;
	}

}