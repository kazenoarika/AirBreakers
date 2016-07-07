#pragma once
#include "Record.h"

class IStage
{
private:
	Record mRecord;

public:
	IStage(void);
	~IStage(void);

	virtual void Initialize(){}
	virtual void Finalize(){}
	virtual void Update()	=0;
	virtual void Draw()		=0;

	virtual bool IsCleared()=0;
	virtual bool IsFailured()=0;

	Record* GetRecord() { return &mRecord; }
};

