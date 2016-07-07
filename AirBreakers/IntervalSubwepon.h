#pragma once
#include "baseinterval.h"
#include "MenuMgr.h"

class Audio;
class IntervalSubwepon : public BaseInterval{
private:
	enum{
		MaxAudio = 5
	};
	MenuMgr mMenuMgr;

	Audio* mAudio[MaxAudio];

public:
	IntervalSubwepon(IIntervalChanger* changer);
	~IntervalSubwepon(void);

	void Initialize()	override;
	void Finalize()		override;
	void Update()		override;
	void Draw()			override;

};

