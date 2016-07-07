#include "DxLib.h"
#include "PasPlay.h"

/*== GameOver ================*/
void PasPlay::GoToGameOver(){
// 「ゲームオーバー」
	stdCount=0;
	GhLogo = LoadGraph("dat/image/play/logo/gameover.png");
	flgGameOver=true;
}
void PasPlay::UpdateGameOver(){
// 
	if(stdCount++>200){
		mPhaseChanger->ChangePhase(ePhaseGameOver);
	}
}
void PasPlay::DrawGameOver(){
	DrawGraph(80, 250, GhLogo, true);
}
