#include "EffectsError.h"
#include "DxLib.h"

CEffectsError::CEffectsError(void){
}


CEffectsError::~CEffectsError(void){
}

void CEffectsError::Initialize(){
	
}

void CEffectsError::Run(){
	bRunning = true;
	mCount = 0;
}


void CEffectsError::Draw(){
	int tmp = mCount%100;
	if(tmp <50){
		for(int i=0;i<8;i++){
			for(int j=0;j<6;j++){
				DrawGraph( (100*i), (100*j), mImages[0].GetGHandle(), true);
			}
		}

		DrawGraph(250, 200, mImages[1].GetGHandle(), true);
		DrawGraph(300, 300, mImages[2].GetGHandle(), true);
	}}

void CEffectsError::Update(){
	mCount++;
}