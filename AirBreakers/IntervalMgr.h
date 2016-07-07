#pragma once
#include <memory>
#include "IIntervalChanger.h"
#include "BaseInterval.h"

class IntervalMgr : public IIntervalChanger, Task
{
private:
	std::unique_ptr<BaseInterval> mInterval;
	eInter mNextInter;

	bool flgGoToScenePlay;


public:
	IntervalMgr(void);
	~IntervalMgr(void);

	void Initialize()	override;
	void Finalize()		override;
	void Update()		override;
	void Draw()			override;

	void ChangeInterval(eInter nextInter)override;
	bool GetGoToScenePlay(){ return flgGoToScenePlay; }
};

