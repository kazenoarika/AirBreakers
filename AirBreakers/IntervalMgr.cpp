#include "IntervalMgr.h"

#include "IntervalMenu.h"
#include "IntervalStageSelect.h"
#include "IntervalSubwepon.h"
#include "IntervalMaterial.h"
#include "IntervalSave.h"

IntervalMgr::IntervalMgr(void){
	flgGoToScenePlay =false;
}
IntervalMgr::~IntervalMgr(void){
}

void IntervalMgr::Initialize(){
	mInterval.reset(new IntervalMenu(this));	
}

void IntervalMgr::Finalize(){
	mInterval->Finalize();
}

void IntervalMgr::Draw(){
	mInterval->Draw();
}

void IntervalMgr::Update(){
	if(mNextInter != eInterNone){
		mInterval->Finalize();	// ���݂̃V�[���̏I�����������s

		switch(mNextInter){
			case eInterMenu:
				mInterval.reset(new IntervalMenu(this));		// �g�b�v���j���[��ʂ̃C���X�^���X
				break;
			case eInterStageSelect:
				mInterval.reset(new IntervalStageSelect(this));	// �X�e�[�W�Z���N�g��ʂ̃C���X�^���X
				break;
			case eInterSW:
				mInterval.reset(new IntervalSubwepon(this));	// �T�u�E�F�|����ʂ̃C���X�^���X
				break;
			case eInterMaterial:
				mInterval.reset(new IntervalMaterial(this));	// �}�e���A����ʂ̃C���X�^���X
				break;
			case eInterSave:
				mInterval.reset(new IntervalSave(this));		// �Z�[�u��ʂ̃C���X�^���X
				break;
			case eInterGoToScenePlay:
				flgGoToScenePlay = true;
				break;
		}
		mNextInter = eInterNone;	//���̃V�[�������N���A
		mInterval->Initialize();
	}

	mInterval->Update();	// �V�[���̍X�V
}

void IntervalMgr::ChangeInterval(eInter nextInter){
	mNextInter = nextInter;
}