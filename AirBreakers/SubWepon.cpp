#include "DxLib.h"

#include "SubWepon.h"

Subwepon::Subwepon(){
	mStatus.Id			=-1;
	mStatus.Name		="";
	mStatus.Kind		=0;
	mStatus.Damage		=0;
	mStatus.HitArea		=0;
	mStatus.Rappid		=0;
	mStatus.Penetoration=0;
	mStatus.LoadNumber	=0;
	mStatus.Speed		=0.0f;
}
Subwepon::~Subwepon(){}

/*==  ================*/


/*== Get/Set ================*/
SubweponStatus Subwepon::GetStatus(){
	return mStatus;
}
void Subwepon::SetSubwepon(SubweponStatus status){
	mStatus = status;
}

