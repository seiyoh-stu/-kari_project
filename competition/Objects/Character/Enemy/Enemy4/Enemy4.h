#pragma once
#include "../EnemyBase.h"
class Enemy4 : public EnemyBase
{
private:
    Vector2D old_velocity;

public:
    Enemy4();
    ~Enemy4();

    virtual void Initialize() override;
    virtual void Update(float) override;
    virtual void Draw(const Vector2D&, bool) const override;
    virtual void Finalize() override;

    virtual void OnHitCollision(GameObject*) override;

public:
    void Movement(float);
    void Animation();

    int move_point = 0;
    std::vector<Vector2D>point;

    float timar = 0.0f;
    int spawn_index;

    bool is_first_Enemy = true;

public:
    void setClone();

    Vector2D Lerp(const Vector2D& a, const Vector2D& b, float t);
    
};