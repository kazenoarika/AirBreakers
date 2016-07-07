#pragma once

#include "Subweponbox.h"
#include "Materialbox.h"
#include "Stage.h"

class Player
{
private:
	Player();
	Player& operator=(const Player& player){};
	~Player(void);

	void Updata();

	StageStatus mStageScore[10];
	Subweponbox mSubweponbox; // �������Ă���T�u�E�F�|��
	Materialbox mMaterialbox;	// �������Ă���T�u�E�F�|��

	int mMaxHP;	// �ő�HP
	int mMoney;	// ������
	int mClearedStage;	// �Ō�ɃN���A�����X�e�[�W

	double mPlaytime;	// �v���C���ԁi�b�j

public:
	static Player* Instance(){
		static Player inst;
		return &inst;
	}

	void InstPlayer();
	void SetPlayer(int MHP, Subweponbox* swBox, Materialbox* MBox, int Money, double PlayTime);

	// MaxHP
	int GetMaxHP();
	void SetMaxHP(int MHP);
	void PlusMaxHP(int plusMHP);

	// Subweponbox
	Subweponbox* GetSubweponbox();
	
	// EquipSW
	void SetEquipSW(int i, int SWnum);
	
	// Materialbox
	Materialbox GetMaterialbox();
	
	// Money
	int GetMoney();
	void SetMoney(int money);
	void PlusMoney(int plusMoney);

	// PlayTime
	double GetPlaytime();
	void SetPlayTime(double playtime);

	int GetNextStageNumber(){ return mClearedStage+1; }
};

