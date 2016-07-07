#pragma once
#include <memory>
#include "BaseScene.h"
#include "Background.h"
#include "MenuMgr.h"

class IStage;
class ScoreBoard;

class Play : public BaseScene{
	private:
		/*== �X�e�[�W��� ================*/
		std::shared_ptr<IStage> Stage;
		std::shared_ptr<BackGround> m_CBackground;
		MenuMgr mMenumgr;						// �Z���N�g���j���[�Ǘ�
		
		bool flgMenu;							// �|�[�Y���j���[�t���O
		int cutMenuAnime;						// �A�j���[�V�����p�ϐ�
		int cutMenuAnimeMax;

		bool flgMenuYesNo;						// YesNo���j���[�t���O
		bool flgYesNo;
		int cutMYNAnime;						// �A�j���[�V�����p�ϐ�
		int cutMYNAnimeMax;

		
		/*== �O���t�B�b�N ================*/
		// �{�[�h
		int GhMenuBoard;						// ���j���[�{�[�h
		int GhMenuHover[4];

		int GhMYNBoard;							// Yes/No�{�[�h
		int GhMYNSelecter[4];					// Yes/No�Z���N�^�[
		// �t�H���g
		int chasetGH[28];						// �L�����Z�b�gGH�I���W�i��

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
