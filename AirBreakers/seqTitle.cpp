#include <memory>

#include "DxLib.h"
#include "seqTitle.h"

Title::Title(ISceneChanger* changer):BaseScene(changer){
	flgEerror = false;
	couError = 0;
}
Title::~Title(){
}
void Title::Initialize(){
	mTitleMgr.Initialize();
}
void Title::Finalize(){
	mTitleMgr.Finalize();
}
void Title::Draw(){
	mTitleMgr.Draw();

	if(flgEerror) DrawErrarEffect();
}
void Title::Update(){
	if(flgEerror){
		UpdataError();
	} else {
		mTitleMgr.Update();
	}
}

