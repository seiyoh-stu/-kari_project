#pragma once

#include<vector>
#include<stdio.h>

#include"DxLib.h"
#include"../Utility/Singleton.h"
#include"../Utility/Vector2D.h"

enum class eSceneType
{
	eTitle,
	eInGame,
	eResult,
	eRanking,
	eExit
};

class SceneBase
{
protected:
	Vector2D screen_offset;	// スクリーンオフセット

public:
	SceneBase()
	{

	}
	virtual ~SceneBase()
	{
		// 解放忘れ防止
		Finalize();
	}

public:
	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize()
	{
	}

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="delta_second">1フレーム当たりの時間</param>
	/// <returns>次のシーンタイプ情報</returns>
	virtual eSceneType Update(const float& delta_second)
	{
		// 現在のシーン情報を返却する
		return GetNowSceneType();
	}

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() const
	{

	}

	/// <summary>
	/// 終了時処理
	/// </summary>
	virtual void Finalize()
	{
		
	}

	/// <summary>
	/// 現在のシーンタイプ取得処理
	/// </summary>
	/// <returns>現在のシーンタイプ情報</returns>
	virtual eSceneType GetNowSceneType() const = 0;

	/// <summary>
	/// スクリーンオフセット情報取得処理
	/// </summary>
	/// <returns>スクリーンオフセット値</returns>
	const Vector2D GetScreenOffset() const
	{
		return screen_offset;
	}
};