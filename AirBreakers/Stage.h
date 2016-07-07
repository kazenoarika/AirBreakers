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

	/*== クリアフラグ用 ================*/
	int mClearDestroy;			// 目標破壊数(=0なら目標なし)
	int mClearTime;				// 目標耐久時間(=0なら目標なし)
	int mClearLimitTime;		// 目標クリアタイム(<0なら目標なし)mStageCount依存
	int mStartLimitTime;		// 制限時間を測り始めたタイム

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
