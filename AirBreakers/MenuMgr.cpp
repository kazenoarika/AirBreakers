#include "MenuMgr.h"


MenuMgr::MenuMgr(void){
}


MenuMgr::~MenuMgr(void){
}

void MenuMgr::Add(const std::shared_ptr<Menu> menu){
	mMenus.push_back(menu);
}

/*==  ================*/
//引数	：なし
//戻り値：なし
//動作	：一項目上へ
/*==  ================*/
void MenuMgr::CurrentUp(){ mCurrent = (mCurrent+(mSelectMax-1))%mSelectMax; }

/*==  ================*/
//引数	：なし
//戻り値：なし
//動作	：一項目下へ
/*==  ================*/
void MenuMgr::CurrentDown(){ mCurrent = (mCurrent+1)%mSelectMax; }

