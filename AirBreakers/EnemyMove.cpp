#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "Enemy.h"

#include "UnitAdmin.h"

// â∫Ç…â∫ÇÈ
void Enemy::MoverDown(){
	if(mObjCount == 0){
		VECTOR force={0,mObjMoveSpeed,0};
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
}

// è„Ç…è„Ç™ÇÈ
void Enemy::MoverUp(){
	if(mObjCount == 0){
		VECTOR force={0,-mObjMoveSpeed,0};
		SetForce(&force);
		mObjTransform.SetAngle(-90 * M_PI/180);
	}
}

// Ç–ÇΩÇ∑ÇÁç∂Ç÷
void Enemy::MoverLeft(){
	if(mObjCount == 0){
		VECTOR force={mObjMoveSpeed,0,0};
		SetForce(&force);
		mObjTransform.SetAngle(180 * M_PI/180);
	}
}


// Ç–ÇΩÇ∑ÇÁâEÇ÷
void Enemy::MoverRight(){
	if(mObjCount == 0){
		VECTOR force={mObjMoveSpeed,0,0};
		SetForce(&force);
		mObjTransform.SetAngle(0 * M_PI/180);
	}
}

// Ç‰ÇÁÇ‰ÇÁóhÇÍÇ»Ç™ÇÁç~ÇËÇƒÇ≠ÇÈ
void Enemy::MoverCos(){
	VECTOR force={0,0,0};
	SetForce(&force);
	mObjTransform.SetAngle((360 * (mObjCount % 180/180.0)) * M_PI/180.0);

	VECTOR point;
	mObjTransform.SetX(mObjTransform.GetX() + (float)cos(mObjTransform.GetAngle())*mObjMoveSpeed);
	mObjTransform.SetY(mObjTransform.GetY() + mObjMoveSpeed);
}

//â∫Ç™Ç¡ÇƒÇ´Çƒí‚ëÿÇµÇƒè„Ç™Ç¡ÇƒÇ¢Ç≠
void Enemy::MoverDownToUp(){
	VECTOR force={0,0,0};
	if(mObjCount == 0){
		force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
	if(mObjCount == 40){
		SetForce(&force);
	}
	if(mObjCount == 40+mState.WaitTime){
		SetForce(&force);
		mObjTransform.SetAngle(-90 * M_PI/180);
	}
}

// â∫Ç™Ç¡Çƒé~Ç‹Ç¡Çƒç∂è„
void Enemy::MoverDownToUpLeft(){
	VECTOR force={0,0,0};
	if(mObjCount == 0){
		force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
	if(mObjCount == 60){
		SetForce(&force);
	}
	if(mObjCount == 60+mState.WaitTime){
		force.x = force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(-135 * M_PI/180);
	}
}

// â∫Ç™Ç¡Çƒé~Ç‹Ç¡ÇƒâEè„
void Enemy::MoverDownToUpRight(){
	VECTOR force={0,0,0};
	if(mObjCount == 0){
		force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
	if(mObjCount == 60){
		SetForce(&force);
	}
	if(mObjCount == 60+mState.WaitTime){
		force.x = force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(-45 * M_PI/180);
	}
}

// â∫Ç™Ç¡Çƒé~Ç‹Ç¡Çƒâ∫
void Enemy::MoverDownToDown(){
	VECTOR force={0,0,0};
	if(mObjCount == 0){
		force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
	if(mObjCount == 60){
		SetForce(&force);
	}
	if(mObjCount == 60+mState.WaitTime){
		force.x = force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
}

// â∫Ç™Ç¡Çƒé~Ç‹Ç¡Çƒç∂
void Enemy::MoverDownToLeft(){
	VECTOR force={0,0,0};
	if(mObjCount == 0){
		force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
	if(mObjCount == 60){
		SetForce(&force);
	}
	if(mObjCount == 60+mState.WaitTime){
		force.x = force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(180 * M_PI/180);
	}
}

// â∫Ç™Ç¡Çƒé~Ç‹Ç¡ÇƒâE
void Enemy::MoverDownToRight(){
	VECTOR force={0,0,0};
	if(mObjCount == 0){
		force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
	if(mObjCount == 40){
		SetForce(&force);
	}
	if(mObjCount == 40+mState.WaitTime){
		force.x = force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(0 * M_PI/180);
	}
}

// â∫Ç™Ç¡Çƒé~Ç‹Ç¡Çƒç∂â∫
void Enemy::MoverDownToLeftDown(){
	VECTOR force={0,0,0};
	if(mObjCount == 0){
		force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
	if(mObjCount == 40){
		SetForce(&force);
	}
	if(mObjCount == 40+mState.WaitTime){
		force.x = force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(135 * M_PI/180);
	}
}

// â∫Ç™Ç¡Çƒé~Ç‹Ç¡ÇƒâEâ∫
void Enemy::MoverDownToRightDown(){
	VECTOR force={0,0,0};
	if(mObjCount == 0){
		force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
	if(mObjCount == 40){
		SetForce(&force);
	}
	if(mObjCount == 40+mState.WaitTime){
		force.x = force.y = mObjMoveSpeed;
		SetForce(&force);
		mObjTransform.SetAngle(45 * M_PI/180);
	}
}

// Ç–ÇΩÇ∑ÇÁÇ…ç∂â∫Ç÷
void Enemy::MoverLeftDown(){
	if(mObjCount == 0){
		VECTOR force={mObjMoveSpeed,mObjMoveSpeed,0};
		SetForce(&force);
		mObjTransform.SetAngle(135 * M_PI/180);
	}
}

// Ç–ÇΩÇ∑ÇÁÇ…âEâ∫Ç÷
void Enemy::MoverRightDown(){
	if(mObjCount == 0){
		VECTOR force={mObjMoveSpeed,mObjMoveSpeed,0};
		SetForce(&force);
		mObjTransform.SetAngle(45 * M_PI/180);
	}
}
