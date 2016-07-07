#include "SceneMgr.h"

#include "seqTitle.h"
#include "seqPlay.h"
#include "seqInterval.h"
#include "seqClear.h"


SceneMgr::SceneMgr(void):mNextScene(eSceneNone)
{
	// はじめはタイトル画面から
	mScene.reset(new Title(this));
}

SceneMgr::~SceneMgr(void){
}

void SceneMgr::Initialize(){
	mScene->Initialize();
}

void SceneMgr::Finalize(){
	mScene->Finalize();
}

//更新
void SceneMgr::Update(){
	if(mNextScene != eSceneNone){
		mScene->Finalize();	// 現在のシーンの終了処理を実行

		switch(mNextScene){
			case eSceneTitle:
				mScene.reset(new Title(this));	// タイトル画面のインスタンス
				break;
			case eScenePlay:
				mScene.reset(new Play(this));	// プレイ画面のインスタンス
				break;
			case eSceneInterval:
				mScene.reset(new Interval(this));	// インターバル画面のインスタンス
				break;
			case eSceneClear:
				mScene.reset(new Clear(this));	// クリアー画面のインスタンス
				break;
		}
		mNextScene = eSceneNone;	//次のシーン情報をクリア
		mScene->Initialize();
	}

	mScene->Update();	// シーンの更新
}

void SceneMgr::Draw(){
	mScene->Draw();	// シーンの描画
}

void SceneMgr::ChangeScene(eScene NextScene){
	mNextScene = NextScene;	// 次のシーンのセット
}