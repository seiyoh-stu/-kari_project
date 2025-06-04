#pragma once
#include "../EnemyBase.h"
class Enemy3: public EnemyBase
{
private:
    Vector2D old_velocity;

public:
    Enemy3();
    ~Enemy3();

    virtual void Initialize() override;
    virtual void Update(float) override;
    virtual void Draw(const Vector2D&, bool) const override;
    virtual void Finalize() override;

    virtual void OnHitCollision(GameObject*) override;

public:
    void Movement(float);
    void Animation();

};

