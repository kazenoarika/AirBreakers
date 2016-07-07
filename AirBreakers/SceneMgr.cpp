#include "SceneMgr.h"

#include "seqTitle.h"
#include "seqPlay.h"
#include "seqInterval.h"
#include "seqClear.h"


SceneMgr::SceneMgr(void):mNextScene(eSceneNone)
{
	// �͂��߂̓^�C�g����ʂ���
	mScene.reset(new Title(this));
}

SceneMgr::~SceneMgr(void){
}

void SceneMgr::Initialize(){
	mScene->Initialize();
}

void SceneMgr::Finalize(){
	mScene->Finalize();
}

//�X�V
void SceneMgr::Update(){
	if(mNextScene != eSceneNone){
		mScene->Finalize();	// ���݂̃V�[���̏I�����������s

		switch(mNextScene){
			case eSceneTitle:
				mScene.reset(new Title(this));	// �^�C�g����ʂ̃C���X�^���X
				break;
			case eScenePlay:
				mScene.reset(new Play(this));	// �v���C��ʂ̃C���X�^���X
				break;
			case eSceneInterval:
				mScene.reset(new Interval(this));	// �C���^�[�o����ʂ̃C���X�^���X
				break;
			case eSceneClear:
				mScene.reset(new Clear(this));	// �N���A�[��ʂ̃C���X�^���X
				break;
		}
		mNextScene = eSceneNone;	//���̃V�[�������N���A
		mScene->Initialize();
	}

	mScene->Update();	// �V�[���̍X�V
}

void SceneMgr::Draw(){
	mScene->Draw();	// �V�[���̕`��
}

void SceneMgr::ChangeScene(eScene NextScene){
	mNextScene = NextScene;	// ���̃V�[���̃Z�b�g
}