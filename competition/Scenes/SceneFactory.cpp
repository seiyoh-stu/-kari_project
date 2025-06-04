#include"SceneFactory.h"
#include"SceneBase.h"

#include"TitleScene/TitleScene.h"
#include"InGameScene/InGameScene.h"
#include"RankingScene/RankingScene.h"
#include"ResultScene/ResultScene.h"

SceneBase* SceneFactory::CreateScene(eSceneType scene)
{
	switch (scene)
	{
	case eSceneType::eTitle:
		return new TitleScene();
		break;
	case eSceneType::eInGame:
		return new InGameScene();
	case eSceneType::eResult:
		return new ResultScene();
		break;
	case eSceneType::eRanking:
		return new RankingScene();
		break;
	case eSceneType::eExit:
		break;
	default:
		break;
	}
	return nullptr;
}