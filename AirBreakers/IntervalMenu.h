#pragma once
#include "baseinterval.h"
#include "MenuMgr.h"

class Audio;
class IntervalMenu : public BaseInterval
{
private:
	enum{
		MaxAudio = 5
	};
	int GhFrame[2];
	int GhLogo[12];

	Audio* mAudio[MaxAudio];
	MenuMgr mMenuMgr;

public:
	IntervalMenu(IIntervalChanger* changer);
	~IntervalMenu(void);

	void Initialize()	override;
	void Finalize()		override;
	void Update()		override;
	void Draw()			override;

};

