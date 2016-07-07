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
		mSE[i] = new Audio();	// 生成
		mSE[i]->Initialize();	// 初期化
	}
}
PasPlay::~PasPlay(void){
	for(int i=0;i<MaxSE;i++){
		delete mSE[i];	// 初期化
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

	/*== グラフィック ================*/
	// 背景
	GhBackground= LoadGraph("dat/image/play/background/galaxy00.jpg");			// 背景
	GhCloud		= LoadGraph("dat/image/play/background/cloud00.png");			// 雲
	LoadDivGraph("dat/image/play/effect/burn_00.png",16,16,1,32,32,GhBurn00);	// 爆発1
	LoadDivGraph("dat/image/play/effect/burn_01.png",10,10,1,64,64,GhBurn01);	// 爆発1
	LoadDivGraph("dat/image/play/effect/burn_02.png",8,7,2,88,88,GhBurn02);		// 爆発2

	// ボード
	GhBoard			= LoadGraph("dat/image/play/frame/scoreboard00.png");		// スコアボード
	GhPlayerStatus	= LoadGraph("dat/image/play/frame/playerstatus.png");		// ゲージフレーム

	/*== オーディオ ================*/
	mSE[0]->SetAudio(LoadSoundMem("dat/audio/se/alert2.ogg"));			// アラート
		mSE[0]->SetLoopFlag(true);
	mSE[1]->SetAudio(LoadSoundMem("dat/audio/se/alart2.ogg"));			// クリア
	mSE[2]->SetAudio(LoadSoundMem("dat/audio/music/st011.mp3"));		// ゲームオーバー
		mSE[2]->SetVolume(120);
	mSE[3]->SetAudio(LoadSoundMem("dat/audio/se/kati.ogg"));			// 選択
		mSE[3]->SetVolume(180);


	/*==  ================*/
	mUnitAdmin.reset(new UnitAdmin());											// ユニットマネージャー
	mBackground.reset(new BackGround(&GhBackground, &GhCloud));					// バックグラウンドマネージャー
	mScoreBoard.reset(new ScoreBoard(&GhBoard, mUnitAdmin.get()));				// スコアボードマネージャー

	mBackground->Initialize();
	mScoreBoard->Initialize();
	mUnitAdmin->Initialize();

	GoToStart();
}
void PasPlay::Finalize(){
}
void PasPlay::Draw(){
// 描画処理
	mBackground->Draw();					// 背景
	mUnitAdmin->Draw();						// ゲームオブジェクト
	DrawPlayerStatusBar(200);				// ステータスバー

	if(flgWarning)	{ DrawWarning();	}	// ワーニング

	BoardStatus tmpBoard;
	mScoreBoard->Draw(GetBoardStatus(&tmpBoard));	// スコアボード

	/*==  ================*/
	if(flgStart)	{ DrawStart();		}	// ミッションスタート
	if(flgClear)	{ DrawClear();		}	// ミッションクリア
	if(flgGameOver)	{ DrawGameOver();	}	// ゲームオーバー
	if(flgResult)	{ DrawResult();		}	// リザルト

//	DrawDebug();
}
void PasPlay::Update(){
// 更新処理
	int i;
	for(i=0;i<MaxSE;i++){ mSE[i]->Initialize(); }
	mBackground->Update();					// 背景

	if(flgStart)	{ UpdateStart();	}	// ミッションスタート
	if(flgClear)	{ UpdateClear();	}	// ミッションクリア
	if(flgGameOver)	{ UpdateGameOver(); }	// ゲームオーバー
	if(flgResult)	{ UpdateResult();	}	// リザルト
	if(flgWarning)	{ UpdateWarning();	}	// ワーニング

	if(!flgStart && !flgClear && !flgResult){				// スタート且つクリアフラグが立っていなければ
		/*== 更新 ================*/
		mUnitAdmin->Update();								// ゲームオブジェクト
		mStage->HiScoreUpdate(mUnitAdmin->GetScore());		// ハイスコア更新
		mStage->HiDestroyUpdate(mUnitAdmin->GetDestroy());	// 破壊数記録更新

		if(!flgGameOver && FlagGameOver()){					// 失敗条件を満たしてしまうとクリアしててもゲームオーバー
			GoToGameOver();
		}
		if(!flgGameOver && !flgClear && FlagClear()){		// ゲームオーバーではなく、クリア条件を満たしているとクリア
			//GoToClear();
		}
		if(!flgWarning && mUnitAdmin->GetBossReadyFlag()){ GoToWarning(); }// ボスの条件が整ったか否か
		if(flgBoss){										// ボスフラグが立っている状態で
			if(!mUnitAdmin->GetBossFlg()){					// ボスが消えると
				GoToClear();								// クリア
				flgBoss = false;
			}
		}
	} //if(!flgStart && !flgClear && !flgResult)

	for(i=0;i<MaxSE;i++){ mSE[i]->Update();	}				// 再生するオーディオを再生
}

void PasPlay::DrawPlayerStatusBar(int Alpha){
// 自機のステータスを表示する
	int HPBoxTLX = 52;								// 表示開始位置
	int HPBoxTLY = 555;
	int HPBoxWidth = ( (float)mUnitAdmin->GetPlayerUnit()->GetHP() / (float)Player::Instance()->GetMaxHP() ) * 131.0f;		// 塗りつぶすバーの長さ
	int HPBoxHeight = 8;							// 高さ

	/*== HPバー ================*/
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Alpha);	// 透明度を引数から設定
	DrawFillBox(HPBoxTLX, HPBoxTLY,	HPBoxTLX + HPBoxWidth, HPBoxTLY + HPBoxHeight, GetColor(20,220,210));	// 塗りつぶし長方形を描画(HP)

	/*== EPバー ================*/
	int EPBoxTLY = HPBoxTLY + HPBoxHeight+2;
	// 塗り長(EP)
	DrawFillBox(HPBoxTLX, EPBoxTLY, HPBoxTLX +131, EPBoxTLY + HPBoxHeight, GetColor(215,220,60));

	/*== フレーム ================*/
	DrawGraph(0,550, GhPlayerStatus, true);			// フレーム表示
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
bool PasPlay::FlagClear(){
// クリア条件判定
	return true;
}
bool PasPlay::FlagGameOver(){
// ゲームオーバー条件判定
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

