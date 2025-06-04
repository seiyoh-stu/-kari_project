#pragma once
#include"Dxlib.h"
#include<string>

#define	D_SUCCESS		(0)				// 成功
#define	D_FAILURE		(-1)			// 失敗

#define D_WIN_MAX_X		float(1280.0)	// スクリーンサイズ（幅）
#define D_WIN_MAX_Y		float(720.0)	// スクリーンサイズ（高さ）
#define D_COLOR_BIT		float(32.0)		// カラービット

#define SIZE			float(1.0)		// 画像倍率

#define π    (3.141592653589793)		//円周率

class Singleton
{
protected:
	Singleton();
	~Singleton();

	Singleton(const Singleton&);

	Singleton& operator = (const Singleton&) = delete;

public:

};