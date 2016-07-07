#define _USE_MATH_DEFINES
#include <cmath>
#include "DxLib.h"
#include "Enemy.h"

#include "Bullet.h"
#include "UnitAdmin.h"
#include "EnemyOrder.h"

Enemy::Enemy(UnitAdmin* unitadmin):Unit(unitadmin){
}
Enemy::~Enemy(){
}
void Enemy::Initialize(){
	mForce.x		= 3;
	mForce.y		= 2;
	mObjCount		= 0;
	mObjHitArea		= (float)DefaultHitArea;
	mObjHostility	= true;
	mObjFlag		= false;
	mHP				= 100;

	/*== 移動用関数ポインタ配列初期化 ================*/
	Mover[0]  = &Enemy::MoverLeft;
	Mover[1]  = &Enemy::MoverUp;
	Mover[2]  = &Enemy::MoverRight;
	Mover[3]  = &Enemy::MoverDown;
	Mover[4]  = &Enemy::MoverLeftDown;
	Mover[5]  = &Enemy::MoverRightDown;
	Mover[6]  = &Enemy::MoverDownToLeft;
	Mover[7]  = &Enemy::MoverDownToUp;
	Mover[8]  = &Enemy::MoverDownToRight;
	Mover[9]  = &Enemy::MoverDownToDown;
	Mover[10] = &Enemy::MoverDownToUpLeft;
	Mover[11] = &Enemy::MoverDownToUpRight;
	Mover[12] = &Enemy::MoverDownToLeftDown;
	Mover[13] = &Enemy::MoverDownToRightDown;
	Mover[14] = &Enemy::MoverCos;

	/*== 射撃用関数ポインタ配列初期化 ================*/
	Shooter[0]= &Enemy::ShooterTargetShoot;

}
void Enemy::Finalize(){
}
/*==  ================*/
void Enemy::SetImage(int* img){
	mObjImg = img;
}
void Enemy::Spawn(float x, float y, float angle){
	mObjTransform.SetX(x);
	mObjTransform.SetY(y);
	mObjTransform.SetAngle(angle);

	mState.HP				= 10;
	mState.AtackBulletColor = 0;
	mState.AtackCount		= 0;
	mState.AtackTime		= GetRand(20)+20;
	mState.Kind				= 0;
	mState.MoveKind			= 14;

	mHP						= mState.HP;

	mObjCount = 0;
	mObjFlag = true;
}
void Enemy::Spawn(EnemyOrder* order){
	mState					=*order->GetEnemyState();

	mObjTransform.SetX((float)order->GetOrderState()->SpawnX);
	mObjTransform.SetY((float)order->GetOrderState()->SpawnY);
	mObjMoveSpeed			=(float)order->GetOrderState()->SpawnSpd;
	mHP						=order->GetEnemyState()->HP;

	mObjCount				= 0;
	mObjFlag				= true;
}

void Enemy::Move(){
	(this->*(this->Mover[mState.MoveKind]))();

	mObjTransform.Move(mForce.x, mForce.y);

	int margin = 40;
	if(	mObjTransform.GetX()<FeeldZeroX-margin	|| mObjTransform.GetX()>FeeldMaxX+margin	||
		mObjTransform.GetY()<FeeldZeroY-200		|| mObjTransform.GetY()>FeeldMaxY+margin	){
			mObjFlag = false;
	}
}
void Enemy::Shot(){
	if(mObjCount == mState.AtackTime){
		(this->*(this->Shooter[0]))();
	}
}
void Enemy::Draw(){
	if(mObjFlag){
		// 2Dグラフィック表示
		DrawRotaGraphFdF();
	}
}
void Enemy::Update(){
	if(mObjFlag){
		Move();			// 移動
		Shot();			// 射撃

		if(mUniInvisible>0){ mUniInvisible--; }	
		mObjCount++;
	}
}

