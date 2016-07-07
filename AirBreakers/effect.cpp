#include "DxLib.h"

#include "effect.h"
#include <cmath>

Effect::Effect(UnitAdmin* unitadmin):Object(unitadmin){
}

Effect::~Effect(){}

void Effect::Update(){
	if(mObjFlag){
		mObjTransform.AddX(cos(GetTransform().GetAngle())*speed);
		mObjTransform.AddY(sin(GetTransform().GetAngle())*speed);

		if(	mObjTransform.GetX()<FeeldZeroX-40  || mObjTransform.GetX()>FeeldMaxX+40 ||
			mObjTransform.GetY()<FeeldZeroY-200 || mObjTransform.GetY()>FeeldMaxY+40){
				mObjFlag = false;
		}
	}

	mObjCount++;
}
