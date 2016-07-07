#pragma once
#include "IStage.h"

class BaseStage : public IStage{

public:
	BaseStage(void);
	~BaseStage(void);

	virtual void Initialize()	override{}
	virtual void Finalize()		override{}
	virtual void Update()		override;
	virtual void Draw()			override;

	virtual bool IsCleared()	override;
	virtual bool IsFailured()	override;
};

