#pragma once
#include <memory>
#include "BaseScene.h"
#include "Background.h"
#include "MenuMgr.h"

class IStage;
class ScoreBoard;

class Play : public BaseScene{
	private:
		/*== ステージ情報 ================*/
		std::shared_ptr<IStage> Stage;
		std::shared_ptr<BackGround> m_CBackground;
		MenuMgr mMenumgr;						// セレクトメニュー管理
		
		bool flgMenu;							// ポーズメニューフラグ
		int cutMenuAnime;						// アニメーション用変数
		int cutMenuAnimeMax;

		bool flgMenuYesNo;						// YesNoメニューフラグ
		bool flgYesNo;
		int cutMYNAnime;						// アニメーション用変数
		int cutMYNAnimeMax;

		
		/*== グラフィック ================*/
		// ボード
		int GhMenuBoard;						// メニューボード
		int GhMenuHover[4];

		int GhMYNBoard;							// Yes/Noボード
		int GhMYNSelecter[4];					// Yes/Noセレクター
		// フォント
		int chasetGH[28];						// キャラセットGHオリジナル

		/*== Menu ================*/
		void GoToMenu();
		void UpdataMenu();
		void DrawMenu();

		void GoToYesNoMenu();
		void UpdateYesNoMenu();
		void DrawMenuYesNo();

	public:
		Play(ISceneChanger* changer);
		~Play();

		/*==  ================*/
		void Initialize() override;
		void Finalize() override;
		void Draw() override;
		void Update() override;

};
