#pragma once
#include "BaseScene.h"
#include "TitleMgr.h"

class Title : public BaseScene{
	private:
		CTitleMgr mTitleMgr;

		// エラー表示用
		bool flgEerror;
		int  couError;
		void UpdataError();
		void DrawErrarEffect();

	public:
		Title(ISceneChanger* changer);
		~Title();

		void Initialize() override;
		void Finalize() override;
		void Update() override;
		void Draw() override;
};

