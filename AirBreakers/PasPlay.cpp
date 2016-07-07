#include "DxLib.h"
#include "PasPlay.h"

#include "Game.h"
#include "Background.h"
#include "UnitAdmin.h"
#include "PlayerUnit.h"
#include "Audio.h"
#include "Stage.h"

PasPlay::PasPlay(){
	for(int i=0;i<MaxSE;i++){
		mSE[i] = new Audio();	// ����
		mSE[i]->Initialize();	// ������
	}
}
PasPlay::~PasPlay(void){
	for(int i=0;i<MaxSE;i++){
		delete mSE[i];	// ������
	}
}
/*==  ================*/
void PasPlay::Initialize(){
	pInput = Game::Instance()->GetInput();

	flgStart	=false;
	flgClear	=false;
	flgGameOver	=false;
	flgWarning	=false;
	flgBoss		=false;
	flgResult	=false;
	flgWarning	=false;

	/*== �O���t�B�b�N ================*/
	// �w�i
	GhBackground= LoadGraph("dat/image/play/background/galaxy00.jpg");			// �w�i
	GhCloud		= LoadGraph("dat/image/play/background/cloud00.png");			// �_
	LoadDivGraph("dat/image/play/effect/burn_00.png",16,16,1,32,32,GhBurn00);	// ����1
	LoadDivGraph("dat/image/play/effect/burn_01.png",10,10,1,64,64,GhBurn01);	// ����1
	LoadDivGraph("dat/image/play/effect/burn_02.png",8,7,2,88,88,GhBurn02);		// ����2

	// �{�[�h
	GhBoard			= LoadGraph("dat/image/play/frame/scoreboard00.png");		// �X�R�A�{�[�h
	GhPlayerStatus	= LoadGraph("dat/image/play/frame/playerstatus.png");		// �Q�[�W�t���[��

	/*== �I�[�f�B�I ================*/
	mSE[0]->SetAudio(LoadSoundMem("dat/audio/se/alert2.ogg"));			// �A���[�g
		mSE[0]->SetLoopFlag(true);
	mSE[1]->SetAudio(LoadSoundMem("dat/audio/se/alart2.ogg"));			// �N���A
	mSE[2]->SetAudio(LoadSoundMem("dat/audio/music/st011.mp3"));		// �Q�[���I�[�o�[
		mSE[2]->SetVolume(120);
	mSE[3]->SetAudio(LoadSoundMem("dat/audio/se/kati.ogg"));			// �I��
		mSE[3]->SetVolume(180);


	/*==  ================*/
	mUnitAdmin.reset(new UnitAdmin());											// ���j�b�g�}�l�[�W���[
	mBackground.reset(new BackGround(&GhBackground, &GhCloud));					// �o�b�N�O���E���h�}�l�[�W���[
	mScoreBoard.reset(new ScoreBoard(&GhBoard, mUnitAdmin.get()));				// �X�R�A�{�[�h�}�l�[�W���[

	mBackground->Initialize();
	mScoreBoard->Initialize();
	mUnitAdmin->Initialize();

	GoToStart();
}
void PasPlay::Finalize(){
}
void PasPlay::Draw(){
// �`�揈��
	mBackground->Draw();					// �w�i
	mUnitAdmin->Draw();						// �Q�[���I�u�W�F�N�g
	DrawPlayerStatusBar(200);				// �X�e�[�^�X�o�[

	if(flgWarning)	{ DrawWarning();	}	// ���[�j���O

	BoardStatus tmpBoard;
	mScoreBoard->Draw(GetBoardStatus(&tmpBoard));	// �X�R�A�{�[�h

	/*==  ================*/
	if(flgStart)	{ DrawStart();		}	// �~�b�V�����X�^�[�g
	if(flgClear)	{ DrawClear();		}	// �~�b�V�����N���A
	if(flgGameOver)	{ DrawGameOver();	}	// �Q�[���I�[�o�[
	if(flgResult)	{ DrawResult();		}	// ���U���g

//	DrawDebug();
}
void PasPlay::Update(){
// �X�V����
	int i;
	for(i=0;i<MaxSE;i++){ mSE[i]->Initialize(); }
	mBackground->Update();					// �w�i

	if(flgStart)	{ UpdateStart();	}	// �~�b�V�����X�^�[�g
	if(flgClear)	{ UpdateClear();	}	// �~�b�V�����N���A
	if(flgGameOver)	{ UpdateGameOver(); }	// �Q�[���I�[�o�[
	if(flgResult)	{ UpdateResult();	}	// ���U���g
	if(flgWarning)	{ UpdateWarning();	}	// ���[�j���O

	if(!flgStart && !flgClear && !flgResult){				// �X�^�[�g���N���A�t���O�������Ă��Ȃ����
		/*== �X�V ================*/
		mUnitAdmin->Update();								// �Q�[���I�u�W�F�N�g
		mStage->HiScoreUpdate(mUnitAdmin->GetScore());		// �n�C�X�R�A�X�V
		mStage->HiDestroyUpdate(mUnitAdmin->GetDestroy());	// �j�󐔋L�^�X�V

		if(!flgGameOver && FlagGameOver()){					// ���s�����𖞂����Ă��܂��ƃN���A���ĂĂ��Q�[���I�[�o�[
			GoToGameOver();
		}
		if(!flgGameOver && !flgClear && FlagClear()){		// �Q�[���I�[�o�[�ł͂Ȃ��A�N���A�����𖞂����Ă���ƃN���A
			//GoToClear();
		}
		if(!flgWarning && mUnitAdmin->GetBossReadyFlag()){ GoToWarning(); }// �{�X�̏��������������ۂ�
		if(flgBoss){										// �{�X�t���O�������Ă����Ԃ�
			if(!mUnitAdmin->GetBossFlg()){					// �{�X���������
				GoToClear();								// �N���A
				flgBoss = false;
			}
		}
	} //if(!flgStart && !flgClear && !flgResult)

	for(i=0;i<MaxSE;i++){ mSE[i]->Update();	}				// �Đ�����I�[�f�B�I���Đ�
}

