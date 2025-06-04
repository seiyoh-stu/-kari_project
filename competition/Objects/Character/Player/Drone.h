#pragma once

#include "../Character.h"
#include"../../Shot/PlayerShot/PlayerShot.h"
#include"PlayerStats.h"


class Drone : public Character
{
protected:

private:
	int Color;
	float rotation_angle;
	struct PlayerStats player_stats_copy;
	float shot_timer;
	float SHOT_INTERVAL;


public:
	int drone_hp;

public:
	Drone();
	~Drone();

public:
	virtual void Initialize() override;
	virtual void Update(float) override;
	virtual void Draw(const Vector2D&, bool) const override;
	virtual void Finalize() override;

	virtual void OnHitCollision(GameObject*) override;

public:
	// ドローン用にプレイヤーの現在のステータスのコピーを設定します
	void SetPlayerStatsCopy(const PlayerStats player_stats)
	{
		this->player_stats_copy = player_stats;
	}
	// プレイヤーによって呼び出され、ドローンに弾を発射させます
	//void Shoot();

	// 回転角度を設定する関数
	void SetRotationAngle(float angle)
	{
		rotation_angle = angle;
	}
	// 回転角度を取得する関数
	float GetRotationAngle() const { return rotation_angle; }
};