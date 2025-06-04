#pragma once

#include"../Shot.h"
#include "../../Character/Player/PlayerStats.h"

class PlayerShot : public Shot
{
protected:

private:
	float screen_velocity;		// ƒXƒNƒŠ[ƒ“ˆÚ“®—Ê
	int Color;
	int Shotmode;
	float attack_power;

	struct PlayerStats player_stats;

public:
	PlayerShot();
	~PlayerShot();

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
	void Animation();
	void ShotModeChange();
	void SetAngle(float degree);

	void SetPlayerStats(struct PlayerStats player_stats)
	{
		this->player_stats = player_stats;
	}
};