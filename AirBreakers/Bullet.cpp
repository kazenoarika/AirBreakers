#include "DxLib.h"
#include "UnitAdmin.h"

#include "Bullet.h"
#include <cmath>

Bullet::Bullet(UnitAdmin* unitadmin){
	/*== 引数受け取り ================*/
	pUnitAdmin = unitadmin;
}
Bullet::~Bullet(){
}

void Bullet::Initialize(){
	mObjHitArea = (float)DefaultHitArea;
}
void Bullet::Finalize(){
}

/*==  ================*/
void Bullet::Hit(){
	if(mStatus.Penetoration-- <= 0){
		mObjFlag=false;
	}
}
void Bullet::Shot(float x,float y,float angle){
	mObjTransform.SetX(x);
	mObjTransform.SetY(y);
	mObjTransform.SetAngle(angle);

	mObjFlag = true;
}
void Bullet::Shot(float x,float y,float angle, bool hostility, BulletStatus* state){
	mObjTransform.SetX(x);
	mObjTransform.SetY(y);
	mObjTransform.SetAngle(angle);
	mObjHostility = hostility;
	mStatus = *state;

	mObjFlag = true;
}
void Bullet::Shot(Transform* transform, BulletStatus* state, bool hostility){
	mObjTransform	=*transform;
	mStatus			=*state;
	mObjHostility	= hostility;

	mObjFlag		= true;
}

/*== メイン ================*/
void Bullet::Draw(){
	if(mObjFlag){
		if(mObjHostility){			// 敵対判定によって画像を変える
			mObjImg = GhBullets[2];
		}else{
			mObjImg = GhBullets[0];	// さらに弾の種類で変える・・・予定
		}

		DrawRotaGraphFdF();
	}
}
void Bullet::Update(){
	if(mObjFlag){
		

		if(mStatus.AfterImage){
			for(int i=5;i>0;i--){	// 過去座標の保存
				lastPoint[i] = lastPoint[i-1];
			}
		}

		mObjTransform.AddX(cos(mObjTransform.GetAngle())*mStatus.Speed);
		mObjTransform.AddY(sin(mObjTransform.GetAngle())*mStatus.Speed);
	
		if(	mObjTransform.GetX()<FeeldZeroX-40  || mObjTransform.GetX()>FeeldMaxX+40 ||
			mObjTransform.GetY()<FeeldZeroY-100 || mObjTransform.GetY()>FeeldMaxY+40){
				mObjFlag = false;
		}
	}
}

/*== Get/Set ================*/
BulletStatus Bullet::GetStatus(){
	return mStatus;
}
void Bullet::SetStatus(BulletStatus* BulStatus){
	mStatus = *BulStatus;
}
void Bullet::SetImage(int* ghBullet){
	for(int i=0;i<ImageCount;i++){
		GhBullets[i] = &ghBullet[i];
	}
}
