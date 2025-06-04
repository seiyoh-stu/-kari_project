#include"ExperiencePoints.h"

ExperiencePoints::ExperiencePoints() :
	track_flag(false)
{
	//リソース管理インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	// コリジョン設定
	collision.is_blocking = true;
	collision.box_size = Vector2D(20, 20);
	collision.object_type = eObjectType::eItem;
	collision.hit_object_type.push_back(eObjectType::ePlayer);
	// 画像設定
	
	//スピード設定
	speed = 200.0f;
	// レイヤー設定
	z_layer = 2;
	// 可動性設定
	is_mobility = true;

	item_type = eItemType::eExp;
}

ExperiencePoints::~ExperiencePoints()
{

}

void ExperiencePoints::Initialize()
{

}

void ExperiencePoints::Update(float delta_seconds)
{
	Movement(delta_seconds);

	Animation();
}

void ExperiencePoints::Draw(const Vector2D& screen_offset, bool flip_flag) const
{
	__super::Draw(0.0f, this->flip_flag);

	//DrawBox(location.x - 10, location.y - 10, location.x + 10, location.y + 10, GetColor(200, 100, 100), TRUE);
	DrawCircle(location.x, location.y, 10, GetColor(0, 200, 0), TRUE, TRUE);
}

void ExperiencePoints::Finalize()
{

}

void ExperiencePoints::OnHitCollision(GameObject* hit_object)
{
	eObjectType type = hit_object->GetCollision().object_type;

	switch (type)
	{
	case eNone:
		break;
	case ePlayer:
		object_manager->DestroyGameObject(this);
		break;
	case eEnemy:
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

void ExperiencePoints::Movement(float delta_seconds)
{
	velocity.x = -1.0f;
	//距離
	float distance;
	distance = sqrt(pow((location.x - player_location.x), 2.0) + pow((location.y - player_location.y), 2.0));

	if (distance < 150.0f)
	{
		track_flag = true;
	}
	if (track_flag)
	{
		velocity = (Tracking(location, player_location)) * 4.0;
	}

	//位置座標を加速度分減らす
	location += velocity * speed * delta_seconds;
}

void ExperiencePoints::Animation()
{

}