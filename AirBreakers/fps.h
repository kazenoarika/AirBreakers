#pragma once
/*============================================================ �V�X�e�� ================*/
class FPS{
	int mCount;					// �J�E���^
	int count0t;				// 60�t���[����1���ƂȂ鎞�����L�^����ϐ�
	static const int N = 60;	// ���ς��Ƃ�T���v����
	static const int fps = 60;	// �ݒ肵��FPS
	int f[fps];					// ���ς��v�Z���邽��60���1�L���Ԃ��L�^
	double ave;					// ���ϒl
public:
	FPS();
	~FPS();
	double retFPS();
	void Draw();
	void Wait();
};