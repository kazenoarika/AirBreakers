#include "DxLib.h"

#include "Menu.h"

// コンストラクタ
Menu::Menu():strText("DEFAULT TEXT"){
}
Menu::Menu(float x, float y, std::string text){
	mTransform.SetX(x);
	mTransform.SetY(y);
	strText = text;
}
Menu::~Menu(){
}

// 情報をセットする
// 文字列の左上X、左上Y、選択肢文字列、捕捉文字列
void Menu::SetMenu(int x, int y, std::string mTitle){
	mTransform.SetX((float)x);
	mTransform.SetY((float)y);
	strText = mTitle;
}

// 色指定描画
void Menu::Draw(int color=GetColor(255,255,255)){
	DrawFormatString(mTransform.GetX(),mTransform.GetY(),color,strText.c_str());
}

// テキストを返す
std::string Menu::GetTitle(){ return strText; }
