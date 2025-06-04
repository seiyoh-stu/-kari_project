#include "Enemy4.h"

Enemy4::Enemy4()
{
	//リソース管理インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	// コリジョン設定
	collision.is_blocking = true;
	collision.box_size = Vector2D(30, 30);							//当たり判定の大きさ
	collision.object_type = eObjectType::eEnemy;					//オブジェクトのタイプ
	collision.hit_object_type.push_back(eObjectType::ePlayer);		//ぶつかるオブジェクトのタイプ
	collision.hit_object_type.push_back(eObjectType::ePlayerShot);	//ぶつかるオブジェクトのタイプ

	// 画像設定
	// レイヤー設定
	z_layer = 2;
	// 可動性設定
	is_mobility = true;

	// 音源取得(0: 敵が破壊時の音 1: 敵が弾を撃った時の音)
	soundseffect[0] = rm->GetSounds("Resource/Sounds/SoundsEffect/Enemy/enemybreak.mp3");
	soundseffect[1] = rm->GetSounds("Resource/Sounds/SoundsEffect/Enemy/enemyshot.mp3");
}

Enemy4::~Enemy4()
{
}

void Enemy4::Initialize()
{

	speed = 20.0f;

	//画像読み込み
	image = LoadGraph("Resource/Images/enemy/ship4.png");

	hp = 4.0;

	point.clear();
	point.push_back(Vector2D(600, location.y));
	if (location.y < 380)
	{
		point.push_back(Vector2D(800, location.y + 150));
		point.push_back(Vector2D(-100, location.y + 150));
	}
	else
	{
		point.push_back(Vector2D(800, location.y - 150));
		point.push_back(Vector2D(-100, location.y - 150));
	}

	timar = 0.0f;
	spawn_index = 0;
}

void Enemy4::Update(float delta_seconds)
{
	Movement(delta_seconds);
	Animation();


	//if (is_first_Enemy && spawn_index < 2)
	//{
	//	timar += delta_seconds;

	//	if (timar >= 0.5f)
	//	{
	//		timar = 0.0f;
	//		spawn_index++;

	//		/*ずらして出す*/
	//		/*Vector2D spawn_offset(30.0f * spawn_index, 0.0f);
	//		Enemy4* new_enemy = object_manager->CreateGameObject<Enemy4>(location + spawn_offset);

	//		new_enemy->setClone();*/
	//	}
	//}
}

void Enemy4::Draw(const Vector2D& screeen_offset, bool file_flag) const
{
	if (image != -1)
	{
		DrawRotaGraphF(location.x, location.y, 1.0f, 0.0f, image, TRUE);
	}

	// //仮(白い四角を描画する)
	//Vector2D t1 = location - (collision.box_size / 2.0f);
	//Vector2D br = location + (collision.box_size / 2.0f);
	//DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 255, 255), TRUE);
	//DrawString(t1.x, t1.y, "3", GetColor(0, 0, 0), TRUE);
}

void Enemy4::Finalize()
{

}

void Enemy4::OnHitCollision(GameObject* hit_object)
{
	eObjectType type = hit_object->GetCollision().object_type;

	switch (type)
	{
	case eNone:
		break;
	case ePlayer:
		break;
	case eEnemy:
		break;
	case ePlayerShot:
		hp -= player_stats.attack_power / 2;
		break;
	case eEnemyShot:
		break;
	case eItem:
		break;
	default:
		break;
	}
	if (hp <= 0.0)
	{
		object_manager->CreateGameObject< ExperiencePoints>(this->location);
		object_manager->DestroyGameObject(this);
		PlaySoundMem(soundseffect[0], DX_PLAYTYPE_BACK, TRUE);
	}
}

//void Enemy4::Movement(float delta_seconds)
//{
//	if (move_point >= point.size())
//		return;
//
//	Vector2D taget = point[move_point];
//	Vector2D direction = taget - location;
//
//	if (direction.Length() < 5.0f)
//	{
//		move_point++;
//		return;
//	}
//
//	/*if (location.x > old_player_location.x)
//	{
//		velocity = Tracking(location, old_player_location) * 2;
//		old_velocity = velocity;
//	}
//	else
//		velocity = old_velocity;*/
//
//
//	direction.Normalize();
//	velocity = direction;
//	
//
//	location += velocity * delta_seconds;
//}


void Enemy4::Movement(float delta_seconds)
{
	if (move_point >= point.size())
		return;

	Vector2D target = point[move_point];
	Vector2D to_target = target - location;

	// 目標との距離が5以下なら次のポイントへ
	if (to_target.Length() < 5.0f)
	{
		move_point++;
		return;
	}

	// 方向の正規化（目的地への方向）
	Vector2D desired_velocity = to_target.Normalize() * speed;

	// 今のvelocityとdesired_velocityを補間して滑らかにする（慣性っぽく）
	float smooth_factor = 10.0f; // 数値を上げると応答が速くなる（滑らかさ減）
	velocity = Lerp(velocity, desired_velocity, smooth_factor * delta_seconds);

	// 移動
	location += velocity *speed * delta_seconds;
}


void Enemy4::Animation()
{
}

void Enemy4::setClone()
{
	is_first_Enemy = false;
}

Vector2D Enemy4::Lerp(const Vector2D& a, const Vector2D& b, float t)
{
	return a * (1.0f - t) + b * t;
}


