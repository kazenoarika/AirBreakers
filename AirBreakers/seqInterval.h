#pragma once

#include "BaseScene.h"
#include "IntervalMgr.h"

class Interval : public BaseScene{
	private:
		IntervalMgr mIntervalMgr;

	public:
		Interval(ISceneChanger* changer);
		~Interval();

		void Initialize()	override;
		void Finalize()		override;
		void Draw()			override;
		void Update()		override;

};