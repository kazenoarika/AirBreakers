#pragma once
#include "basephase.h"
class PasResult :
	public BasePhase
{
private:
	int GhResult;		// リザルトボードGHオリジナル

public:
	PasResult(IPhaseChanger* changer);
	~PasResult(void);

	void Initialize()	override;
	void Finalize()		override;
	void Update()		override;
	void Draw()			override;
};

