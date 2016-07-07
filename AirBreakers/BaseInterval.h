#pragma once
#include "IIntervalChanger.h"
#include "Task.h"

class Input;
class BaseInterval : public Task
{
protected:
	Input* pInput;
	signed mCount;
	int GhBackground;
	IIntervalChanger* mInterChanger;

public:
	BaseInterval(IIntervalChanger* changer);
	~BaseInterval(void);

	virtual void Initialize()	override{}
	virtual void Finalize()		override;
	virtual void Update()		override{}
	virtual void Draw()			override;

};

