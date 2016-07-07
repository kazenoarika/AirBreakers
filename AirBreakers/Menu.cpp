#include "DxLib.h"

#include "Menu.h"

// �R���X�g���N�^
Menu::Menu():strText("DEFAULT TEXT"){
}
Menu::Menu(float x, float y, std::string text){
	mTransform.SetX(x);
	mTransform.SetY(y);
	strText = text;
}
Menu::~Menu(){
}

// �����Z�b�g����
// ������̍���X�A����Y�A�I����������A�ߑ�������
void Menu::SetMenu(int x, int y, std::string mTitle){
	mTransform.SetX((float)x);
	mTransform.SetY((float)y);
	strText = mTitle;
}

// �F�w��`��
void Menu::Draw(int color=GetColor(255,255,255)){
	DrawFormatString(mTransform.GetX(),mTransform.GetY(),color,strText.c_str());
}

// �e�L�X�g��Ԃ�
std::string Menu::GetTitle(){ return strText; }
