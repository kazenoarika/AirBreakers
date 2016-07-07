#include "Game.h"
#include "MenuInTitle.h"
#include "Input.h"

CMenuInTitle::CMenuInTitle(const std::shared_ptr<ITitleChanger> changer):BaseTitle(changer){
}


CMenuInTitle::~CMenuInTitle(void){
}

void CMenuInTitle::Initialize(){
	mInput = Game::Instance()->GetInput();

	const int menuDefX = 400;
	const int menuDefY = 350;
	const int spaceY   = 50;
	const std::string tmpStr[] ={
		"はじめから　ゲームを開始します",
		"セーブした　つづきから　ゲームを再開します",
		"オプションを　変更します",
		"アプリケーションを　終了します"
	};
	for(int i=0;i<4;i++){
		std::shared_ptr<Menu> tmpMenu(new Menu(menuDefX, menuDefY+(spaceY*i), tmpStr[i]));
		mMenuMgr.Add(tmpMenu);
	}
	
}

void CMenuInTitle::Finalize(){
}

void CMenuInTitle::Draw(){
	// 背景
	DrawGraph(0,0,GhBackground,false);
	
	/*== メニューの表示 ================*/
	for(int i=0;i<mMenumgr.GetSelectMax();i++){
		int marginLeft = (i == mMenumgr.GetCurrent()) ? 20 : 0;	// 選択中のロゴをちょっと右にずらす

		DrawGraphF(mMenumgr.GetMenu(i)->GetTransform().GetX()+marginLeft, mMenumgr.GetMenu(i)->GetTransform().GetY(), GhMenu[i], true);		// ロゴの表示
	}
	DrawGraph(mMenumgr.GetCurrentMenu()->GetTransform().GetX()-16,mMenumgr.GetCurrentMenu()->GetTransform().GetY(),GhCursol,true);			// カーソル表示

	const int textX1 = 10;
	const int textY1 = Game::Instance()->WindowHeight-30;
	const int textX2 = Game::Instance()->WindowWidth -10;
	const int textY2 = textY1 + 15;
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, 120);																	// 透明度を設定
	DrawFillBox(textX1, textY1, textX2, textY2, GetColor(40,40,40));											// 塗りつぶし四角形
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0);
	DrawFormatString(textX1, textY1, GetColor(255,255,255),"- %s", mMenumgr.GetCurrentMenu()->GetText().c_str());		// テキストの表示

}

void CMenuInTitle::Update(){
	// ↑
	if(pInput->IsPushUp()>=1){
		if(pInput->IsPushUp()==1 || 
			(pInput->IsPushUp()>10 && pInput->IsPushUp()%5==0)){
			mAudio[1]->Play();
			mMenumgr.CurrentUp();
		}
	}
	// ↓
	if(pInput->IsPushDown()>=1){
		if(pInput->IsPushDown()==1 || (pInput->IsPushDown()>10 && pInput->IsPushDown()%5==0)){
			mAudio[1]->Play();
			mMenumgr.CurrentDown();
		}
	}
	// ショット/決定キー
	if(pInput->IsPushShot() == 1){
		mAudio[2]->Play();
		switch(mMenumgr.GetCurrent()){
			case 0:	// GAMESTART
				Player::Instance()->InstPlayer();
				mSceneChanger->ChangeScene(eScenePlay);
				break;
			case 1:	// COUNTINUE
				GoToLoad();
				break;
			case 2:	// OPTION
				flgEerror =true;
//				GoToOption();
				break;
			case 3:	// EXIT
				Game::Instance()->SetIEnd(true);
				break;
			default:
				break;
		}
	}
	// キャンセル
	if(pInput->IsPushBom() == 1){
		GoToTitle();
	}
}