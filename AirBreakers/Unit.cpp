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
	mHP -= mBullet->GetStatus().Damage;	// �e�̈З͂���_���[�W�v�Z
	mUniInvisible = 3;		// ���G���Ԃ��Z�b�g

	if(mHP<0){
		flgDestroyed = true;
		mObjFlag=false;
	}
}
void Unit::Hit(Object* objObject){
	mHP -= 1;				// ����Ε���e�̓_���[�W1
	mUniInvisible = 3;		// ���G���Ԃ��Z�b�g

	if(mHP<0){
		mObjFlag=false;		// ������悤�ɂ��Ă邯�Ǒ�j�t���O�ɂ���\��
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
