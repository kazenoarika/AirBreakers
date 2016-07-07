#include "Stage.h"

/*==  ================*/
Stage::Stage(){
}
Stage::~Stage(){
}

/*==  ================*/
bool Stage::StageClear(){
//	if(!(mClearDestroy<=0) && mClearDestroy >= mUnitAdmin->GetDestroy()){ return false; }
//	if(!(mClearTime<=0) && mClearTime <= mStageCount){ return false; }
	if(mClearLimitTime > 0){ return false; }
	return true;
}


void Stage::Draw(){
}

void Stage::Update(){
}
/*== Get/Set ================*/
void Stage::SetStageStatus(StageStatus status){
	this->mState.HiScore = status.HiScore;
	this->mState.Cleared = status.Cleared;
}
