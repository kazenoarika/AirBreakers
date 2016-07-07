#include "DxLib.h"
#include "IntervalSave.h"

#include "Game.h"
#include "Audio.h"

IntervalSave::IntervalSave(IIntervalChanger* changer):BaseInterval(changer){
	for(int i=0;i<MaxAudio;i++){
		mAudio[i] = new Audio();
	}
}


IntervalSave::~IntervalSave(void){
	for(int i=0;i<MaxAudio;i++){
		delete mAudio[i];
	}
}

void IntervalSave::Initialize(){
	pInput = Game::Instance()->GetInput();

	/*== グラフィック ================*/
	GhBackground = LoadGraph("dat/image/title/load00.jpg");	// 背景

	/*== オーディオ ================*/
	mAudio[0]->SetAudio(LoadSoundMem("dat/audio/music/momizi.ogg"));
		mAudio[0]->SetLoopFlag(true);
	mAudio[1]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system14.ogg"));
		mAudio[1]->SetVolume(150);
	mAudio[2]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system16.ogg"));
		mAudio[2]->SetVolume(150);
}

void IntervalSave::Finalize(){
	for(int i=0;i<MaxAudio;i++){
		mAudio[i]->Stop();
	}
}

void IntervalSave::Draw(){
	DrawGraph(0,0,GhBackground,true);
}

void IntervalSave::Update(){
	int i;
	for(i=0;i<MaxAudio;i++){ mAudio[i]->Initialize();	}
	if(mCount == 0){ mAudio[0]->Play(); }					// BGM再生

	if(pInput->IsPushBom() == 1){
		mInterChanger->ChangeInterval(eInterMenu);
	}

	for(i=0;i<MaxAudio;i++){ mAudio[i]->Update();	}
	mCount++;
}

