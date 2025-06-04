#pragma once
#include"../SceneBase.h"

class TitleScene : public SceneBase
{
protected:

private:
	int menu_num;			// メニューカーソル番号
	bool help;				// ヘルプが開かれてるかどうか?
	bool is_button;			// ボタンが操作できるかどうか?
	int back_ground_sound;	// BGM

public:
	TitleScene();
	~TitleScene();

public:
	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second);
	virtual void Draw() const override;
	virtual void Finalize() override;

public:
	virtual eSceneType GetNowSceneType() const override;
};