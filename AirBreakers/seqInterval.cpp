#include "DxLib.h"
#include "seqInterval.h"

Interval::Interval(ISceneChanger* changer):BaseScene(changer){
}
Interval::~Interval(){
}
void Interval::Initialize(){
	mIntervalMgr.Initialize();
}
void Interval::Finalize(){
	mIntervalMgr.Finalize();
}
void Interval::Draw(){
	mIntervalMgr.Draw();
}
void Interval::Update(){
	mIntervalMgr.Update();
	if(mIntervalMgr.GetGoToScenePlay()){
		mSceneChanger->ChangeScene(eScenePlay);
	}
}
