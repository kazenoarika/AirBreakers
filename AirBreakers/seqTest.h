#pragma once

#include "BaseScene.h"

class Test : public BaseScene{
	private:
		int modelHandle;

	public:
		Test(ISceneChanger* changer);
		~Test();

		/*==  ================*/
		void Initialize() override;
		void Finalize() override;
		void Update() override;
		void Draw() override;
};

