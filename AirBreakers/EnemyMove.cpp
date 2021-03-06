#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "Enemy.h"

#include "UnitAdmin.h"

// 下に下る
void Enemy::MoverDown(){
	if(mObjCount == 0){
		VECTOR force={0,mObjMoveSpeed,0};
		SetForce(&force);
		mObjTransform.SetAngle(90 * M_PI/180);
	}
}

// 上に上がる
void Enemy::MoverUp(){
	if(mObjCount == 0){
		VECTOR force={0,-mObjMoveSpeed,0};
		SetForce(&force);
		mObjTransform.SetAngle(-90 * M_PI/180);
	}
}

// ひたすら左へ
void Enemy::MoverLeft(){
	if(mObjCount == 0){
		VECTOR force={mObjMoveSpeed,0,0};
		SetForce(&force);
		mObjTransform.SetAngle(180 * M_PI/180);
	}
}


// ひたすら右へ
void Enemy::MoverRight(){
	if(mObjCount == 0){
		VECTOR force={mObjMoveSpeed,0,0};
		SetForce(&force);
		mObjTransform.SetAngle(0 * M_PI/180);
	}
}

// ゆらゆら揺れながら降りてくる
void Enemy::MoverCos(){
	VECTOR force={0,0,0};
	SetForce(&force);
	mObjTransform.SetAngle((360 * (mObjCount % 180/180.0)) * M_PI/180.0);

	VECTOR point;
	mObjTransform.SetX(mObjTransform.GetX() + (float)cos(mObjTransform.GetAngle())*mObjMoveSpeed);
	mObjTransform.SetY(mObjTransform.GetY() + mObjMoveSpeed);
}

//下がってきて停滞して上がっていく
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

// 下がって止まって左上
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

// 下がって止まって右上
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

// 下がって止まって下
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

// 下がって止まって左
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

// 下がって止まって右
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

// 下がって止まって左下
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

// 下がって止まって右下
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

// ひたすらに左下へ
void Enemy::MoverLeftDown(){
	if(mObjCount == 0){
		VECTOR force={mObjMoveSpeed,mObjMoveSpeed,0};
		SetForce(&force);
		mObjTransform.SetAngle(135 * M_PI/180);
	}
}

// ひたすらに右下へ
void Enemy::MoverRightDown(){
	if(mObjCount == 0){
		VECTOR force={mObjMoveSpeed,mObjMoveSpeed,0};
		SetForce(&force);
		mObjTransform.SetAngle(45 * M_PI/180);
	}
}
