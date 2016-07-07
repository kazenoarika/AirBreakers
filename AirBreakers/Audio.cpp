#include "DxLib.h"
#include "Audio.h"


Audio::Audio(void){
	mAudio = 0;
	mVolume = 255;
	flgPlay = false;
	flgLoop = false;
}

Audio::~Audio(void){
	DeleteSoundMem(mAudio);
}

void Audio::Initialize(){
	flgPlay = false;
}

void Audio::Stop(){
	if(CheckSoundMem(mAudio) == 1){
		StopSoundMem(mAudio);
	}

}

void Audio::Update(){
	if(flgPlay){
		ChangeVolumeSoundMem(mVolume, mAudio);
		if(flgLoop){
			PlaySoundMem(mAudio, DX_PLAYTYPE_LOOP);
		}else{
			PlaySoundMem(mAudio, DX_PLAYTYPE_BACK);
		}
	}
}