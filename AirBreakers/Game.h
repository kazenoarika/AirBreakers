// ゲーム統一処理：シングルトン
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
	/* 必須 */
	private:
		const std::string tApplicationName;	// アプリケーション名
		const std::string tVersion;			// バージョン
		
		bool flgEnd;	// 終了フラグ
		std::shared_ptr<Input> mInput;	// 入力

		SceneMgr mSceneManager;	// シーン管理クラス
		std::unique_ptr<FPS> fps;	// fps管理クラス
		//std::unique_ptr<Resouce> resouce;	// 

		// 容易にインスタンスを作られないようにプライベート化
		Game();
		Game(const Game& game):tApplicationName("Air Breakers!!"),tVersion("0.00a"){};
		Game& operator=(const Game& game){}
		~Game();


	public:
		// インスタンスにアクセス
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

