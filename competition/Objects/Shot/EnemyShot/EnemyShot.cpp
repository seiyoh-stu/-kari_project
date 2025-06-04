#include"EnemyShot.h"
#include"../../../Utility/InputManager.h"

EnemyShot::EnemyShot() :
	screen_velocity(0.0),
	birth_count(800),
	old_velocity(0.0f)
{

	//リソース管理インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	// 座標
	// コリジョン設定
	collision.is_blocking = true;
	collision.box_size = Vector2D(10, 10);
	collision.object_type = eObjectType::eEnemyShot;
	collision.hit_object_type.push_back(eObjectType::ePlayer);
	// 画像設定
	// レイヤー設定
	z_layer = 3;
	// 可動性設定
	is_mobility = true;

}

EnemyShot::~EnemyShot()
{

}

void EnemyShot::Initialize()
{
	//画像読み込み
	shot_image[0] = LoadGraph("Resource/Images/enemy_shot/shot1.png");

	shot_image[1] = LoadGraph("Resource/Images/enemy_shot/shot2.png");

	shot_image[2] = LoadGraph("Resource/Images/enemy_shot/shot3.png");
}

void EnemyShot::Update(float delta_seconds)
{
	Movement(delta_seconds);

	Animation();
}

void EnemyShot::Draw(const Vector2D& screen_offset, bool flip_flag) const
{
	__super::Draw(0.0f, this->flip_flag);

	int image_to_draw = -1;

	switch (shot_type)
	{
	case ePlayer1:
		break;
	case ePlayer2:
		break;
	case ePlayer3:
		break;
	case eEnemy1:
		image_to_draw = shot_image[0];
		break;
	case eEnemy2:
		image_to_draw = shot_image[2];
		break;
	case eEnemy3:
		image_to_draw = shot_image[2];
		break;
	case eEnemy4:
		image_to_draw = shot_image[1];
		break;
	case eEnemy5:
		image_to_draw = shot_image[1];
		break;
	default:
		break;
	}

	if (image_to_draw != -1)
	{
		DrawRotaGraph(location.x, location.y, 1.5, 0, image_to_draw,TRUE);
	}
	
}

void EnemyShot::Finalize()
{

}

void EnemyShot::OnHitCollision(GameObject* hit_object)
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

Vector2D EnemyShot::GetScreenVelocity()
{
	Vector2D value = 0.0f;
	value.x = screen_velocity;
	screen_velocity = 0.0f;
	return value;
}

Vector2D EnemyShot::GetVelocity()
{
	return this->velocity;
}

void EnemyShot::SetVelocity(Vector2D velocity)
{
	this->velocity += velocity;
}

void EnemyShot::Movement(float delta_seconds)
{
	// 移動スピード
	float speed = 200.0f;
	// 移動方向
	Vector2D direction = 0.0f;


	switch (shot_type)
	{
	case eEnemy1:	//真左
		velocity.x = -1.0f;
		break;
	case eEnemy2:	//真上
		velocity.y = -1.0f;
		break;
	case eEnemy3:	//真下
		velocity.y = 1.0f;
		break;
	case eEnemy4:	//自機狙い
		if(location.x > old_player_location.x)
		{
			velocity = Tracking(location, old_player_location);
			old_velocity = velocity;
		}
		else
			velocity = old_velocity;
		break;
	case eEnemy5:	//グネグネ
		velocity.x = -1.2f;
		birth_count++;
		if (shot_type == eEnemy2 && birth_count > 800)
		{
			birth_count = 0;
			if (velocity.y < 0)
				velocity.y = 1.5f;
			else
				velocity.y = -1.5f;
		}
		break;
	default:
		break;
	}

	
	//位置座標を加速度分減らす
	location += velocity * speed * delta_seconds;

}

void EnemyShot::Animation()
{

}