#pragma once
#include "../EnemyBase.h"

class Enemy5 : public EnemyBase
{
private:
    int shot_num;
    float cool_down_2;
    float cool_down_2_count;
public:
    Enemy5();
    ~Enemy5();

    virtual void Initialize() override;
    virtual void Update(float) override;
    virtual void Draw(const Vector2D&, bool) const override;
    virtual void Finalize() override;

    virtual void OnHitCollision(GameObject*) override;

public:
    void Movement(float);
    void Animation();

};