#pragma once

#include"../Character.h"
#include"../../Shot/PlayerShot/PlayerShot.h"
#include "Drone.h"
#include"PlayerStats.h"

class Player : public Character
{
protected:
	bool is_dead;
	bool is_visible;
	int death_image_index;

private:
	float screen_velocity;		// ÉXÉNÉäÅ[Éìà⁄ìÆó 

	float shot_timer;
	float SHOT_INTERVAL;
	float invincible_timer;

	PlayerStats player_stats = {};

	Drone* drone;
	Vector2D old_location[20];

	int image;
	bool is_invincible;
	int soundseffect[10];

public:
	bool death_animation_finished;

public:
	Player();
	~Player();

public:
	virtual void Initialize() override;
	virtual void Update(float) override;
	virtual void Draw(const Vector2D&, bool) const override;
	virtual void Finalize() override;

	virtual void OnHitCollision(GameObject*) override;

public:
	Vector2D GetScreenVelocity();
	Vector2D GetVelocity();
	void SetVelocity(Vector2D);

	void Movement(float);
	void Animation(float);

	void AddExperience(float exp);
	void LevelUp();
	void SubtractLife();
	void AddShield(int shield);

	void SetPlayerStats(float attack, int life, int level)
	{
		player_stats.attack_power = attack;
		player_stats.life_count = life;
		player_stats.player_level = level;
	}
	PlayerStats GetPlayerStats() const
	{
		return player_stats;
	}
	void CheckLevelUp();

	void StatsUp(ePowerUp powerup);
};