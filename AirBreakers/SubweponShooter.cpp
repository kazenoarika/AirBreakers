#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "PlayerUnit.h"
#include "UnitAdmin.h"
#include "Bullet.h"

void PlayerUnit::ShooterTwinStrike(Subwepon* subwepon){
	// ’e‚Ì€”õ
	BulletStatus tmpState;
	tmpState.Kind			=eKindNomal;
	tmpState.Speed			=subwepon->GetStatus().Speed;
	tmpState.Damage			=subwepon->GetStatus().Damage;
	tmpState.Penetoration	=subwepon->GetStatus().Penetoration;
	//tmpState.AfterImage	=subwepon->GetStatus();
	tmpState.HitArea		=subwepon->GetStatus().HitArea;
	//tmpState.Homing		=subwepon->GetStatus();

	int i;	
	int defSpaceX = flgSlow ? 14 : 28;
	for(int j=0;j<2;j++){
		if((i = pUnitAdmin->SearchEmptyBullet()) != -1){
			defSpaceX *= (-1);
			const float defX = mObjTransform.GetX()+defSpaceX;
			const float defY = mObjTransform.GetY()+5;
			pUnitAdmin->GetBullet(i)->Shot(defX, defY, mObjTransform.GetAngle(), mObjHostility, &tmpState);
		}
	}
}

void PlayerUnit::ShooterLanceShot(Subwepon* subwepon){
	// ’e‚Ì€”õ
	BulletStatus tmpState;
	tmpState.Kind			=eKindNomal;
	tmpState.Speed			=subwepon->GetStatus().Speed;
	tmpState.Damage			=subwepon->GetStatus().Damage;
	tmpState.Penetoration	=subwepon->GetStatus().Penetoration;
	//tmpState.AfterImage	=subwepon->GetStatus();
	tmpState.HitArea		=subwepon->GetStatus().HitArea;
	//tmpState.Homing		=subwepon->GetStatus();

	int i = pUnitAdmin->SearchEmptyBullet();
	if(i != -1){
		pUnitAdmin->GetBullet(i)->Shot(mObjTransform.GetX(),mObjTransform.GetY(), mObjTransform.GetAngle(), mObjHostility, &tmpState);
	}
}

void PlayerUnit::ShooterRazr(Subwepon* subwepon){
	// ’e‚Ì€”õ
	BulletStatus tmpState;
	tmpState.Kind			=eKindNomal;
	tmpState.Speed			=subwepon->GetStatus().Speed;
	tmpState.Damage			=subwepon->GetStatus().Damage;
	tmpState.Penetoration	=subwepon->GetStatus().Penetoration;
	//tmpState.AfterImage	=subwepon->GetStatus();
	tmpState.HitArea		=subwepon->GetStatus().HitArea;
	//tmpState.Homing		=subwepon->GetStatus();
}

void PlayerUnit::ShooterDrill(Subwepon* subwepon){
	// ’e‚Ì€”õ
	BulletStatus tmpState;
	tmpState.Kind			=eKindDrill;
	tmpState.Speed			=subwepon->GetStatus().Speed;
	tmpState.Damage			=subwepon->GetStatus().Damage;
	tmpState.Penetoration	=subwepon->GetStatus().Penetoration;
	//tmpState.AfterImage	=subwepon->GetStatus();
	tmpState.HitArea		=subwepon->GetStatus().HitArea;
	//tmpState.Homing		=subwepon->GetStatus();
}

void PlayerUnit::ShooterParticle(Subwepon* subwepon){
	// ’e‚Ì€”õ
	BulletStatus tmpState;
	tmpState.Kind			=eKindNomal;
	tmpState.Speed			=subwepon->GetStatus().Speed;
	tmpState.Damage			=subwepon->GetStatus().Damage;
	tmpState.Penetoration	=subwepon->GetStatus().Penetoration;
	//tmpState.AfterImage	=subwepon->GetStatus();
	tmpState.HitArea		=subwepon->GetStatus().HitArea;
	//tmpState.Homing		=subwepon->GetStatus();

	int i = pUnitAdmin->SearchEmptyBullet();
	float rand = (flgSlow) ? (-90)+(GetRand(45.0) - (45.0/2.0)) : (-90)+(GetRand(90.0) - 45);
	rand *= M_PI/180.0;

	if(i != -1){
		pUnitAdmin->GetBullet(i)->Shot(mObjTransform.GetX(), mObjTransform.GetY(), rand, mObjHostility, &tmpState);
	}
}