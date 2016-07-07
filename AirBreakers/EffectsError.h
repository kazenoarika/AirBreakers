#pragma once

#include "Images.h"
class CEffectsError{
private:
	enum{ImageMax=3};
	bool bRunning;
	int mCount;
	CImages mImages[ImageMax];

public:
	CEffectsError(void);
	~CEffectsError(void);

	void Initialize();
	void Run();
	void Draw();
	void Update();
	bool IsRunning(){ return bRunning; }
};