void PasPlay::DrawPlayerStatusBar(int Alpha){
// ���@�̃X�e�[�^�X��\������
	int HPBoxTLX = 52;								// �\���J�n�ʒu
	int HPBoxTLY = 555;
	int HPBoxWidth = ( (float)mUnitAdmin->GetPlayerUnit()->GetHP() / (float)Player::Instance()->GetMaxHP() ) * 131.0f;		// �h��Ԃ��o�[�̒���
	int HPBoxHeight = 8;							// ����

	/*== HP�o�[ ================*/
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Alpha);	// �����x����������ݒ�
	DrawFillBox(HPBoxTLX, HPBoxTLY,	HPBoxTLX + HPBoxWidth, HPBoxTLY + HPBoxHeight, GetColor(20,220,210));	// �h��Ԃ������`��`��(HP)

	/*== EP�o�[ ================*/
	int EPBoxTLY = HPBoxTLY + HPBoxHeight+2;
	// �h�蒷(EP)
	DrawFillBox(HPBoxTLX, EPBoxTLY, HPBoxTLX +131, EPBoxTLY + HPBoxHeight, GetColor(215,220,60));

	/*== �t���[�� ================*/
	DrawGraph(0,550, GhPlayerStatus, true);			// �t���[���\��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
bool PasPlay::FlagClear(){
// �N���A��������
	return true;
}
bool PasPlay::FlagGameOver(){
// �Q�[���I�[�o�[��������
	if(mUnitAdmin->GetPlayerUnit()->GetFlag()){ return false; }
	return true;
}

/*==  ================*/
BoardStatus* PasPlay::GetBoardStatus(BoardStatus *tmpBoard){
	tmpBoard->Score		= mUnitAdmin->GetScore();
	tmpBoard->HiScore	= mStage->GetStatus().HiScore;
	tmpBoard->Destroy	= mUnitAdmin->GetDestroy();
	tmpBoard->Time		= this->stdCount;
	tmpBoard->Money		= mUnitAdmin->GetMoney();
	return tmpBoard;
}
void PasPlay::DrawDebug(){
	const int menuDX = 16;
	const int menuDY = 16;
	const int betweenDY = 15;
	const int strColor = GetColor(255,80,80);

	const bool tmpBool[] = {flgStart,flgGameOver,flgBoss,flgClear,flgResult,flgWarning};
	const std::string tmpStr[] ={"Start","GmeOver","Boss","Clear","Result","Warning"};

	const int boolSize = sizeof(tmpStr)/sizeof(tmpStr[0]);
	int i=0;
	for(i=0;i<boolSize;i++){
		int tmp = tmpBool[i] ? 1 : 0;
		DrawFormatString(menuDX,menuDY+(i * betweenDY),strColor,"%-8s : %1d", tmpStr[i].c_str(), tmp );
	}

}

