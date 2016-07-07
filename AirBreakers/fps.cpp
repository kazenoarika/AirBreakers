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
	if(mCount==0){// 60フレの1回目なら
		if(t==0)
			term=0;
		else
			term=count0t+1000-GetNowCount();
	}
	else	// 待つべき時間＝現在あるべき時刻-現在の時刻
		term=(int)(count0t+mCount*(1000.0/fps))-GetNowCount();

	if(term>0)// 待つべき時間だけ持つ
		Sleep(term);

	gnt=GetNowCount();

	if(mCount==0)// 60フレームに1度基準を作る
		count0t=gnt;
	f[mCount]=gnt-t;// 一周した時間を記録
	t=gnt;
	// 平均計算
	if(mCount==fps-1){
		ave=0;
		for(i=0;i<fps;i++)
			ave+=f[i];
		ave/=fps;
	}
	mCount=(++mCount)%fps;
}