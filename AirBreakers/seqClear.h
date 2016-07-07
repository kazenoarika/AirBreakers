#pragma once

#include "BaseScene.h"

class Clear : public BaseScene{
	private:
		enum{
			STAFFROLL,
			ENDCARD,
		}state;

	public:
		Clear(ISceneChanger* changer);

		void Initialize() override;
		void Finalize() override;
		void Draw() override;
		void Update() override;

		void SetTop();

};
