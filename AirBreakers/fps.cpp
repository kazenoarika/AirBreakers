#include "DxLib.h"

#include "FPS.h"

FPS::FPS(){
	mCount = 0;
	count0t = 0;
}

FPS::~FPS(){}

double FPS::retFPS(){
	return 1000/ave;
}

void FPS::Draw(){
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", 1000/ave);
}

void FPS::Wait(){
	int term,i,gnt;
	static int t=0;
	if(mCount==0){// 60�t����1��ڂȂ�
		if(t==0)
			term=0;
		else
			term=count0t+1000-GetNowCount();
	}
	else	// �҂ׂ����ԁ����݂���ׂ�����-���݂̎���
		term=(int)(count0t+mCount*(1000.0/fps))-GetNowCount();

	if(term>0)// �҂ׂ����Ԃ�������
		Sleep(term);

	gnt=GetNowCount();

	if(mCount==0)// 60�t���[����1�x������
		count0t=gnt;
	f[mCount]=gnt-t;// ����������Ԃ��L�^
	t=gnt;
	// ���όv�Z
	if(mCount==fps-1){
		ave=0;
		for(i=0;i<fps;i++)
			ave+=f[i];
		ave/=fps;
	}
	mCount=(++mCount)%fps;
}