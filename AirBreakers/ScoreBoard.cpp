#include <string>
#include "DxLib.h"

#include "ScoreBoard.h"
#include "UnitAdmin.h"
#include "PlayerUnit.h"

ScoreBoard::ScoreBoard(int* GhBoard, UnitAdmin* unitadmin):Object(unitadmin){
	mObjImg = GhBoard;
}

ScoreBoard::~ScoreBoard(){
}

void ScoreBoard::Initialize(){
	AnimeCount=0;
	int i=0;
	int tmpGh[10];

	LoadDivGraph("dat/image/system/font/num16_d.png",10,10,1,16,16,tmpGh);
	for(i=0;i<10;i++){
		GhFontNumber[i] = tmpGh[i];
	}
	LoadDivGraph("dat/image/system/font/num24_d.png",10,10,1,24,24,tmpGh);
	for(i=0;i<10;i++){
		GhFontNumber[i+10] = tmpGh[i];
	}
	LoadDivGraph("dat/image/system/font/num32_d.png",10,10,1,32,32,tmpGh);
	for(i=0;i<10;i++){
		GhFontNumber[i+20] = tmpGh[i];
	}

	LoadDivGraph("dat/image/system/font/char16_d.png", 28, 14, 2, 16, 16, GhFont);

	GhCircle=LoadGraph("dat/image/play/frame/bgIcon.png");
	GhFrame	=LoadGraph("dat/image/play/frame/sbswframe.png");
}

void ScoreBoard::Update(){
}

void ScoreBoard::DrawScore(BoardStatus* boStatus){
	unsigned i,j;
	std::string tmpStr[] = {"score","hiscore","destroy","money"};

	// 文字列score ~ destroyまで
	for(j=0;j<4;j++){
		for(i=0;i<tmpStr[j].length();i++){
			DrawRotaGraph( (i*12)+FeeldMaxX+40, (j*60)+30, 1, 0, GhFont[stoimg(tmpStr[j].at(i))],true );
		}
	}

	// 数字の描画
	int score	=boStatus->Score;
	int hiscore	=boStatus->HiScore;
	int destroy =boStatus->Destroy;
	int money	=boStatus->Money;
	for(i=0;i<9;i++){
		DrawRotaGraph((-13*i)+(FeeldMaxX+150),  45, 1, 0, GhFontNumber[score%10]	,true);
		DrawRotaGraph((-13*i)+(FeeldMaxX+150), 105, 1, 0, GhFontNumber[hiscore%10]	,true);
		DrawRotaGraph((-13*i)+(FeeldMaxX+150), 165, 1, 0, GhFontNumber[destroy%10]	,true);
		DrawRotaGraph((-13*i)+(FeeldMaxX+150), 225, 1, 0, GhFontNumber[money%10]	,true);
		score	/=10;
		hiscore	/=10;
		destroy	/=10;
		money	/=10;
	}
}

void ScoreBoard::DrawSubwepon(){
	unsigned i,j;
	std::string tmpStr = "slot";
	int selected	=pUnitAdmin->GetPlayerUnit()->GetSelectSW();
	int color		=GetColor(255,255,255);
	int defX		=FeeldMaxX+30;										// 描画の左上基準点 
	int defY		=400;

	DrawRotaGraph( defX, (selected*100)+defY, 1, 0, GhCircle, true);	// 選択サークル
	for(j=0;j<2;j++){
		DrawGraph( defX, (j*100)+defY, GhFrame, true);					// 周りの白枠

		for(i=0;i<tmpStr.length();i++){
			DrawRotaGraph( (i*12)+defX, (j*100)+defY, 1, 0, GhFont[stoimg(tmpStr.at(i))],true );	// Slotの文字列画像
		}
		DrawRotaGraph( (tmpStr.length())*12+defX, (j*100)+defY, 1,0,GhFontNumber[j+1], true);	// スロット番号画像
		DrawFormatString( defX+10, (j*100)+(defY+15), color,
			"%s",
			pUnitAdmin->GetPlayerUnit()->GetSubwepon()[j].GetStatus().Name.c_str());	// 装備しているサブウェポンの名前
		DrawFormatString( defX+10, (j*100)+(defY+30), color,
			"%d",
			pUnitAdmin->GetPlayerUnit()->GetSubwepon()[j].GetStatus().LoadNumber);		// 〃　　　　　　　　　　　　装填弾数
	}
}

void ScoreBoard::Draw(){
	DrawGraph(0,0,*mObjImg,true);
}

void ScoreBoard::Draw(BoardStatus* boStatus){
	DrawGraph(0,0,*mObjImg,true);	// フレーム表示
	DrawScore(boStatus);			// スコア周りの表示
	DrawSubwepon();					// サブウェポン
}
