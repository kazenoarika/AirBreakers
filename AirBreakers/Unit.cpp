#include "DxLib.h"

#include "Unit.h"
#include "Bullet.h"

Unit::Unit(UnitAdmin* unitadmin):Object(unitadmin){
	mHP				= 0;
	cntDestroyed	= 0;
	mUniInvisible	= 0;
	flgDestroyed	= false;
}
Unit::~Unit(){}

/*==  ================*/
void Unit::Hit(Bullet* mBullet){
	mHP -= mBullet->GetStatus().Damage;	// 弾の威力からダメージ計算
	mUniInvisible = 3;		// 無敵時間をセット

	if(mHP<0){
		flgDestroyed = true;
		mObjFlag=false;
	}
}
void Unit::Hit(Object* objObject){
	mHP -= 1;				// 現状対物被弾はダメージ1
	mUniInvisible = 3;		// 無敵時間をセット

	if(mHP<0){
		mObjFlag=false;		// 消えるようにしてるけど大破フラグにする予定
	}
}
/*==  ================*/
void Unit::Draw(){
	if(mObjFlag){

		DrawRotaGraphFdF();
	}
}
void Unit::DrawmHP(){
	if(mObjFlag){
		DrawBox(mObjTransform.GetX()-1,mObjTransform.GetY()-1,mObjTransform.GetX()+10        ,mObjTransform.GetY()+1,GetColor(255,255,255),false);
		DrawBox(mObjTransform.GetX()  ,mObjTransform.GetY()  ,mObjTransform.GetX()+10+(mHP/5),mObjTransform.GetY()  ,GetColor(0,0,255)    ,false);
	}
}

/*== Get/Set ================*/
int Unit::GetHP(){
	return mHP;
}
