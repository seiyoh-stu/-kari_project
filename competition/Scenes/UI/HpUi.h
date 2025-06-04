#pragma once
#include"../../Utility/Singleton.h"
#include"../../Resource/ResourceManager.h"

class HpUI
{
private:
	// int hp_table;
	int hp_bar1;			// HP�o�[(���[)
	int hp_bar2;			// HP�o�[(�E�[)
	int hp;					// 
	int max_hp;				// �ő�HP
public:
	HpUI();
	~HpUI();

public:
	void Initialize();			//����������
	void Update();				//�X�V����
	void Draw() const;			//�`�揈��
	void Finalize();			//�I������

	void SetHp(int, int);
};