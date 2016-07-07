#pragma once

#include "ScoreBoard.h"

struct StageStatus{
	int HiScore;
	int HiDestroy;
	int Meter;
	int Time;
	bool Cleared;
	int Clear;

	StageStatus(){
		HiScore=0;
		HiDestroy=0;
		Meter=0;
		Time=0;
		Cleared=false;
		Clear=0;
	}
};

class Stage{
protected:
	/*==  ================*/
	char name[128];

	StageStatus mState;		// 

	/*== �N���A�t���O�p ================*/
	int mClearDestroy;			// �ڕW�j��(=0�Ȃ�ڕW�Ȃ�)
	int mClearTime;				// �ڕW�ϋv����(=0�Ȃ�ڕW�Ȃ�)
	int mClearLimitTime;		// �ڕW�N���A�^�C��(<0�Ȃ�ڕW�Ȃ�)mStageCount�ˑ�
	int mStartLimitTime;		// �������Ԃ𑪂�n�߂��^�C��

	bool StageClear();


//	void HiScoreUpdate();

public:
	Stage();
	~Stage();

	void Draw();
	void Update();

	/*== Get/Set ================*/
	StageStatus GetStatus(){
		return mState;
	}
	void HiScoreUpdate(int score){ if(mState.HiScore < score){ mState.HiScore = score; } }
	void HiDestroyUpdate(int destroy){ if(mState.HiDestroy < destroy){ mState.HiDestroy = destroy;} }
	void SetStageStatus(StageStatus status);
};
