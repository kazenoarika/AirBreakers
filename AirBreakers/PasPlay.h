#pragma once
#include <memory>
#include "ScoreBoard.h"
#include "MenuMgr.h"

class UnitAdmin;
class BackGround;
class Input;
class EnemyWorker;
class Audio;

class PasPlay
{
private:
	enum{
		MaxSE = 4
	};
	std::unique_ptr<BackGround>	mBackground;	// 背景情報
//	std::unique_ptr<Stage>		mStage;			// ステージ情報
	std::shared_ptr<UnitAdmin>	mUnitAdmin;		// ユニットアドミン
	std::unique_ptr<ScoreBoard> mScoreBoard;	// スコアボード
	MenuMgr mMenuMgr;							// メニューマネージャー
	Audio* mSE[MaxSE];								// サウンドエフェクト

	Input* pInput;

	bool flgStart;								// スタート
	bool flgClear;								// クリアフラグ
	bool flgGameOver;							// ゲームオーバーフラグ
	bool flgResult;								// リザルト
	bool flgWarning;							// ワーニング
	bool flgBoss;								// ボス

	/*== グラフィック ================*/
	// 背景
	int GhBackground;							// 背景GHオリジナル
	int GhCloud;								// 雲

	int GhBurn00[16];							// 爆発1
	int GhBurn01[10];							// 爆発2
	int GhBurn02[8] ;							// 爆発3

	// ボード
	int GhBoard;								// スコアボードGHオリジナル
	int GhMenuBoard;							// メニューボード
	int GhResult;								// リザルトボードGHオリジナル
	int GhPlayerStatus;							// プレイヤーステータス
	
	// ロゴ
	int GhLogo;									// ロゴ
	int GhMenuLogo[4];							// メニュー用ロゴ

	// フォント
	int GhFontNumber[30];
	int GhFont[28];

	// ワーニング
	int GhWarning;								// ワーニング背景

	/*== 関数 ================*/
	void DrawPlayerStatusBar(int Alpha);
	bool FlagClear();
	bool FlagGameOver();
	BoardStatus* GetBoardStatus(BoardStatus *tmpBoard);
	void DrawDebug();

		/*== Start ================*/
		void GoToStart();
		void UpdateStart();
		void DrawStart();

		/*== Clear ================*/
		void GoToClear();
		void UpdateClear();
		void DrawClear();

		/*== GameOver ================*/
		void GoToGameOver();
		void UpdateGameOver();
		void DrawGameOver();

		/*== Result ================*/
		void GoToResult();
		void UpdateResult();
		void DrawResult();

		/*== Warrning ================*/
		void GoToWarning();
		void UpdateWarning();
		void DrawWarning();

public:
	PasPlay();
	~PasPlay(void);

	void Initialize();
	void Finalize();
	void Update();
	void Draw();
};

