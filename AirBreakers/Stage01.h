#pragma once
#include "basestage.h"
class Stage01 :
	public BaseStage
{
private:

public:
	Stage01(void);
	~Stage01(void);

	virtual void Initialize()	override;
	virtual void Finalize()		override;
	virtual void Update()		override;
	virtual void Draw()			override;

	virtual bool IsCleared()	override;
	virtual bool IsFailured()	override;
};

