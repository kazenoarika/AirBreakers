#include "DxLib.h"

#include "IntervalStageSelect.h"
#include "Game.h"

IntervalStageSelect::IntervalStageSelect(IIntervalChanger* changer):BaseInterval(changer){
	mCount		 = 0;
	flgNextStage = false;
}

IntervalStageSelect::~IntervalStageSelect(void)
{
}

void IntervalStageSelect::Initialize(){
	GhBackground = LoadGraph("dat/image/interval/background/stageselect.png");

	const int defX		= 0;
	const int defY		= 0;
	const int spaceY	= 40;
	std::string	tmp[] = {"ステージ 0","???","???","???","???","???", "メニューへ戻る"};
	for(int i=0;i<7;i++){
		mMenuMgr.GetMenu(i)->SetMenu(defX, (i*spaceY)+defY, tmp[i], "");
	}
	mMenuMgr.SetCurrent(0);
	mMenuMgr.SetSelectMax(7);

	flgNextStage = false;
}

void IntervalStageSelect::Finalize(){
	DeleteGraph(GhBackground);
}

void IntervalStageSelect::Draw(){
	const int tmpColor[] = { GetColor(0,0,0), GetColor(185,122,0), GetColor(255,255,255) };

	DrawGraph(0,0,GhBackground,true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 80);
	DrawBox(0, 0, 800, 600,	tmpColor[0], true );
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	int defX,defY;
	for(int i=0;i<7;i++){
		defX = mMenuMgr.GetMenu(i)->GetTransform().GetX();
		defY = mMenuMgr.GetMenu(i)->GetTransform().GetY();
		DrawBox(defX, defY, defX+ 200, defY+40,tmpColor[0], true);
		DrawBox(defX, defY, defX+ 200, defY+40,tmpColor[1], false);

		DrawFormatString(defX+10, defY+10, tmpColor[2], mMenuMgr.GetMenu(i)->GetTitle().c_str());
		if(i==mMenuMgr.GetCurrent()){
			DrawFormatString(defX+10, defY+10, tmpColor[1], mMenuMgr.GetMenu(i)->GetTitle().c_str());
		}
	}
}

void IntervalStageSelect::Update(){
	if(!flgNextStage){
		if(pInput->IsPushShot() == 1){
			switch(mMenuMgr.GetCurrent()){
				case 0:
					flgNextStage = true;
					break;
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
					mInterChanger->ChangeInterval(eInterMenu);
					break;
			}
		}
		if(pInput->IsPushBom() == 1){
			mInterChanger->ChangeInterval(eInterMenu);
		}
		if(pInput->IsPushUp() == 1){
			mMenuMgr.CurrentUp();
		}
		if(pInput->IsPushDown() == 1){
			mMenuMgr.CurrentDown();
		}
	}
	if(flgNextStage){
		if(mCount++>100){ mInterChanger->ChangeInterval(eInterGoToScenePlay); };
	}
}

