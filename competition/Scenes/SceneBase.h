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
	Vector2D screen_offset;	// �X�N���[���I�t�Z�b�g

public:
	SceneBase()
	{

	}
	virtual ~SceneBase()
	{
		// ����Y��h�~
		Finalize();
	}

public:
	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize()
	{
	}

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
	/// <returns>���̃V�[���^�C�v���</returns>
	virtual eSceneType Update(const float& delta_second)
	{
		// ���݂̃V�[������ԋp����
		return GetNowSceneType();
	}

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw() const
	{

	}

	/// <summary>
	/// �I��������
	/// </summary>
	virtual void Finalize()
	{
		
	}

	/// <summary>
	/// ���݂̃V�[���^�C�v�擾����
	/// </summary>
	/// <returns>���݂̃V�[���^�C�v���</returns>
	virtual eSceneType GetNowSceneType() const = 0;

	/// <summary>
	/// �X�N���[���I�t�Z�b�g���擾����
	/// </summary>
	/// <returns>�X�N���[���I�t�Z�b�g�l</returns>
	const Vector2D GetScreenOffset() const
	{
		return screen_offset;
	}
};