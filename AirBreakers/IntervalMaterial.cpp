#include "DxLib.h"
#include "IntervalMaterial.h"

#include "Game.h"
#include "Audio.h"

IntervalMaterial::IntervalMaterial(IIntervalChanger* changer):BaseInterval(changer){
	for(int i=0;i<MaxAudio;i++){
		mAudio[i] = new Audio();
	}
}

IntervalMaterial::~IntervalMaterial(void){
	for(int i=0;i<MaxAudio;i++){
		delete mAudio[i];
	}
}

void IntervalMaterial::Initialize(){
	pInput = Game::Instance()->GetInput();

	/*== グラフィック ================*/
	GhBackground = LoadGraph("dat/image/interval/background/item.png");

	/*== オーディオ ================*/
	mAudio[0]->SetAudio(LoadSoundMem("dat/audio/music/tobuga.ogg"));
		mAudio[0]->SetLoopFlag(true);
	mAudio[1]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system14.ogg"));
		mAudio[1]->SetVolume(150);
	mAudio[2]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system16.ogg"));
		mAudio[2]->SetVolume(150);

}

void IntervalMaterial::Finalize(){
	for(int i=0;i<MaxAudio;i++){
		mAudio[i]->Stop();
	}
}

void IntervalMaterial::Draw(){
	DrawGraph(0,0,GhBackground,true);
}

void IntervalMaterial::Update(){
	int i;
	for(i=0;i<MaxAudio;i++){ mAudio[i]->Initialize();	}
	if(mCount == 0){ mAudio[0]->Play(); }					// BGM再生

	if(pInput->IsPushBom() == 1){
		mInterChanger->ChangeInterval(eInterMenu);
	}

	for(i=0;i<MaxAudio;i++){ mAudio[i]->Update();	}
	mCount++;
}

