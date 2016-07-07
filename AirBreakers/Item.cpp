#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "Item.h"


Item::Item(UnitAdmin* unitadmin):Object(unitadmin){
	mKind			= eItemKindScore;
	mVeiwAngle		= 0.0;
	mObjFlag		= false;
	mObjHostility	= false;
}
Item::~Item(void){
}

void Item::Spawn(float x, float y, float angle, eItemKind kind){
	mObjTransform.SetX(x);
	mObjTransform.SetY(y);
	mObjTransform.SetAngle(angle);
	mKind = kind;
	mObjMoveSpeed = 1;

	mRank = GetRand(1000) / 2000.0 + 0.5;

	mObjFlag = true;
}
void Item::Spawn(Transform* transform, eItemKind kind){
	mObjTransform	=*transform;
	mKind			= kind;
	mObjMoveSpeed	= 1;

	mRank			= GetRand(1000) / 2000.0 + 0.5;

	mObjFlag		= true;
}
void Item::Hit(){
	mObjFlag = false;
}

void Item::Draw(){
	if(mObjFlag){
		DrawRotaGraphFdF(&mObjTransform, mRank, mVeiwAngle, *mObjImg, true, false);
	}
}
void Item::Update(){
	if(mObjFlag){
		mVeiwAngle+=0.1;

		const float t = 0.2;

		if(mObjTransform.GetAngle()<0){
			if(mObjTransform.GetAngle()<(-M_PI/2)){
				mObjTransform.SetAngle(-t);
				if(mObjTransform.GetAngle()<-M_PI){ mObjTransform.SetAngle(M_PI); }
			}else{
				mObjTransform.SetAngle(t);
			}
		}else{
			if(mObjTransform.GetAngle()<M_PI/2){
				mObjTransform.SetAngle(t);
			}else{
				mObjTransform.SetAngle(-t);
			}
		}

		mObjTransform.Move(mObjMoveSpeed,mObjMoveSpeed);

		if(	mObjTransform.GetX() < -FeeldZeroX || FeeldMaxX+FeeldZeroX < mObjTransform.GetX() ||
			mObjTransform.GetY() < -FeeldZeroY || FeeldMaxY+FeeldZeroY < mObjTransform.GetY()){
				mObjFlag = false;
		}
	}
}



