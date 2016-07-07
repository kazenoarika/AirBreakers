#include "DxLib.h"
#include "PasPlay.h"

#include "UnitAdmin.h"
#include "Audio.h"

/*== Warning ================*/
void PasPlay::GoToWarning(){
	stdCount =0;
	GhWarning	= LoadGraph("dat/image/system/error.png");
	GhLogo		= LoadGraph("dat/image/play/logo/warning.png");
	mSE[0]->Play();
	flgWarning = true;
}
void PasPlay::UpdateWarning(){
	if(stdCount == 399){
		mUnitAdmin->SpawnBoss();	// ワーニング処理が終わるタイミングでボスをスポーン
		mSE[0]->Stop();
		flgBoss = true;				// ボスフラグを立てる
		flgWarning = false;			// ワーニング終了
	}
	stdCount++;
}
void PasPlay::DrawWarning(){
	if(stdCount%200 < 120){
		for(int i=0;i<8;i++){
			for(int j=0;j<6;j++){
				DrawGraph( (100*i), (100*j), GhWarning, true);
			}
		}

		DrawRotaGraphF(308,300,1,0, GhLogo,true);
	}
}