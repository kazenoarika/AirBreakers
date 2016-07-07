#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "Enemy.h"
#include "PlayerUnit.h"
#include "UnitAdmin.h"
#include "Bullet.h"
#include "Audio.h"

void Enemy::ShooterTargetShoot(){
	PlayerUnit* pPU = pUnitAdmin->GetPlayerUnit();

	BulletStatus tmpState;
	tmpState.Kind			=eKindNomal;
	tmpState.Speed			=mObjMoveSpeed;
	tmpState.Damage			=10;
	tmpState.Penetoration	=0;
	//tmpState.AfterImage	=subwepon->GetStatus();
	tmpState.HitArea		=DefaultHitArea;
	//tmpState.Homing		=subwepon->GetStatus();

	double angle = atan2(pPU->GetTransform().GetY()-mObjTransform.GetY(), pPU->GetTransform().GetX() - mObjTransform.GetX());

	int i;
	if((i = pUnitAdmin->SearchEmptyBullet()) != -1){
		pUnitAdmin->GetBullet(i)->Shot(mObjTransform.GetX(), mObjTransform.GetY(), angle, mObjHostility, &tmpState);
		pUnitAdmin->GetSE(0)->Play();
	}
}