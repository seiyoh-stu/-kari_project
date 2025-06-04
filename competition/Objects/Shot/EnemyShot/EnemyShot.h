#pragma once

#include"../Shot.h"

class EnemyShot : public Shot
{
protected:

private:
	float screen_velocity;		// ƒXƒNƒŠ[ƒ“ˆÚ“®—Ê

	int birth_count;

	Vector2D old_velocity;

public:
	EnemyShot();
	~EnemyShot();

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

	int image;
	int shot_image[3];
};