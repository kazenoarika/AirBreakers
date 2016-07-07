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
	std::unique_ptr<BackGround>	mBackground;	// �w�i���
//	std::unique_ptr<Stage>		mStage;			// �X�e�[�W���
	std::shared_ptr<UnitAdmin>	mUnitAdmin;		// ���j�b�g�A�h�~��
	std::unique_ptr<ScoreBoard> mScoreBoard;	// �X�R�A�{�[�h
	MenuMgr mMenuMgr;							// ���j���[�}�l�[�W���[
	Audio* mSE[MaxSE];								// �T�E���h�G�t�F�N�g

	Input* pInput;

	bool flgStart;								// �X�^�[�g
	bool flgClear;								// �N���A�t���O
	bool flgGameOver;							// �Q�[���I�[�o�[�t���O
	bool flgResult;								// ���U���g
	bool flgWarning;							// ���[�j���O
	bool flgBoss;								// �{�X

	/*== �O���t�B�b�N ================*/
	// �w�i
	int GhBackground;							// �w�iGH�I���W�i��
	int GhCloud;								// �_

	int GhBurn00[16];							// ����1
	int GhBurn01[10];							// ����2
	int GhBurn02[8] ;							// ����3

	// �{�[�h
	int GhBoard;								// �X�R�A�{�[�hGH�I���W�i��
	int GhMenuBoard;							// ���j���[�{�[�h
	int GhResult;								// ���U���g�{�[�hGH�I���W�i��
	int GhPlayerStatus;							// �v���C���[�X�e�[�^�X
	
	// ���S
	int GhLogo;									// ���S
	int GhMenuLogo[4];							// ���j���[�p���S

	// �t�H���g
	int GhFontNumber[30];
	int GhFont[28];

	// ���[�j���O
	int GhWarning;								// ���[�j���O�w�i

	/*== �֐� ================*/
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

