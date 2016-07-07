#define _USE_MATH_DEFINES
#include <cmath>
#include <string>

#include "DxLib.h"
#include "UnitAdmin.h"

#include "Player.h"
#include "Stage.h"
#include "PlayerUnit.h"
#include "Bullet.h"
#include "Item.h"
#include "Background.h"
#include "BigUnit.h"
#include "Audio.h"

UnitAdmin::UnitAdmin(){
	int i=0;

	mScore	=0;
	mDestroy=0;
	mMoney	=0;

	mJiki		= new PlayerUnit(this);	// ���@�錾
	mBigUnit	= new BigUnit(this);	// �{�X�̐錾
	mUnit[0]	= mJiki;				// ���@���Ǘ��z���
	mUnit[1]	= mBigUnit;				// �{�X���Ǘ��z���

	for(i=0;i<MaxUnit-2;i++){
		mEnemy[i] = new Enemy(this);	// �G�@�錾
		mUnit[i+2] = mEnemy[i];			// ���j�b�g�z��ɑ��
	}

	for(i=0;i<MaxBullet;i++){
		mBullet[i] = new Bullet(this);
	}
	for(i = 0;i<MaxObject;i++){
		mItem[i] = new Item(this);
	}

	mBGM = new Audio();			// ����
	mBGM->Initialize();			// ������
	for(i=0;i<MaxSE;i++){
		mSE[i] = new Audio();	// ����
		mSE[i]->Initialize();	// ������
	}


}
UnitAdmin::~UnitAdmin(){
	int i=0;
	for(i=0;i<MaxUnit;i++)				{ delete mUnit[i];		}	// Unit
	for(i=0;i<Bullet::ImageCount;i++)	{ delete mBullet[i];	}	// Bullet
	for(i=0;i<MaxObject;i++)			{ delete mItem[i];		}	// Item
	delete mBGM;													// BGM
	for(i=0;i<MaxSE;i++)				{ delete mSE[i];		}	// SE

}
void UnitAdmin::Initialize(){
	int i=0;

	/*==  ================*/
	mScore			= 0;
	mDestroy		= 0;
	mLastSpawnOrder = 0;
	mCount			= 0;
	flgBossReady	= false;

	/*== �O���t�B�b�N���[�h ================*/
	std::string dirPass("dat/image/play/bullet/");
	std::string fileName[]={"bul00.png", "bul01.png", "bul.png","item00.png", "item01.png","item02.png","item03.png","item04.png"};
	for(i=0;i<3;i++){			// �e�̉摜�̃��[�h
		std::string tmp = dirPass + fileName[i];
		GhBullets[i] = LoadGraph(tmp.c_str());
	}
	dirPass		= "dat/image/play/drop/";
	for(i=0;i<5;i++){			// �A�C�e���̉摜�̃��[�h
		std::string tmp = dirPass + fileName[i+3];
		GhItems[i] = LoadGraph(tmp.c_str());
	}
	GhEnemy = LoadGraph("dat/image/play/enemy/en_000.png");

	for(i=0;i<MaxBullet;i++){	// �e�̉摜��n��
		mBullet[i]->SetImage(GhBullets);
	}

	/*== �T�E���h ================*/
	mBGM->SetAudio(LoadSoundMem("dat/audio/music/tw045.ogg"));	// BGM
		mBGM->SetLoopFlag(true);
		mBGM->SetVolume(180);
	mSE[0]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_battle16.ogg"));	// �e�̔���
		mSE[0]->SetVolume(120);
	mSE[1]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_battle18.ogg"));	// ��e
		mSE[1]->SetVolume(150);
	mSE[2]->SetAudio(LoadSoundMem("dat/audio/se/gun-fire03.ogg"));					// ����

	/*==  ================*/
	for(i=0;i<MaxUnit;i++){		// ���j�b�g�̏�����
		mUnit[i]->Initialize();
	}
	LoadEnemyOrdertoCSV(0);		// �G�̔z�u�f�[�^�̓ǂݍ���

	/*==  ================*/
	mSWBox.GetSubweponForCSV(0);
	mSWBox.GetSubweponForCSV(0);
	mSWBox.GetSubweponForCSV(0);
	mSWBox.GetSubweponForCSV(0);
}
void UnitAdmin::Finalize(){
	int i;
	for(i=0;i<sizeof(GhBullets)/sizeof(GhBullets[0]);i++){
		DeleteGraph(GhBullets[i]);
	}
	for(i=0;i<sizeof(GhItems)/sizeof(GhItems[0]);i++){
		DeleteGraph(GhItems[i]);
	}
	DeleteGraph(GhEnemy);
	delete mBGM;
	for(i=0;i<MaxSE;i++){
		delete mSE[i];
	}
}
void UnitAdmin::Draw(){
	int i=0;
	// �e���j�b�g�̕`��
	for(i=0;i<MaxUnit;i++)	{ mUnit[i]->Draw();		}
	for(i=0;i<MaxBullet;i++){ mBullet[i]->Draw();	}
	for(i=0;i<MaxObject;i++){ mItem[i]->Draw();		}
}
void UnitAdmin::Update(){
	int i;
	mBGM->Initialize();
	for(i=0;i<MaxSE;i++){ mSE[i]->Initialize();	}

	// �e���j�b�g��Update
	for(i=0;i<MaxUnit;i++)	{ mUnit[i]->Update();	}
	for(i=0;i<MaxBullet;i++){ mBullet[i]->Update(); }
	for(i=0;i<MaxObject;i++){ mItem[i]->Update();	}

	// �����蔻��
	Judge();

	if(mCount == 0)		{ mBGM->Play(); }
	if(mCount<3000)		{ SpawnSearchOrder(); } 			// �I�[�_�[����G�l�~�[���X�|�[��
	if(3000<mCount && mCount<6000){ SpawnRandomEnemy(); }	// �G�@�������_���ŏo��������
	if(6000 == mCount)	{ flgBossReady = true; }			// �{�X�����ďo��������


	mBGM->Update();
	for(i=0;i<MaxSE;i++){ mSE[i]->Update();	}
	mCount++;
}

