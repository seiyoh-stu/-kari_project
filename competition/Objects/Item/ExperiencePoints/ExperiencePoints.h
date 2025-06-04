#pragma once

#include"../Item.h"

class ExperiencePoints : public Item
{
protected:

private:
	bool track_flag;

public:
	ExperiencePoints();
	~ExperiencePoints();

public:
	virtual void Initialize() override;
	virtual void Update(float) override;
	virtual void Draw(const Vector2D&, bool) const override;
	virtual void Finalize() override;

	virtual void OnHitCollision(GameObject*) override;

	void Movement(float);
	void Animation();

};