#include "DxLib.h"
#include "PasPlay.h"

/*== Clear ================*/
void PasPlay::GoToClear(){
// 「ミッションクリア」
	GhLogo = LoadGraph("dat/image/play/logo/clear.png");
	stdCount=0;
	flgClear=true;
}
void PasPlay::UpdateClear(){
// クリア時の演出
	if(stdCount++>200){
		GoToResult();
	}
}
void PasPlay::DrawClear(){
// 「ミッションクリア」ロゴ表示
	DrawGraph(50, 250, GhLogo, true);
}
