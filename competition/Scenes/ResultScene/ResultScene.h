#pragma once
#include"../SceneBase.h"

class ResultScene : public SceneBase
{
protected:
	enum class selectedbutton 
	{
		Title,
		End
	};

	selectedbutton m_selectedbutton;
public:
	ResultScene();
	~ResultScene();

public:
	int menu_num;
	bool is_button;

	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second);
	virtual void Draw() const override;
	virtual void Finalize() override;

public:
	virtual eSceneType GetNowSceneType() const override;
};