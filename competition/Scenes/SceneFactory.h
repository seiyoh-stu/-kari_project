#pragma once
#include"SceneBase.h"

class SceneFactory
{
public:
	static class SceneBase* CreateScene(enum eSceneType);
};