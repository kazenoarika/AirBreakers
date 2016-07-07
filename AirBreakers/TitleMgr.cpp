#include "TitleMgr.h"

#include "TopInTitle.h"
#include "MenuInTitle.h"
#include "LoadInTitle.h"
#include "OptionInTitle.h"

CTitleMgr::CTitleMgr(void):mNextTitle(eStateNone){
	changer.reset(this);
	spTitle.reset(new CTopInTitle(changer));
}


CTitleMgr::~CTitleMgr(void){
}

void CTitleMgr::Initialize(){
	spTitle->Initialize();
}

void CTitleMgr::Finalize(){
	spTitle->Finalize();
}

void CTitleMgr::Update(){
	if(mNextTitle != eStateNone){
		spTitle->Finalize();		// 現在のシーケンスの終了処理

		// 指定されたインスタンスを作成する
		switch(mNextTitle){
			case eStateTop:
				spTitle.reset(new CTopInTitle(changer));
				break;
			case eStateMenu:
				spTitle.reset(new CMenuInTitle(changer));
				break;
			case eStateLoad:
				spTitle.reset(new CLoadInTitle(changer));
				break;
			case eStateOption:
				spTitle.reset(new COptionInTitle(changer));
				break;
		}
		spTitle->Initialize();		// シーケンスの初期化
		mNextTitle = eStateNone;	// 通常状態
	}

	spTitle->Update();				// シーンの更新
}

void CTitleMgr::Draw(){
	spTitle->Draw();
}

void CTitleMgr::ChangeScene(eStateTitleMode NextScene){
	mNextTitle = NextScene;
}