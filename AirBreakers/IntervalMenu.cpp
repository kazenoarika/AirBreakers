#include "DxLib.h"
#include "IntervalMenu.h"
#include "Game.h"

#include "Audio.h"

IntervalMenu::IntervalMenu(IIntervalChanger* changer):BaseInterval(changer){
	for(int i=0;i<MaxAudio;i++){
		mAudio[i] = new Audio();
	}
}

IntervalMenu::~IntervalMenu(void){
	for(int i=0;i<MaxAudio;i++){
		delete mAudio[i];
	}
}

void IntervalMenu::Initialize(){
	pInput = Game::Instance()->GetInput();

	/*== グラフィック ================*/
	GhBackground	= LoadGraph("dat/image/interval/skybg.png");			// 背景
	GhFrame[0]		= LoadGraph("dat/image/interval/flame00.png");			// フレーム
	GhFrame[1]		= LoadGraph("dat/image/interval/flame01.png");			// フレーム
	LoadDivGraph("dat/image/interval/menulogo.png",12,2,6,384,64,GhLogo);	// メニュー


	/*== オーディオ ================*/
	mAudio[0]->SetAudio(LoadSoundMem("dat/audio/music/y_ko.ogg"));
		mAudio[0]->SetLoopFlag(true);
	mAudio[1]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system14.ogg"));
		mAudio[1]->SetVolume(150);
	mAudio[2]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system16.ogg"));
		mAudio[2]->SetVolume(150);


	/*== メニュー ================*/
	const int tmpMenuMax = 4;

	mMenuMgr.SetCurrent(0);
	mMenuMgr.SetSelectMax(tmpMenuMax);
	std::string strTmp[] = {"STAGE SELECT", "Subwepon", "Material", "SAVE"};
	const int tmpX = 50;
	const int tmpY = 50;
	const int betweenDefY = 64;
	for(int i=0;i<tmpMenuMax;i++){
		mMenuMgr.GetMenu(i)->SetMenu(tmpX+(i*(-10)), tmpY+(i*betweenDefY), strTmp[i], "");
	}
}

void IntervalMenu::Finalize(){
	int i=0;
	DeleteGraph(GhBackground);
	for(i=0;i<sizeof(GhFrame)/sizeof(GhFrame[0]);i++){
		DeleteGraph(GhFrame[i]);
	}
	for(i=0;i<sizeof(GhLogo)/sizeof(GhLogo[0]);i++){
		DeleteGraph(GhLogo[i]);
	}
	for(int i=0;i<MaxAudio;i++){
		mAudio[i]->Stop();
	}

}

void IntervalMenu::Draw(){
	const int bgDefX = 0;
	const int bgDefY = 0;

	DrawGraph(bgDefX, bgDefY ,GhBackground,true);
	DrawGraph(bgDefX, bgDefY ,GhFrame[0],true);
	DrawGraph(bgDefX, bgDefY ,GhFrame[1],true);

	/*== メニュー ================*/
	for(int i=0;i<mMenuMgr.GetSelectMax();i++){
		const int tmpSub = (i == mMenuMgr.GetCurrent()) ? (i+1)*2+1 : (i+1)*2;
		const int tmpX = (i == mMenuMgr.GetCurrent()) ? mMenuMgr.GetMenu(i)->GetTransform().GetX()+25 : mMenuMgr.GetMenu(i)->GetTransform().GetX();
		DrawGraph(tmpX, mMenuMgr.GetMenu(i)->GetTransform().GetY(), GhLogo[tmpSub], true);
	}
}

void IntervalMenu::Update(){
	int i;
	for(i=0;i<MaxAudio;i++){ mAudio[i]->Initialize();	}
	if(mCount == 0){ mAudio[0]->Play(); }
	if(pInput->IsPushUp()==1){
		mAudio[1]->Play();
		mMenuMgr.CurrentUp();
	}

	if(pInput->IsPushDown()==1){
		mAudio[1]->Play();
		mMenuMgr.CurrentDown();
	}

	if(pInput->IsPushShot()==1){
		switch(mMenuMgr.GetCurrent()){
			case 0:		// ステージセレクト
				mInterChanger->ChangeInterval(eInterStageSelect);
				break;
			case 1:		// サブウェポン
				mInterChanger->ChangeInterval(eInterSW);
				break;
			case 2:		// マテリアル
				mInterChanger->ChangeInterval(eInterMaterial);
				break;
			case 3:		// セーブ
				mInterChanger->ChangeInterval(eInterSave);
				break;
		}
	}

	for(i=0;i<MaxAudio;i++){ mAudio[i]->Update();	}
	mCount++;
}