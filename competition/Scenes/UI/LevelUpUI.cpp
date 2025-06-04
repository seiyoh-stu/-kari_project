#include"LevelUpUI.h"

LevelUpUI::LevelUpUI() :
	old_flag(),
	cursor(0),
	player_stats(),
	window(),
	power(),
	lot(),
	lot_str(),
	lot_icon(),
	power_icon()
{
	//リソース管理インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();

	window[0] = rm->GetImages("Resource/Images/LevelUpUi/Window.png")[0];
	window[1] = rm->GetImages("Resource/Images/LevelUpUi/Header.png")[0];
	window[2] = rm->GetImages("Resource/Images/LevelUpUi/Table_01.png")[0];
	window[3] = rm->GetImages("Resource/Images/LevelUpUi/window_3.png")[0];

	/*power[0] = rm->GetImages("Resource/Images/LevelUpUi/Health.png")[0];
	power[1] = rm->GetImages("Resource/Images/LevelUpUi/Damage.png")[0];
	power[2] = rm->GetImages("Resource/Images/LevelUpUi/Speed.png")[0];
	power[3] = rm->GetImages("Resource/Images/LevelUpUi/X100.png")[0];*/

	power_icon[0] = rm->GetImages("Resource/Images/UpGrade_Icon/hp.png")[0];
	power_icon[1] = rm->GetImages("Resource/Images/UpGrade_Icon/power.png")[0];
	power_icon[2] = rm->GetImages("Resource/Images/UpGrade_Icon/speed.png")[0];
	power_icon[3] = rm->GetImages("Resource/Images/UpGrade_Icon/shot_speed.png")[0];
	power_icon[4] = rm->GetImages("Resource/Images/UpGrade_Icon/shot_size.png")[0];
	power_icon[5] = rm->GetImages("Resource/Images/UpGrade_Icon/three_way.png")[0];
	power_icon[6] = rm->GetImages("Resource/Images/UpGrade_Icon/drone.png")[0];
}

LevelUpUI::~LevelUpUI()
{

}

void LevelUpUI::Initialize()
{
	for (int i = 0; i < LOT_MAX; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			bility[i] += proba[j];
		}
	}
}

void LevelUpUI::Update(bool flag, PlayerStats stats)
{
	player_stats = stats;

	//強化内容抽選会
	if (old_flag != flag)
	{
		//抽選
		int nums[3] = { 0,0,0 };
		Lottery(nums);
		for (int i = 0; i < 3; i++)
		{
			//抽選結果
			switch (nums[i])
			{
			case STATS_HP:
				lot[i] = ePowerUp::eHp;
				break;
			case STATS_DAMAGE:
				lot[i] = ePowerUp::eDamage;
				break;
			case STATS_SPEED:
				lot[i] = ePowerUp::eSpeed;
				break;
			case WAPON_SPEED:
				lot[i] = ePowerUp::eShotspeed;
				break;
			case WAPON_SIZE:
				lot[i] = ePowerUp::eShot_HitRange;
				break;
			case WAPON_3WAY:
				lot[i] = ePowerUp::eThreeway;
				break;
			case WAPON_DRONE:
				lot[i] = ePowerUp::eDrone;
				break;
			default:
				break;
			}

			//画像変更
			lot_str[i] = power[nums[i]];
			lot_icon[i] = power_icon[nums[i]];
		}
	}
	old_flag = flag;
}

