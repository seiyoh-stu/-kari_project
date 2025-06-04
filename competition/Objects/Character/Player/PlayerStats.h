#pragma once
enum ePowerUp
{
	eHp,
	eDamage,
	eSpeed,
	eShotspeed,
	eThreeway,
	eShot_HitRange,
	eDrone
};

struct PlayerStats
{
	float attack_power = 1.0f;
	float move_speed = 0.0f;
	float shot_speed = 0.3f;
	int life_count = 3;
	int Shield_count = 3;
	int player_level = 1;
	int player_hp_max = 6;
	int player_shot_hitrange_up = 0;
	int drone_count = 0;
	bool threeway_flag = false;
	bool drone_flag = false;



	// åoå±ílä÷òA
	int current_exp = 0;
	int next_level_exp = 100;
};
