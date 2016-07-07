#include "Game.h"
#include "LoadInTitle.h"
#include "Input.h"

CLoadInTitle::CLoadInTitle(const std::shared_ptr<ITitleChanger> changer):BaseTitle(changer){
}


CLoadInTitle::~CLoadInTitle(void)
{
}

void CLoadInTitle::Initialize(){
	GhBackground = LoadGraph("dat/image/title/load00.jpg");

/*	std::ifstream ifs("");
	char str[256];
	if(ifs.fail()){
		// ファイル読み込み失敗
	}
	while(ifs.getline(str, 256)){
		
	}
*/

	/*== メニュー周り設定 ================*/
	int tmpMenuMax = Game::Instance()->MaxSavedata;

	mMenumgr.SetCurrent(0);
	mMenumgr.SetSelectMax(tmpMenuMax);

	std::string strTmp[] = {"Savedata1","Savedata2","Savedata3"};
	const int menuDX = 100;
	const int menuDY = 100;
	const int betweenDY = 169;
	for(int i=0;i<tmpMenuMax;i++){
		mMenumgr.GetMenu(i)->SetMenu(menuDX, menuDY+(i*betweenDY), strTmp[i], "");
	}

	state = LOAD;}

void CLoadInTitle::Finalize(){
}

void CLoadInTitle::Draw(){
	DrawGraph(0,0,GhBackground,false);
	

	/*==  ================*/
	const int defX = mMenumgr.GetCurrentMenu()->GetTransform().GetX();
	const int defY = mMenumgr.GetCurrentMenu()->GetTransform().GetY();
	const int width = 685;
	const int height = 150;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 80);	// 透明度を引数から設定
	DrawFillBox(
		defX,
		defY,
		defX + width,
		defY + height,
		GetColor(40,40,40)
	);

	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 );}

void CLoadInTitle::Update(){
	if(pInput->IsPushUp()==1){
		mMenumgr.CurrentUp();
	}
	if(pInput->IsPushDown()==1){
		mMenumgr.CurrentDown();
	}
	if(pInput->IsPushBom()==1){
		GoToMenu();
	}}