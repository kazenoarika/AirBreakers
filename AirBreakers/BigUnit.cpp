#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "BigUnit.h"
#include "Bullet.h"
#include "PlayerUnit.h"
#include "UnitAdmin.h"

BigUnit::BigUnit(UnitAdmin* unitadmin):Enemy(unitadmin){
	mObjKind		= eObjKindBoss;
	mPhase			= 0;
}
BigUnit::~BigUnit(){
}

void BigUnit::Initialize(){
	GhUnit = LoadGraph("dat/image/play/enemy/ver/verEnemy00.png");

	mHP = 500;
	mObjHitArea = 120;
	mObjFlag = false;
//	Shooter[0] = &BigUnit::ShooterAllrange;
}
void BigUnit::Finalize(){
	DeleteGraph(GhUnit);
}
void BigUnit::Draw(){
	if(mObjFlag){
		DrawRotaGraphFdF(&mObjTransform, 10, mObjTransform.GetAngle(), GhUnit, true, false);
	}
}
void BigUnit::Update(){
	if(mObjFlag){
		if(mObjCount ==  0){ mForce.y = 4; }
		if(mObjCount == 80){ mForce.y = 0; }
		if(mObjCount  > 80){ ShooterAllrange(); }

		Move();
		if(mUniInvisible>0){ mUniInvisible--; }	
		mObjCount++;
	}
}

void BigUnit::Move(){
	mObjTransform.Move(mForce.x, mForce.y);
}

void BigUnit::Spawn(){
	mObjTransform.SetX(FeeldMaxX/2)		;
	mObjTransform.SetY(-60)				;
	mObjTransform.SetAngle(0* M_PI/180)	;

	mObjCount		= 0;
	mObjHostility	= true;
	mObjFlag		= true;
}

/*== シューター ================*/
void BigUnit::ShooterAllrange(){
	PlayerUnit* pPU = pUnitAdmin->GetPlayerUnit();
	BulletStatus tmpState;

	tmpState.Kind			=eKindNomal;
	tmpState.Speed			=4;
	tmpState.Damage			=10;
	tmpState.Penetoration	=0;
	//tmpState.AfterImage	=subwepon->GetStatus();
	tmpState.HitArea		=DefaultHitArea;
	//tmpState.Homing		=subwepon->GetStatus();

	double angle = atan2(pPU->GetTransform().GetY()-mObjTransform.GetY(), pPU->GetTransform().GetX() - mObjTransform.GetX());
	int tmp;
	if(mObjCount % 30 == 0){
		for(int i=0;i<20;i++){
			if((tmp = pUnitAdmin->SearchEmptyBullet()) != -1){
				pUnitAdmin->GetBullet(tmp)->Shot(mObjTransform.GetX(), mObjTransform.GetY(), angle+M_PI*2/20*i, mObjHostility, &tmpState);
			}
		}
	}
}