/*==  ================*/
void UnitAdmin::LoadEnemyOrdertoCSV(int stageNum = Player::Instance()->GetNextStageNumber()){
	int n, num, i, fp;
	char fname[256];
	int input[64];
	char inputc[64];

	
	sprintf_s(fname, "dat/stagedata/main/%02d/stagedata.csv",stageNum);
	fp = FileRead_open(fname);	// �t�@�C���ǂݍ���
	if(fp == NULL){
		printfDx("read error\n");
		return;
	}
	for(i=0;i<2;i++)	// �ŏ���2�s��ǂݔ�΂�
		while(FileRead_getc(fp)!='\n');

	n=0, num=0;

	EnemyState eneState;
	OrderState ordState;

	while(1){
		for(i=0;i<64;i++){
                        inputc[i]=input[i]=FileRead_getc(fp);//1�����擾����
                        if(inputc[i]=='/'){//�X���b�V���������
                                while(FileRead_getc(fp)!='\n');//���s�܂Ń��[�v
                                i=-1;//�J�E���^���ŏ��ɖ߂���
                                continue;
                        }
                        if(input[i]==',' || input[i]=='\n'){//�J���}�����s�Ȃ�
                                inputc[i]='\0';//�����܂ł𕶎���Ƃ�
                                break;
                        }
                        if(input[i]==EOF){//�t�@�C���̏I���Ȃ�
                                goto EXFILE;//�I��
                        }
                }
		switch(num){
			case  0: ordState.SpawnTime			=atoi(inputc);break;
			case  1: eneState.HP				=atoi(inputc);break;
			case  2: eneState.MoveKind			=atoi(inputc);break;
			case  3: eneState.Kind				=atoi(inputc);break;
			case  4: ordState.SpawnX			=atoi(inputc);break;
			case  5: ordState.SpawnY			=atoi(inputc);break;
			case  6: ordState.SpawnSpd			=atoi(inputc);break;
			case  7: eneState.AtackTime			=atoi(inputc);break;
			case  8: eneState.AtackCount		=atoi(inputc);break;
			case  9: eneState.AtackBulletColor	=atoi(inputc);break;
			case 10: eneState.WaitTime			=atoi(inputc);break;
		}
		num++;
		if(num==11){
			mEnemyOrder[n].SetOrderState(&ordState);
			mEnemyOrder[n].SetEnemyState(&eneState);
			num=0;
			n++;
		}
	}
	EXFILE:
		FileRead_close(fp);
}
void UnitAdmin::GameInit(){
	// �����̃X�|�[���ʒu
	mJiki->Spawn();
}
void UnitAdmin::DrawmHP(){
	// �e���j�b�g��HP�o�[�\��
	for(int i=0;i<MaxUnit;i++){
		mUnit[i]->DrawmHP();
	}
}
Unit* UnitAdmin::Nearest(Object* reqObject){
// ��ԋ߂��G�΃��j�b�g��Ԃ�
	Unit* returnUnit = NULL;
	int range = -1;

	const int reqX = reqObject->GetTransform().GetX();
	const int reqY = reqObject->GetTransform().GetY();


	for(int i=0;i<MaxUnit;i++){
		if(mUnit[i]->GetFlag()){
			if(reqObject->GetHostility() != mUnit[i]->GetHostility()){	// ���ʔ��肪�قȂ�Ȃ�
				const int tarX = mUnit[i]->GetTransform().GetX();
				const int tarY = mUnit[i]->GetTransform().GetY();

				const int tmpRange = (reqX - tarX) * (reqX - tarX) + (reqY - tarY) * (reqY - tarY);

				if(tmpRange < range || range==-1){
					returnUnit = mUnit[i];
					range = tmpRange;
				}
			}
		}
	}
	return returnUnit;
}	// Unit* UnitAdmin::Nearest(Object* reqObject)

