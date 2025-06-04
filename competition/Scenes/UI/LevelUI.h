#pragma once
#include"../../Utility/Singleton.h"
#include"../../Resource/ResourceManager.h"

class LevelUI
{	
private:
	int exp;
	int max_exp;
	int level_ui1;
	int level_ui2;
	int level;
	std::vector<int> level_bar;			// ���x�������̉摜

public:
	LevelUI();
	~LevelUI();

public:
	void Initialize();			//����������
	void Update();				//�X�V����
	void Draw() const;			//�`�揈��
	void Finalize();			//�I������

	void SetExperience(int, int);	// �v���C���[���瑝�����ꂽ���x��(�݌v)�̎擾����
};