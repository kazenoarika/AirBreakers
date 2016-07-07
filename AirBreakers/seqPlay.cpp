#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"

#include "seqPlay.h"
#include "Stage01.h"
#include "Game.h"

Play::Play(ISceneChanger* changer) : BaseScene(changer){
}
Play::~Play(){
}
void Play::Initialize(){
	flgMenu = false;
	cutMenuAnime = 0;
	cutMenuAnimeMax = 0;

	flgMenuYesNo = false;
	cutMYNAnime = 0;
	cutMYNAnimeMax = 0;

	Stage.reset(new Stage01());
	pInput=Game::Instance()->GetInput();	// 入力情報のポインタ受け取り
}
void Play::Finalize(){
}

/*== Menu ================*/
void Play::GoToMenu(){
	const int menuLength = 4;

	const int menuStdX		= Game::Instance()->WindowWidth/2;
	const int menuStdY		= Game::Instance()->WindowHeight/2;
	const int selMenuStdX	= menuStdX;
	const int selMenuStdY	= menuStdY - 152;
	const int betweenY		= 112;

	for(int i=0;i<menuLength;i++){
		mMenumgr.GetMenu(i)->SetMenu(selMenuStdX, selMenuStdY+(i*betweenY), "", "");
	}

	const std::string dirpass("dat/image/play/menu/");
	const std::string filename[] ={ "mResutart.png", "mTerms.png", "mOption.png", "mGoTitle.png" };
	std::string tmp;
	tmp = dirpass + "mBoard.png";
	GhMenuBoard = LoadGraph(tmp.c_str());
	for(int i=0;i<menuLength;i++){
		tmp = dirpass + filename[i];
		GhMenuHover[i] = LoadGraph(tmp.c_str());
	}


	mMenumgr.SetCurrent(0);
	mMenumgr.SetSelectMax(menuLength);
	cutMenuAnime = 0;
	cutMenuAnimeMax = 10;
	flgMenu=true;
}
void Play::UpdataMenu(){
	if(cutMenuAnime>=cutMenuAnimeMax){	// アニメーションが終わっていれば
		if(pInput->IsPushShot()==1){
			switch(mMenumgr.GetCurrent()){
				case 0:		// メニューを閉じる
					flgMenu=false;
					break;
				case 1:		// クリア条件確認
					break;
				case 2:		// オプション
					break;
				case 3:		// タイトルにもどる
					GoToYesNoMenu();
					break;
			}
		}
		if(pInput->IsPushUp()==1){
			mMenumgr.CurrentUp();
		}
		if(pInput->IsPushDown()==1){
			mMenumgr.CurrentDown();
		}
	}else{								// アニメーション中なら
		cutMenuAnime++;
	}
}
void Play::DrawMenu(){
/*== メニュー描画 ================*/
	int menuStdX = Game::Instance()->WindowWidth/2;
	int menuStdY = Game::Instance()->WindowHeight/2;

	SetDrawBlendMode( DX_BLENDMODE_ALPHA, 120);
	DrawFillBox(												// 黒く上塗り
		0,
		0,
		Game::Instance()->WindowWidth,
		Game::Instance()->WindowHeight,
		GetColor(40,40,40)
	);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0);

	float exrate = sin( (M_PI/2) * ((float)cutMenuAnime/cutMenuAnimeMax));
	DrawRotaGraph(menuStdX,menuStdY,exrate,0,GhMenuBoard,true);		// ポーズメニューフレーム

	if(cutMenuAnime>=cutMenuAnimeMax){
		DrawRotaGraph(												//メニュー項目画像
			mMenumgr.GetCurrentMenu()->GetTransform().GetX(),
			mMenumgr.GetCurrentMenu()->GetTransform().GetY(),
			exrate,
			0,
			GhMenuHover[mMenumgr.GetCurrent()],
			true
		);
	}
}

/*==  ================*/
void Play::GoToYesNoMenu(){
	const std::string dirpass("dat/image/play/menu/");
	const std::string filename[]={"mYNBrdYes.png","mYNBrdYes_Dark.png","mYNBrdNo_Dark.png","mYNBrdNo.png"};

	std::string tmp = dirpass + "mYNBrd.png";
	GhMYNBoard = LoadGraph(tmp.c_str());							// ボード画像読み込み
	for(int i=0;i<sizeof(filename)/sizeof(filename[0]);i++){	
		tmp = dirpass + filename[i];
		GhMYNSelecter[i] = LoadGraph(tmp.c_str());				// はい/いいえの画像読み込み
	}

	cutMYNAnime = 0;
	cutMYNAnimeMax = 10;
	flgMenuYesNo =true;
}
void Play::UpdateYesNoMenu(){
	if(cutMYNAnime>=cutMYNAnimeMax){
		if((pInput->IsPushLeft()==1)||(pInput->IsPushRight()==1)){
			flgYesNo = !flgYesNo;
		}
		if(pInput->IsPushShot()){
			if(flgYesNo){
				mSceneChanger->ChangeScene(eSceneTitle);
			} else {
				flgMenuYesNo = false;
			}
		}
	}else{
		cutMYNAnime++;
	}
}
void Play::DrawMenuYesNo(){
	int menuStdX = Game::Instance()->WindowWidth/2;
	int menuStdY = Game::Instance()->WindowHeight/2;

	const float exrate = sin( (M_PI /2) * (cutMYNAnime/cutMYNAnimeMax) );
	DrawRotaGraph(menuStdX, menuStdY, exrate, 0, GhMYNBoard, true);

	if(cutMYNAnime>=cutMYNAnimeMax){
		DrawFormatString(menuStdX-120, menuStdY-50, GetColor(255,255,255), "本当にタイトルに戻りますか？");

		const int spaceX = 80;
		const int spaceY = 60;
		const int tmpSubscript = flgYesNo ? 1 : 0;
		DrawRotaGraph(menuStdX-(spaceX * exrate), menuStdY+(spaceY * exrate), exrate, 0 ,GhMYNSelecter[tmpSubscript],true);
		DrawRotaGraph(menuStdX+(spaceX * exrate), menuStdY+(spaceY * exrate), exrate, 0 ,GhMYNSelecter[tmpSubscript+2],true);
	}
}

/*==  ================*/
void Play::Draw(){
	Stage->Draw();

	if(flgMenu){
		DrawMenu();
		if(flgMenuYesNo){ DrawMenuYesNo(); }
	}	// メニュー表示
}
void Play::Update(){
	if(flgMenu){								// メニューが開かれていれば
		if(flgMenuYesNo){
			UpdateYesNoMenu();
		}else{
			UpdataMenu();						// メニュー処理
		}
	} else {
		if(!(cutMenuAnime-->0)){
			if(CheckHitKey(KEY_INPUT_ESCAPE)){	// Escキーが押されていれば
				GoToMenu();
			}
			mPhaseMgr.Update();					// フェイズ更新
			if(mPhaseMgr.GetEnd()){
				if(Player::Instance()->GetNextStageNumber()==0){
					mSceneChanger->ChangeScene(eSceneTitle);
				} else {
					mSceneChanger->ChangeScene(eSceneInterval);
				}
			}
			if(mPhaseMgr.GetClear()){
				mSceneChanger->ChangeScene(eSceneInterval);
			}
		}
	}

}
