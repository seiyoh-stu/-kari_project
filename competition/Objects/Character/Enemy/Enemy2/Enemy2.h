#pragma once
#include "../EnemyBase.h"

class Enemy2 : public EnemyBase
{
private:
    bool trans = false;
public:
    Enemy2();
    ~Enemy2();

    virtual void Initialize() override;
    virtual void Update(float) override;
    virtual void Draw(const Vector2D&, bool) const override;
    virtual void Finalize() override;

    virtual void OnHitCollision(GameObject*) override;

public:
    void Movement(float);
    void Animation();
    
    void SetTrans();

};