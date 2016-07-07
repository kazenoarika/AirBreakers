#pragma once
#include <vector>
#include <memory>
#include "Menu.h"

class MenuMgr
{
private:
	enum{
		MenuMax = 10,
	};

	Menu mMenu[MenuMax];
	std::vector<std::shared_ptr<Menu>> mMenus;

	int mCurrent;
	int mSelectMax;
public:
	MenuMgr(void);
	~MenuMgr(void);

	void CurrentUp();
	void CurrentDown();

	void Add(const std::shared_ptr<Menu> menu);

	/*== Get/Set ================*/
	Menu* GetMenu(int i){ return &mMenu[i]; }
	Menu* GetCurrentMenu(){ return &mMenu[mCurrent]; }

	int GetCurrent(){ return mCurrent; }
	void SetCurrent(int current){ this->mCurrent = current; }

	int GetSelectMax(){ return mSelectMax; }
	void SetSelectMax(int selectmax){ this->mSelectMax = selectmax; }
};

