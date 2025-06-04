#pragma once
#include"../Utility/Singleton.h"
#include"SceneBase.h"

class SceneManager : public Singleton
{
private:
	//���݂̃V�[�����̃|�C���^
	SceneBase* current_scene;

public:
	SceneManager();
	~SceneManager();


	//����������
	void Initialize();

	//�X�V����
	bool Update(float);

	//�`�揈��
	void Graph() const;

	//�I��������
	void Finalize();

private:
	bool ChangeScene(eSceneType);
};