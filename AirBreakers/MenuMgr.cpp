#include "MenuMgr.h"


MenuMgr::MenuMgr(void){
}


MenuMgr::~MenuMgr(void){
}

void MenuMgr::Add(const std::shared_ptr<Menu> menu){
	mMenus.push_back(menu);
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F�Ȃ�
//����	�F�ꍀ�ڏ��
/*==  ================*/
void MenuMgr::CurrentUp(){ mCurrent = (mCurrent+(mSelectMax-1))%mSelectMax; }

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F�Ȃ�
//����	�F�ꍀ�ډ���
/*==  ================*/
void MenuMgr::CurrentDown(){ mCurrent = (mCurrent+1)%mSelectMax; }