void LevelUpUI::Draw() const
{

	float choice_size[3] = { 1.0,1.0,1.0 };
	choice_size[cursor] = 1.3;

	int pluse_x = 120;

	//外枠
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	DrawRotaGraph(pluse_x + 640, 360, 0.9, 0, window[0], 1, 0);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraph(pluse_x + 640, 80, 1.0, 0, window[1], 1, 0);
	//内枠
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawRotaGraph(pluse_x + 360, 400, 0.6 * choice_size[0], 0, window[2], 1, 0);
	DrawRotaGraph(pluse_x + 640, 400, 0.6 * choice_size[1], 0, window[2], 1, 0);
	DrawRotaGraph(pluse_x + 920, 400, 0.6 * choice_size[2], 0, window[2], 1, 0);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//強化内容（文字）
	DrawRotaGraph(pluse_x + 360, 440, 0.6 * choice_size[0], 0, lot_str[0], 1, 0);
	DrawRotaGraph(pluse_x + 640, 440, 0.6 * choice_size[1], 0, lot_str[1], 1, 0);
	DrawRotaGraph(pluse_x + 920, 440, 0.6 * choice_size[2], 0, lot_str[2], 1, 0);
	//強化内容（アイコン）
	DrawRotaGraph(pluse_x + 360, 340, 0.5 * choice_size[0], 0, lot_icon[0], 1, 0);
	DrawRotaGraph(pluse_x + 640, 340, 0.5 * choice_size[1], 0, lot_icon[1], 1, 0);
	DrawRotaGraph(pluse_x + 920, 340, 0.5 * choice_size[2], 0, lot_icon[2], 1, 0);


	//現在ステータス描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	DrawRotaGraph(70, 400, 0.4, 0, window[3], 1, 0);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	int font = 40;
	SetFontSize(font);
	DrawFormatString(10, 130, GetColor(255, 255, 255), "Level  %d", player_stats.player_level);
	font = 37;
	SetFontSize(font);
	int y = 160;
	DrawFormatString(10, y + (font * 1), GetColor(255, 255, 255), "hp");
	DrawFormatString(60, y + (font * 2), GetColor(255, 255, 255), "%d", player_stats.life_count);
	DrawFormatString(10, y + (font * 3), GetColor(255, 255, 255), "power");
	DrawFormatString(60, y + (font * 4), GetColor(255, 255, 255), "%.2f", player_stats.attack_power);
	DrawFormatString(10, y + (font * 5), GetColor(255, 255, 255), "speed");
	DrawFormatString(60, y + (font * 6), GetColor(255, 255, 255), "%.2f", player_stats.move_speed);

	y += font * 6 + 15;
	DrawFormatString(10, y + (font * 1), GetColor(255, 255, 255), "--shot--");
	DrawFormatString(10, y + (font * 2), GetColor(255, 255, 255), "cool_time");
	DrawFormatString(60, y + (font * 3), GetColor(255, 255, 255), "%.2f", player_stats.shot_speed);
	DrawFormatString(10, y + (font * 4), GetColor(255, 255, 255), "hit_range");
	DrawFormatString(60, y + (font * 5), GetColor(255, 255, 255), "%.2f", float(player_stats.player_shot_hitrange_up));
}

void LevelUpUI::Finalize()
{

}

int LevelUpUI::Probability()
{
	int value = rand() % 100;

	if (value < bility[STATS_HP])
	{
		return STATS_HP;
	}
	else if (value < bility[STATS_DAMAGE])
	{
		return STATS_DAMAGE;
	}
	else if (value < bility[STATS_SPEED])
	{
		return STATS_SPEED;
	}
	else if(value < bility[WAPON_SPEED])
	{
		return WAPON_SPEED;
	}
	else if (value < bility[WAPON_SIZE])
	{
		return WAPON_SIZE;
	}
	else if(value < bility[WAPON_3WAY])
	{
		if (player_stats.threeway_flag)
		{
			//取得済みの場合それ以外がでるまでループ
			int loop = Probability();
			while (loop == WAPON_3WAY)
			{
				loop = Probability();
			}
			return loop;
		}
		return WAPON_3WAY;
	}
	else
	{
		if (player_stats.drone_count > 0)
		{
			//取得済みの場合それ以外がでるまでループ
			int loop = Probability();
			while (loop == WAPON_DRONE)
			{
				loop = Probability();
			}
			return loop;
		}
		return WAPON_DRONE;
	}

}

void LevelUpUI::Lottery(int* nums)
{
	nums[0] = Probability();

	while (nums[0] == nums[1])
	{
		nums[1] = Probability();
	}

	while (nums[0] == nums[2] || nums[1] == nums[2])
	{
		nums[2] = Probability();
	}
}

ePowerUp LevelUpUI::GetLottery()
{
	return lot[cursor];
}