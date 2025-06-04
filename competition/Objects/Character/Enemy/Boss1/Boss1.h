#pragma once
#include "../EnemyBase.h"
#include "../Enemy3/Enemy3.h"


class Boss1 : public EnemyBase
{
private:

public:
    Boss1();
    ~Boss1();

    virtual void Initialize() override;
    virtual void Update(float) override;
    virtual void Draw(const Vector2D&, bool) const override;
    virtual void Finalize() override;

    virtual void OnHitCollision(GameObject*) override;

public:
    void Movement(float);
    void Animation();

    int GetBoss1Hp();
    bool GetDeathFlag();
};

