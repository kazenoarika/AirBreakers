#include "TitleMgr.h"

#include "TopInTitle.h"
#include "MenuInTitle.h"
#include "LoadInTitle.h"
#include "OptionInTitle.h"

CTitleMgr::CTitleMgr(void):mNextTitle(eStateNone){
	changer.reset(this);
	spTitle.reset(new CTopInTitle(changer));
}


CTitleMgr::~CTitleMgr(void){
}

void CTitleMgr::Initialize(){
	spTitle->Initialize();
}

void CTitleMgr::Finalize(){
	spTitle->Finalize();
}

void CTitleMgr::Update(){
	if(mNextTitle != eStateNone){
		spTitle->Finalize();		// ���݂̃V�[�P���X�̏I������

		// �w�肳�ꂽ�C���X�^���X���쐬����
		switch(mNextTitle){
			case eStateTop:
				spTitle.reset(new CTopInTitle(changer));
				break;
			case eStateMenu:
				spTitle.reset(new CMenuInTitle(changer));
				break;
			case eStateLoad:
				spTitle.reset(new CLoadInTitle(changer));
				break;
			case eStateOption:
				spTitle.reset(new COptionInTitle(changer));
				break;
		}
		spTitle->Initialize();		// �V�[�P���X�̏�����
		mNextTitle = eStateNone;	// �ʏ���
	}

	spTitle->Update();				// �V�[���̍X�V
}

void CTitleMgr::Draw(){
	spTitle->Draw();
}

void CTitleMgr::ChangeScene(eStateTitleMode NextScene){
	mNextTitle = NextScene;
}