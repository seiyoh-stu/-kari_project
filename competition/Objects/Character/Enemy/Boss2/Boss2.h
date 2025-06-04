#pragma once
#include "../EnemyBase.h"
#include "../Enemy2/Enemy2.h"
#include "../Enemy4/Enemy4.h"

class Boss2 : public EnemyBase
{
private:

public:
    Boss2();
    ~Boss2();

    virtual void Initialize() override;
    virtual void Update(float) override;
    virtual void Draw(const Vector2D&, bool) const override;
    virtual void Finalize() override;

    virtual void OnHitCollision(GameObject*) override;

public:
    void Movement(float);
    void Animation();

    int GetBoss2Hp();
    bool GetDeathFlag();
};

