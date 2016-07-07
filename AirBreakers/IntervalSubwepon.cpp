#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "IntervalSubwepon.h"

#include "Game.h"
#include "Player.h"
#include "Menu.h"
#include "Audio.h"

IntervalSubwepon::IntervalSubwepon(IIntervalChanger* changer):BaseInterval(changer){
	for(int i=0;i<MaxAudio;i++){
		mAudio[i] = new Audio();
	}
}


IntervalSubwepon::~IntervalSubwepon(void){
	for(int i=0;i<MaxAudio;i++){
		delete mAudio[i];
	}
}

void IntervalSubwepon::Initialize(){
	pInput = Game::Instance()->GetInput();
	mCount = 0;
	
	GhBackground = LoadGraph("dat/image/interval/background/subwepon.png");		// 背景

	/*== オーディオ ================*/
	mAudio[0]->SetAudio(LoadSoundMem("dat/audio/music/hidari_sinri.ogg"));
		mAudio[0]->SetLoopFlag(true);
	mAudio[1]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system14.ogg"));
		mAudio[1]->SetVolume(150);
	mAudio[2]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system16.ogg"));
		mAudio[2]->SetVolume(150);

	const int defX		= 64;
	const int defY		= 286;
	const int spaceX	= 400;
	const int spaceY	= 40;
	std::string	tmp;
	for(int i=0;i<10;i++){
		tmp = Player::Instance()->GetSubweponbox()->GetSubwepon(i)->GetStatus().Name;
		mMenuMgr.GetMenu(i)->SetMenu( ((i%2)*spaceX)+defX, (i/2*spaceY)+defY, tmp,"");
	}

	mMenuMgr.SetCurrent(0);
	mMenuMgr.SetSelectMax(10);
}

void IntervalSubwepon::Finalize(){
	for(int i=0;i<MaxAudio;i++){
		mAudio[i]->Stop();
	}
}

void IntervalSubwepon::Draw(){
	DrawGraph(0,0,GhBackground,true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * sin(mCount%180 * M_PI/180));
	DrawBox(
		mMenuMgr.GetCurrentMenu()->GetTransform().GetX()		,mMenuMgr.GetCurrentMenu()->GetTransform().GetY()	,
		mMenuMgr.GetCurrentMenu()->GetTransform().GetX()+200	,mMenuMgr.GetCurrentMenu()->GetTransform().GetY()+20	,
		GetColor(80,255,200),true
	);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	const int fontColor = GetColor(255,255,255);
	for(int i=0;i<10;i++){
		mMenuMgr.GetMenu(i)->Draw(GetColor(255,255,255));
	}
}

void IntervalSubwepon::Update(){
	int i;
	for(i=0;i<MaxAudio;i++){ mAudio[i]->Initialize();	}
	if(mCount == 0){ mAudio[0]->Play(); }					// BGM再生

	if(pInput->IsPushLeft() == 1){
		mMenuMgr.CurrentUp();
		mAudio[1]->Play();
		while(1){
			if(Player::Instance()->GetSubweponbox()->GetSubwepon(mMenuMgr.GetCurrent())->GetStatus().Id == -1){
				mMenuMgr.CurrentUp();
				if(mMenuMgr.GetCurrent() == 0){break;}
				continue;
			}else{
				break;
			}
		}
	}
	if(pInput->IsPushRight() == 1){
		mMenuMgr.CurrentDown();
		mAudio[1]->Play();
		while(1){
			if(Player::Instance()->GetSubweponbox()->GetSubwepon(mMenuMgr.GetCurrent())->GetStatus().Id == -1){
				mMenuMgr.CurrentDown();
				if(mMenuMgr.GetCurrent() == 0){break;}
				continue;
			}else{
				break;
			}
		}
	}
	if(pInput->IsPushUp() == 1){
		mMenuMgr.CurrentUp();
		mMenuMgr.CurrentUp();
		mAudio[1]->Play();
		while(1){
			if(Player::Instance()->GetSubweponbox()->GetSubwepon(mMenuMgr.GetCurrent())->GetStatus().Id == -1){
				mMenuMgr.CurrentUp();
				if(mMenuMgr.GetCurrent() == 0){break;}
				continue;
			}else{
				break;
			}
		}
	}
	if(pInput->IsPushDown() == 1){
		mMenuMgr.CurrentDown();
		mMenuMgr.CurrentDown();
		mAudio[1]->Play();
		while(1){
			if(Player::Instance()->GetSubweponbox()->GetSubwepon(mMenuMgr.GetCurrent())->GetStatus().Id == -1){
				mMenuMgr.CurrentDown();
				if(mMenuMgr.GetCurrent() == 0){break;}
				continue;
			}else{
				break;
			}
		}
	}
	if(pInput->IsPushBom()== 1){
		mInterChanger->ChangeInterval(eInterMenu);
	}

	for(i=0;i<MaxAudio;i++){ mAudio[i]->Update();	}
	mCount++;
}

