#include "Player.h"


Player::Player(void){
	mMaxHP = 100;
	mMoney = 0;
	mPlaytime = 0.0f;
	mClearedStage = -1;
}
Player::~Player(void){}

void Player::InstPlayer(){
// �͂��߂����I�񂾎��̏����ݒ�
	mMaxHP = 100;

	/*== �T�u�E�F�|�� ================*/
	mSubweponbox.GetSubweponForCSV(0);
	mSubweponbox.GetSubweponForCSV(4);
	mSubweponbox.SetEquipSW(0, 0);
	mSubweponbox.SetEquipSW(1, 1);

	/*== �}�e���A�� ================*/
	mMaterialbox;
	mMoney = 0;
	mPlaytime = 0.0f;
}
void Player::SetPlayer(int MHP, Subweponbox* swBox, Materialbox* MBox, int Money, double PlayTime){
	mMaxHP = MHP;
	mSubweponbox = *swBox;
	mMaterialbox = *MBox;
	mMoney = Money;
	mPlaytime = PlayTime;
}
void Player::Updata(){
	mPlaytime++;
}

/*== MaxHP ================*/
int Player::GetMaxHP(){
	return this->mMaxHP;
}
void Player::SetMaxHP(int MHP){
	if(MHP>0){ this->mMaxHP = MHP; }
}
void Player::PlusMaxHP(int PlusMHP){
	if(PlusMHP > 0){ mMaxHP+= PlusMHP; }
}

/*== Subweponbox ================*/
Subweponbox* Player::GetSubweponbox(){
	return &mSubweponbox;
}
	
/*== Materialbox ================*/
Materialbox Player::GetMaterialbox(){
	return mMaterialbox;
}
	
/*== Money ================*/
int Player::GetMoney(){
	return this->mMoney;
}
void Player::SetMoney(int money){
	if((mMoney = money)<0){
		mMoney = 0;
	}
}
void Player::PlusMoney(int plusMoney){
	if((mMoney+=plusMoney)<0){
		mMoney = 0;
	}
}

/*== PlayTime ================*/
double Player::GetPlaytime(){
	return this->mPlaytime;
}
void Player::SetPlayTime(double playtime){
	if(playtime<0){
		mPlaytime = playtime;
	}
}
