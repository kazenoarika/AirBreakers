#include "DxLib.h"
#include "PasPlay.h"

/*== Clear ================*/
void PasPlay::GoToClear(){
// �u�~�b�V�����N���A�v
	GhLogo = LoadGraph("dat/image/play/logo/clear.png");
	stdCount=0;
	flgClear=true;
}
void PasPlay::UpdateClear(){
// �N���A���̉��o
	if(stdCount++>200){
		GoToResult();
	}
}
void PasPlay::DrawClear(){
// �u�~�b�V�����N���A�v���S�\��
	DrawGraph(50, 250, GhLogo, true);
}
