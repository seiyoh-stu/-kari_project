#pragma once
#include"Singleton.h"
#include"InputManager.h"
#include"../Resource/ResourceManager.h"

class Application : public Singleton
{
private:
	float delta_seconds;
	bool is_finalize;

public:
	Application();
	~Application();

	//����������
	void WakeUp();

	//���s����
	void Run();

	//�I��������
	void Shutdown();

private:
	void UpdateDeltaTime();
};