void UnitAdmin::Judge(){
//	�����蔻��
	for(int i=0;i<MaxUnit;i++){
		if(mUnit[i]->GetFlag()){	// �����Ă郆�j�b�g���画��

			/*== �Βe���� ================*/
			for(int b=0;b<MaxBullet;b++){
				if(mBullet[b]->GetFlag()){	// �o�Ă�
					
					if(mUnit[i]->GetHostility() != mBullet[b]->GetHostility()){	// �G�Δ��肪�قȂ�Ȃ�

						if(Collider(mBullet[b], mUnit[i])){		// �������Ă���Ȃ�
							if(mUnit[i]->GetInvisible()==0){	// ��e�Ώۂ����G��ԂłȂ����
								mUnit[i]->Hit(mBullet[b]);		// ��e����
								mSE[1]->Play();
								if(mUnit[i]->GetHostility()){	// ��e�Ώۂ��G�Ȃ�
									mScore+=10;						// �������10�|�C���b�I
									if(!mUnit[i]->GetFlag()){		// �Ώۂ̓G������ł�����
										SpawnItem(mUnit[i], GetRand(3));	// �A�C�e���o��
										mScore+=100;				// �����I�ɃX�R�A�͓G�ɂ���ĈقȂ�悤�ɂ͂�����
										mDestroy++;					// ���j��������
									}
								}
							}
							mBullet[b]->Hit();					// �e�͑Ώۂ̖��G��Ԃɂ��Ȃ�

						}
					}
				}
			}// �Βe���肱���܂�

			/*== �΃��j�b�g���� ================*/
			for(int u=0;u<MaxUnit;u++){
				if(i==u){ continue; }		// �������g�ƍ��W���Ԃ�Ƃ�������O�����
				if(mUnit[u]->GetFlag()){	// �t���O�������Ă���
					if(mUnit[i]->GetHostility() != mUnit[u]->GetHostility()){	// �G�΂�
						if(Collider(mUnit[i], mUnit[u])){	// �������Ă���
							if(mUnit[i]->GetInvisible()==0){// ���G���ԂłȂ����
								mUnit[i]->Hit(mUnit[u]);	// ��e����
							}
						}
					}
				}
			}// �΃��j�b�g���肱���܂�

			// �΃A�C�e������
			if(i == 0){										// ���@�̂ݔ���
				for(int d=0;d<MaxObject;d++){
					if(mItem[d]->GetFlag()){				// �o�Ă�A�C�e��
						if(Collider(mUnit[i], mItem[d])){	// �ڐG����
							HitItem(mItem[d]);				// �A�C�e���̎�ނɂ��擾����
							mItem[d]->Hit();				// �A�C�e�����̂̐ڐG����
						}else{
							float r = sqrt(pow(mItem[d]->GetTransform().GetY()- mUnit[i]->GetTransform().GetY(), 2)+pow(mItem[d]->GetTransform().GetX()- mUnit[i]->GetTransform().GetX(), 2));
							if(r<mUnit[i]->GetHitArea()*5){
								float angle = atan2(mUnit[i]->GetTransform().GetY()-mItem[d]->GetTransform().GetY(), mUnit[i]->GetTransform().GetX()-mItem[d]->GetTransform().GetX());
								mItem[d]->GetTransform().SetAngle(angle);
								mItem[d]->SetMoveSpeed(mItem[d]->GetMoveSpeed()+0.3);
							}
						}
					}
				}
			}

		}
	}
}// void UnitAdmin::Judge()
bool UnitAdmin::Collider(Object* origin, Object* target){
	double oriX = origin->GetTransform().GetX();
	double oriY = origin->GetTransform().GetY();

	double tarX = target->GetTransform().GetX();
	double tarY = target->GetTransform().GetY();

	double r = sqrt(pow(tarY - oriY, 2) + pow(tarX - oriX, 2));

	// [origin] �� [target] �̋�����2�̃I�u�W�F�N�g�̃q�b�g�G���A�̍��v���Z���ꍇ
	if(r < origin->GetHitArea() + target->GetHitArea()){
		return true;	// ��������
	}
	return false;	// �����ĂȂ���ΊO��
}
void UnitAdmin::HitItem(Item* item){
	switch(item->GetKind()){
		case eItemKindScore:
			mScore += 1000 * item->GetRank();
			break;
		case eItemKindPower:
			break;
		case eItemKindEnegy:
			break;
		case eItemKindMoney:
			mMoney += 100 * item->GetRank();
			break;
		case eItemKindSubwepon:
			mSWBox.GetSubweponForCSV(0);
			break;
	}
}
void UnitAdmin::SpawnItem(Object* object, int itemNumber){
// �A�C�e���o��
	for(int i=0;i<itemNumber;i++){
		int tmpSub = SearchEmptyItem();
		if(tmpSub != -1){
			float angle = GetRand(180) * M_PI/180;
			int rand = GetRand(1000);

			eItemKind kind;
			if(				 rand <=  495){ kind = eItemKindScore;	}
			if(495 < rand && rand <=  990){ kind = eItemKindMoney;	}
			if(990 < rand && rand <= 1000){ kind = eItemKindSubwepon;	}

			mItem[tmpSub]->SetImage(&GhItems[kind]);
			mItem[tmpSub]->Spawn(object->GetTransform().GetX(), object->GetTransform().GetY(), -angle, kind);
		}
	}
}
void UnitAdmin::DrawDebug(){
	int terma = 1;
	int color = GetColor(255,255,255);

	switch(terma){
	case 0:
		DrawFormatString(16,520,color, "%d", mCount);
		for(int i =0;i<sizeof(mEnemy)/sizeof(mEnemy[0]);i++){
			DrawFormatString(16, 16+(i*16), color, "Bullet[%02d]:%d, [%f, %f]",
				i, mBullet[i]->GetFlag(), mBullet[i]->GetTransform().GetX(),mBullet[i]->GetTransform().GetY());
		}
		break;
	}
}

