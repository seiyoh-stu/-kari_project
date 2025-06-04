#pragma once
#include "../SceneBase.h"

class RankingScene : public SceneBase
{
protected:

public:
	RankingScene();
	~RankingScene();

public:
	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second);
	virtual void Draw() const override;
	virtual void Finalize() override;

public:
	virtual eSceneType GetNowSceneType() const override;

};