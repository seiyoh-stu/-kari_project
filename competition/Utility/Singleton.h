#pragma once
#include"Dxlib.h"
#include<string>

#define	D_SUCCESS		(0)				// ����
#define	D_FAILURE		(-1)			// ���s

#define D_WIN_MAX_X		float(1280.0)	// �X�N���[���T�C�Y�i���j
#define D_WIN_MAX_Y		float(720.0)	// �X�N���[���T�C�Y�i�����j
#define D_COLOR_BIT		float(32.0)		// �J���[�r�b�g

#define SIZE			float(1.0)		// �摜�{��

#define ��    (3.141592653589793)		//�~����

class Singleton
{
protected:
	Singleton();
	~Singleton();

	Singleton(const Singleton&);

	Singleton& operator = (const Singleton&) = delete;

public:

};