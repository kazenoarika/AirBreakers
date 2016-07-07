#pragma once
#include "baseinterval.h"

class Audio;
class IntervalMaterial : public BaseInterval{
private:
	enum{MaxAudio=5};
	Audio* mAudio[MaxAudio];

public:
	IntervalMaterial(IIntervalChanger* changer);
	~IntervalMaterial(void);

	void Initialize()	override;
	void Finalize()		override;
	void Update()		override;
	void Draw()			override;

};

