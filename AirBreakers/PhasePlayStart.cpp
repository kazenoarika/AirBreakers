#include "DxLib.h"
#include "PasPlay.h"

#include "UnitAdmin.h"

/*== Start ================*/
void PasPlay::GoToStart(){
// �u�~�b�V�����X�^�[�g�v�\��

	stdCount=0;
	/*== �O���t�B�b�N ================*/
	GhLogo = LoadGraph("dat/image/play/logo/start.png");	// �X�e�[�W�X�^�[�g���S

	mUnitAdmin->GameInit();								// ���j�b�g�����Z�b�g
	flgStart=true;
}
void PasPlay::UpdateStart(){
// �~�b�V�����X�^�[�g����
	if(stdCount++>200){
		flgStart=false;
	}
}
void PasPlay::DrawStart(){
// �u�~�b�V�����X�^�[�g�v���S�̕\��
	int  tmpX = stdCount <20 ? (23*stdCount)-400 : 50;
	DrawGraph(tmpX, 250, GhLogo, true);
}

