// �Q�[�����ꏈ���F�V���O���g��
#pragma once

#include <memory>
#include <string>
#include "Input.h"

#include "SceneMgr.h"
#include "fps.h"
#include "Player.h"

class Resouce;
class Subwepon;


class Game{
	/* �K�{ */
	private:
		const std::string tApplicationName;	// �A�v���P�[�V������
		const std::string tVersion;			// �o�[�W����
		
		bool flgEnd;	// �I���t���O
		std::shared_ptr<Input> mInput;	// ����

		SceneMgr mSceneManager;	// �V�[���Ǘ��N���X
		std::unique_ptr<FPS> fps;	// fps�Ǘ��N���X
		//std::unique_ptr<Resouce> resouce;	// 

		// �e�ՂɃC���X�^���X������Ȃ��悤�Ƀv���C�x�[�g��
		Game();
		Game(const Game& game):tApplicationName("Air Breakers!!"),tVersion("0.00a"){};
		Game& operator=(const Game& game){}
		~Game();


	public:
		// �C���X�^���X�ɃA�N�Z�X
		static Game* Instance(){
			static Game inst;
			return &inst;
		}

		enum{
			WindowWidth = 800,
			WindowHeight = 600,
			MaxSavedata = 3,
		};

		bool Update();
		void Initialize();
		void Finalize();
	
		/*== Get/Set ================*/
		void SetIEnd(bool endFlag){flgEnd = endFlag;}
		bool GetIEnd(){return flgEnd;}
		std::shared_ptr<Input> GetInput() const{ return mInput; }
		SceneMgr* GetSceneMgr(){ return &mSceneManager; }
};

