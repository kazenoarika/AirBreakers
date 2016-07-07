#include "DxLib.h"
#include "PasPlay.h"

#include "UnitAdmin.h"

/*== Start ================*/
void PasPlay::GoToStart(){
// 「ミッションスタート」表示

	stdCount=0;
	/*== グラフィック ================*/
	GhLogo = LoadGraph("dat/image/play/logo/start.png");	// ステージスタートロゴ

	mUnitAdmin->GameInit();								// ユニットをリセット
	flgStart=true;
}
void PasPlay::UpdateStart(){
// ミッションスタート処理
	if(stdCount++>200){
		flgStart=false;
	}
}
void PasPlay::DrawStart(){
// 「ミッションスタート」ロゴの表示
	int  tmpX = stdCount <20 ? (23*stdCount)-400 : 50;
	DrawGraph(tmpX, 250, GhLogo, true);
}

