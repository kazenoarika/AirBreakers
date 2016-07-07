#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "PasPlay.h"

#include "UnitAdmin.h"
#include "Input.h"
#include "Stage.h"

/*== Result ================*/
void PasPlay::GoToResult(){
// 「リザルト表示」
	int i=0;
	int tmpGh[10];

	GhResult	= LoadGraph("dat/image/play/frame/resultboard.png");

	LoadDivGraph("dat/image/system/font/num16.png",10,10,1,16,16,tmpGh);
	for(i=0;i<10;i++){
		GhFontNumber[i] = tmpGh[i];
	}
	LoadDivGraph("dat/image/system/font/num24.png",10,10,1,24,24,tmpGh);
	for(i=0;i<10;i++){
		GhFontNumber[i+10] = tmpGh[i];
	}
	LoadDivGraph("dat/image/system/font/num32.png",10,10,1,32,32,tmpGh);
	for(i=0;i<10;i++){
		GhFontNumber[i+20] = tmpGh[i];
	}

	LoadDivGraph("dat/image/system/font/char16.png", 28, 14, 2, 16, 16, GhFont);

	/*==  ================*/
	const int defX		= 55;
	const int defY		= 315;
	const int spaceX	= 400;
	const int spaceY	= 20;
	std::string tmpStr;
	for(i=0;i<10;i++){
		tmpStr = mUnitAdmin->GetSubweponBox()->GetSubwepon(i)->GetStatus().Name;
		mMenuMgr.GetMenu(i)->SetMenu( ((i%2)*spaceX)+defX, ((i/2)*spaceY)+defY, tmpStr, "");
	}
	mMenuMgr.SetCurrent(0);
	mMenuMgr.SetSelectMax(10);

	stdCount	= 0;
	flgResult	= true;
}
void PasPlay::UpdateResult(){
// リザルト画面更新
	if(stdCount==40){
		
	}
	if(stdCount>100){
		if(pInput->IsPushShot() == 1){
			mPhaseChanger->ChangePhase(ePhaseClear);
		}
		if(pInput->IsPushLeft() == 1){
			mMenuMgr.CurrentUp();
			while(1){
				if(mUnitAdmin->GetSubweponBox()->GetSubwepon(mMenuMgr.GetCurrent())->GetStatus().Id == -1){
					mMenuMgr.CurrentUp();
					if(mMenuMgr.GetCurrent() == 0){break;}
					continue;
				}else{
					break;
				}
			}
		}
		if(pInput->IsPushRight() == 1){
			mMenuMgr.CurrentDown();
			while(1){
				if(mUnitAdmin->GetSubweponBox()->GetSubwepon(mMenuMgr.GetCurrent())->GetStatus().Id == -1){
					mMenuMgr.CurrentDown();
					if(mMenuMgr.GetCurrent() == 0){break;}
					continue;
				}else{
					break;
				}
			}
		}
		if(pInput->IsPushUp() == 1){
			mMenuMgr.CurrentUp();
			mMenuMgr.CurrentUp();
			while(1){
				if(mUnitAdmin->GetSubweponBox()->GetSubwepon(mMenuMgr.GetCurrent())->GetStatus().Id == -1){
					mMenuMgr.CurrentUp();
					if(mMenuMgr.GetCurrent() == 0){break;}
					continue;
				}else{
					break;
				}
			}
		}
		if(pInput->IsPushDown() == 1){
			mMenuMgr.CurrentDown();
			mMenuMgr.CurrentDown();
			while(1){
				if(mUnitAdmin->GetSubweponBox()->GetSubwepon(mMenuMgr.GetCurrent())->GetStatus().Id == -1){
					mMenuMgr.CurrentDown();
					if(mMenuMgr.GetCurrent() == 0){break;}
					continue;
				}else{
					break;
				}
			}
		}
	}
	stdCount++;
}
void PasPlay::DrawResult(){
// リザルト画面描画
	int i;
	DrawGraph(0,0,GhResult,true);

	/*== 数字の描画 ================*/
	int score	=mUnitAdmin->GetScore();
	int hiscore	=mStage->GetStatus().HiScore;
	int money	=mUnitAdmin->GetMoney();
	for(i=0;i<9;i++){
		DrawRotaGraph((-26*i)+500,  140, 1, 0, GhFontNumber[(score%10)+20]	,true);
		DrawRotaGraph((-26*i)+500,  220, 1, 0, GhFontNumber[(money%10)+20]	,true);
		score/=10;
		money/=10;
	}

	/*== サブウェポン ================*/
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * sin(stdCount%180 * M_PI/180));
	DrawBox(
		mMenuMgr.GetCurrentMenu()->GetTransform().GetX()		,mMenuMgr.GetCurrentMenu()->GetTransform().GetY()	,
		mMenuMgr.GetCurrentMenu()->GetTransform().GetX()+200	,mMenuMgr.GetCurrentMenu()->GetTransform().GetY()+20	,
		GetColor(80,255,200),true
	);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	const int color = GetColor(255,255,255);
	for(i=0;i<10;i++){
		DrawFormatString(mMenuMgr.GetMenu(i)->GetTransform().GetX(), mMenuMgr.GetMenu(i)->GetTransform().GetY(), color, mMenuMgr.GetMenu(i)->GetTitle().c_str());
	}
}
