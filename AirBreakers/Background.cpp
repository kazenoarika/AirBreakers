#include "DxLib.h"

#include "Background.h"
#include "cloud.h"

BackGround::BackGround(int* mGhBackground,int* mClocdGh){
	mObjImg = mGhBackground;

	GetGraphSize((*mObjImg),&mImgWidth, &mImgHeight);

	mObjHostility = true;
	mObjFlag = false;
	mObjHitArea = (float)DefaultHitArea;

	for(int i=0;i<MaxCloud;i++){
		cloud[i] = new Cloud((FeeldZeroX+300)*(i%2), mClocdGh);
	}

	flgScroll = false;
}
BackGround::~BackGround(){
	for(int i=0;i<MaxCloud;i++){
		delete cloud[i];
	}	
}
void BackGround::Initialize(){
// ‰Šú‰»
	mObjTransform.SetX(FeeldMaxX / 2);
	mObjTransform.SetY((float)-mImgHeight+ FeeldMaxY);
	mObjTransform.SetY(FeeldMaxY/2);

	mObjMoveSpeed = 10;
}
void BackGround::Draw(){
	DrawRotaGraphFdF();
	DrawRotaGraphFdF(0,-mImgHeight,1,0,(*mObjImg),true,false);
	
	// ‰_‚Ì•`‰æ
	for(int i=0;i<MaxCloud;i++){
		cloud[i]->Draw();
		//DrawFormatString(cloud[i]->GetX(),cloud[i]->GetY(),GetColor(255,0,0),"%d, %d",i,cloud[i]->GetX());
	}
}
void BackGround::Update(){
	if(flgScroll){
		mObjTransform.AddY(mObjMoveSpeed);
		if(mObjTransform.GetY()>=mImgHeight){ mObjTransform.SetY(0); }

		for(int i=0;i<MaxCloud;i++){
			cloud[i]->Update();
		}
	}
}
