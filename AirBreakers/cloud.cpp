#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "cloud.h"


Cloud::Cloud(int x, int* mGhCloud){
	mObjImg		= mGhCloud;

}
Cloud::~Cloud(){
}
void Cloud::Draw(){
}
void Cloud::Update(){
	mObjTransform.AddY(scrollSpeed);
	if(mObjTransform.GetY()>=FeeldMaxY+70){ mObjTransform.AddY(-70); }
}


void Cloud::Spawn(float x, float y){
	mObjTransform.SetX(x);
	mObjTransform.SetY(GetRand(FeeldMaxY*2)-FeeldMaxY);

	scrollSpeed=GetRand(4)+1;
	mObjTransform.SetAngle(M_PI/2);
	mObjFlag=true;
}