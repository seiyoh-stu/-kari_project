#include"DxLib.h"
#include"HpUI.h"

HpUI::HpUI() :
	//hp_table(),
	//hp_bar()
	hp_bar1(0),
	hp_bar2(0),
	hp(0),
	max_hp(0)
{
	// リソース管理インスタンス取得
	ResourceManager* rm = ResourceManager::GetInstance();
	// hp_table = rm->GetImages("Resource/Images/HPUi/Health_Bar_Table.png")[0];
	// hp_bar = rm->GetImages("Resource/Images/HPUi/Health_Dot.png")[0];
	hp_bar1 = rm->GetImages("Resource/Images/HPUi/hp_bar1.png")[0];
	hp_bar2 = rm->GetImages("Resource/Images/HPUi/hp_bar2.png")[0];

	hp_bar1 = rm->GetImages("Resource/Images/HPUi/Health_Dot.png")[0];
	hp_bar2 = rm->GetImages("Resource/Images/HPUi/Armor_Bar_Dot.png")[0];


}

HpUI::~HpUI()
{

}

void HpUI::Initialize()
{

}

void HpUI::Update()
{

}

void HpUI::Draw() const
{
	//// HP最大数の描画(枠)
	//SetDrawBright(0, 0, 0);
	//DrawRotaGraph(50, 30, 1.0, 0, hp_bar1, 1, 0);
	//for (int i = 0; i < max_hp; i++)
	//{
	//	DrawRotaGraph((100 + (i * 45)), 30, 1.0, 0, hp_bar2, 1, 0);
	//}
	//// 現在のHPのバーの描画
	//SetDrawBright(255, 255, 255);
	//if (hp > 0)
	//{
	//	DrawRotaGraph(50, 30, 1.0, 0, hp_bar1, 1, 0);
	//}
	//for (int i = 0; i < hp; i++)
	//{
	//	DrawRotaGraph((100 + (i * 45)), 30, 1.0, 0, hp_bar2, 1, 0);
	//}


	//HP　BOXタイプ
	for (int i = 0; i < hp; i++)
	{
		DrawRotaGraph((50 + (i * 43)), 39, 1.35, 0, hp_bar1, 1, 0);
	}
	if(hp >= 4)
	{
		for (int i = 3; i < hp; i++)
		{
			DrawRotaGraph((50 + (i * 43)), 39, 1.35, 0, hp_bar2, 1, 0);
		}
	}
}

void HpUI::Finalize()
{

}

void HpUI::SetHp(int hp, int max_hp)
{
	this->hp = hp;
	this->max_hp = max_hp;
	return ;
}
