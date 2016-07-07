#pragma once
#include "baseinterval.h"

class Audio;
class IntervalSave : public BaseInterval{
private:
	enum{MaxAudio=5};
	Audio* mAudio[MaxAudio];

public:
	IntervalSave(IIntervalChanger* changer);
	~IntervalSave(void);

	void Initialize()	override;
	void Finalize()		override;
	void Update()		override;
	void Draw()			override;
};

