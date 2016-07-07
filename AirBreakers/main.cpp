#include "DxLib.h"
#include "Game.h"

int LoopProcess(){
	if(ScreenFlip()!=0) return false;
	if(ProcessMessage()!=0) return false;
	if(ClearDrawScreen()!=0) return false;
	return true;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	if(	SetGraphMode(
			Game::Instance()->WindowWidth,
			Game::Instance()->WindowHeight,
			16
		) != DX_CHANGESCREEN_OK) return -1;	// ウィンドウサイズを変更する
	if( ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK ) return -1; //ウィンドウ化と初期化処理
//	if( SetWindowIconID( MAINICON )) return -1;
	if( DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;		//描画先を裏画面に設定
	SetDrawMode( DX_DRAWMODE_BILINEAR );

	Game::Instance()->Initialize();

	while(LoopProcess()){
		if(!Game::Instance()->Update())
			break;
	}

	Game::Instance()->Finalize();
	DxLib_End();
	return 0;
}