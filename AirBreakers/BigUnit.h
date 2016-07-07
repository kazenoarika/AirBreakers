#pragma once

#include "Enemy.h"

class BigUnit : public Enemy{
	private:
		int mPhase;

		/*== �O���t�B�b�N ================*/
		int GhUnit;

		void ShooterAllrange();

	public:
		BigUnit(UnitAdmin* unitadmin);
		~BigUnit();
		void Initialize()	override;
		void Finalize()		override;
		void Update()		override;
		void Draw()			override;

		void Move();
		void Spawn();
};