/*== �X�|�[���֐� ================*/
int UnitAdmin::SearchEmptyUnit(){
	int i;
	for(i=0;i<sizeof(mUnit)/sizeof(mUnit[0]);i++){
		if(!mUnit[i]->GetFlag()){
			return i;
		}
	}
	return -1;
}
int UnitAdmin::SearchEmptyEnemy(){
	int i;
	for(i=0;i<sizeof(mEnemy)/sizeof(mEnemy[0]);i++){
		if(!mEnemy[i]->GetFlag()){
			return i;
		}
	}
	return -1;
}
int UnitAdmin::SearchEmptyBullet(){
	for(int i=0;i<sizeof(mBullet)/sizeof(mBullet[0]);i++){
		if(!mBullet[i]->GetFlag()){ return i; }
	}
	return -1;
}
int UnitAdmin::SearchEmptyItem(){
	for(int i=0;i<sizeof(mItem)/sizeof(mItem[0]);i++){
		if(!mItem[i]->GetFlag()){ return i; }
	}
	return -1;
}
void UnitAdmin::SpawnRandomEnemy(){
//	�G�̃����_���o��
	if(mCount%3 == 0){
		int dice = GetRand(20);

		if(dice==1){
			int i= SearchEmptyEnemy();
			if(i!=-1){
				mEnemy[i]->SetImage(&GhEnemy);
				mEnemy[i]->Spawn(GetRand(600), 20, M_PI/2);
			}
		}
	}
}
void UnitAdmin::SpawnSearchOrder(){
	for(int i = mLastSpawnOrder;i<sizeof(mEnemyOrder)/sizeof(mEnemyOrder[0]);i++){
		if(	mEnemyOrder[i].GetOrderState()->SpawnTime != 0 &&
			mEnemyOrder[i].GetOrderState()->SpawnTime == mCount)
		{
			int tmpSubscript;
			if( (tmpSubscript =  SearchEmptyEnemy()) == -1){
				return;
			}

			mEnemy[tmpSubscript]->SetImage(&GhEnemy);
			mEnemy[tmpSubscript]->Spawn(&mEnemyOrder[i]);
			mLastSpawnOrder++;
		}
	}
}
void UnitAdmin::SpawnBoss(){
// �{�X���o��������
	mBigUnit->Spawn();
	flgBossReady = false;
}

bool UnitAdmin::GetBossFlg(){ return mBigUnit->GetFlag(); }