#pragma once
#include "baseinterval.h"
#include "MenuMgr.h"

class IntervalStageSelect :	public BaseInterval{
private:
	unsigned mCount;
	bool flgNextStage;
	MenuMgr mMenuMgr;

public:
	IntervalStageSelect(IIntervalChanger* changer);
	~IntervalStageSelect(void);

	void Initialize()	override;
	void Finalize()		override;
	void Update()		override;
	void Draw()			override;
};

