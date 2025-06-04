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

	//‰Šú‰»ˆ—
	void WakeUp();

	//Àsˆ—
	void Run();

	//I—¹ˆ—
	void Shutdown();

private:
	void UpdateDeltaTime();
};