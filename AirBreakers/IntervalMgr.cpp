#include "IntervalMgr.h"

#include "IntervalMenu.h"
#include "IntervalStageSelect.h"
#include "IntervalSubwepon.h"
#include "IntervalMaterial.h"
#include "IntervalSave.h"

IntervalMgr::IntervalMgr(void){
	flgGoToScenePlay =false;
}
IntervalMgr::~IntervalMgr(void){
}

void IntervalMgr::Initialize(){
	mInterval.reset(new IntervalMenu(this));	
}

void IntervalMgr::Finalize(){
	mInterval->Finalize();
}

void IntervalMgr::Draw(){
	mInterval->Draw();
}

void IntervalMgr::Update(){
	if(mNextInter != eInterNone){
		mInterval->Finalize();	// 現在のシーンの終了処理を実行

		switch(mNextInter){
			case eInterMenu:
				mInterval.reset(new IntervalMenu(this));		// トップメニュー画面のインスタンス
				break;
			case eInterStageSelect:
				mInterval.reset(new IntervalStageSelect(this));	// ステージセレクト画面のインスタンス
				break;
			case eInterSW:
				mInterval.reset(new IntervalSubwepon(this));	// サブウェポン画面のインスタンス
				break;
			case eInterMaterial:
				mInterval.reset(new IntervalMaterial(this));	// マテリアル画面のインスタンス
				break;
			case eInterSave:
				mInterval.reset(new IntervalSave(this));		// セーブ画面のインスタンス
				break;
			case eInterGoToScenePlay:
				flgGoToScenePlay = true;
				break;
		}
		mNextInter = eInterNone;	//次のシーン情報をクリア
		mInterval->Initialize();
	}

	mInterval->Update();	// シーンの更新
}

void IntervalMgr::ChangeInterval(eInter nextInter){
	mNextInter = nextInter;
}