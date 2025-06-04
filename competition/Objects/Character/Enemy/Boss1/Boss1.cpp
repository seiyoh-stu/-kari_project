#include "Boss1.h"

Boss1::Boss1()
{
	// コリジョン設定
	collision.is_blocking = true;
	collision.box_size = Vector2D(150, 150);						//当たり判定の大きさ
	collision.object_type = eObjectType::eEnemy;					//オブジェクトのタイプ
	collision.hit_object_type.push_back(eObjectType::ePlayer);		//ぶつかるオブジェクトのタイプ
	collision.hit_object_type.push_back(eObjectType::ePlayerShot);	//ぶつかるオブジェクトのタイプ
	// 初期スピード
	// speed=200.0f;
	// 画像設定
	// レイヤー設定
	z_layer = 2;
	// 可動性設定
	is_mobility = true;

	//最大HP設定
	max_hp = 150;
	hp = float(max_hp);
}

Boss1::~Boss1()
{
}

void Boss1::Initialize()
{
	//画像読み込み
	image = LoadGraph("Resource/Images/enemy/ship3.png");
}

void Boss1::Update(float delta_seconds)
{
	Movement(delta_seconds);
	Animation();

	//HP割合計算
	ratio = (hp * 100) / max_hp;
	if (ratio <= 0)
	{
		ratio = 0;
	}

	//時間経過
	shot_timer += delta_seconds;

	EnemyShot* shot;

	//攻撃
	if (hp > 0 && shot_timer >= 0.5f)
	{
		switch (atack_pattern)
		{
		case 0:
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y));
			shot->SetShotType(eEnemy1);
			atack_pattern = 1;
			break;
		case 1:
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y + 150));
			shot->SetShotType(eEnemy1);
			shot = object_manager->CreateGameObject<EnemyShot>(Vector2D(location.x, location.y - 150));
			shot->SetShotType(eEnemy1);
			atack_pattern = 2;
			break;
		case 2:
			object_manager->CreateGameObject<Enemy3>(Vector2D(location.x, location.y + 150));
			object_manager->CreateGameObject<Enemy3>(Vector2D(location.x, location.y - 150));
			atack_pattern = 0;
			break;
		default:
			break;
		}

		//タイマーリセット
		shot_timer = 0.0f;
	}

	//死
	if (hp <= 0.0f)
	{
		death_count -= (delta_seconds * 1.0f);
	}
	if (death_count <= 0.0)
	{
		death_flag = true;
	}
	if (death_flag)
	{
		transparency--;
	}

}

void Boss1::Draw(const Vector2D& screen_offset, bool flip_flag) const
{
	if (image != -1)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, transparency);
		DrawRotaGraphF(location.x, location.y, 10.0f, 0.0f, image, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	// 現在のHPのバーの描画
	if(ratio != 0)
	{
		DrawRotaGraph(100, 670, 1.0, 0, hp_bar1, 1, 0);
	}
	for (int i = 0; i < ratio; i++)
	{
		DrawRotaGraph((105 + (i * 11)), 670, 1.0, 0, hp_bar2, 1, 0);
	}
	if (ratio != 0)
	{
		SetFontSize(26);
		DrawFormatString(7, 657, GetColor(255, 0, 255), "BOSS");
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Boss1::Finalize()
{
}

void Boss1::OnHitCollision(GameObject* hit_object)
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
}

void Boss1::Movement(float delta_seconds)
{
	float speed = 200.0f;

	location += velocity * speed * delta_seconds;
}

void Boss1::Animation()
{
}

int Boss1::GetBoss1Hp()
{
	return ratio;
}

bool Boss1::GetDeathFlag()
{
	return death_flag;
}