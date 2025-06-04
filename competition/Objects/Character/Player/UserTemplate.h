#pragma once

/*
* ��Βl�ɕϊ�
* �����F
* �@�����̐������Βl�ɕϊ�����e���v���[�g�֐�
* �����F
* �@T Value�@�ϊ�����l
* �߂�l�F
* �@�����̐�Βl
*/

template <typename T>
T Abs(T value)
{
	T result;

	if (value > 0)
	{
		//value�����̒l
		result = value;
	}
	else
	{
		//value�����̒l
		result = -value;
	}

	return result;
}

/*
* �ő�l��Ԃ��e���v���[�g
* �����F
* �@�����Ŏw�肳�ꂽ��̒l�̍ő�l��Ԃ�
* �����F
* �@T a�@�v�Z�p�f�[�^
* �@T b�@�v�Z�p�f�[�^
* �߂�l�F
* �@�ő�l
*/
template <typename T>
T Max(T a, T b)
{
	T result;

	//�l���傫���ق���result�ɐݒ�
	if (a < b)
	{
		result = b;
	}
	else
	{
		result = a;
	}

	return result;
}

/*
* �ŏ��l��Ԃ��e���v���[�g
* �����F
* �@�����Ŏw�肳�ꂽ��̒l�̍ő�l��Ԃ�
* �����F
* �@T a�@�v�Z�p�f�[�^
* �@T b�@�v�Z�p�f�[�^
* �߂�l�F
* �@�ŏ��l
*/
template <typename T>
T Min(T a, T b)
{
	T result;

	////�l���������ق���result�ɐݒ�
	if (a > b)
	{
		result = b;
	}
	else
	{
		result = a;
	}

	return result;
}