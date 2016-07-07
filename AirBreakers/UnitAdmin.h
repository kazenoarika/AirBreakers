#pragma once
#include "EnemyOrder.h"
#include "Materialbox.h"
#include "Subweponbox.h"

class Stage;
class Play;
class Unit;
class Object;
class PlayerUnit;
class Enemy;
class Item;
class BigUnit;
class Audio;

class UnitAdmin{
	private:
		enum{
			MaxUnit		= 64,
			MaxBullet	= 256,
			MaxObject	= 128,
			MaxSE		= 7
		};

		int			mScore;					// スコア
		int			mDestroy;				// 破壊数
		int			mCount;					// カウンタ
		int			mMoney;					// 獲得金額
		bool		flgBossReady;			// ボスが出現したいって

		int			mLastSpawnOrder;		// エネミーオーダー用
		Subweponbox	mSWBox;					// サブウェポン取得用
		
		/*== グラフィックス ================*/
		int			GhBullets[12];			// 弾
		int			GhItems[5];				// ドロップアイテム
		int			GhEnemy;				// 敵

		/*== オーディオ ================*/
		Audio*		mBGM;					// BGM
		Audio*		mSE[MaxSE];				// SE

		/*== ゲームオブジェクト ================*/
		Item*		mItem[MaxObject];		// アイテム
		EnemyOrder	mEnemyOrder[200];		// 敵機
		PlayerUnit* mJiki;					// 自機
		BigUnit*	mBigUnit;				// ボス
		Enemy*		mEnemy[MaxUnit-2];		// 敵機
		Bullet*		mBullet[MaxBullet];		// 弾

		Unit*		mUnit[MaxUnit];			// 管理用配列

		/*== スポーン関数 ================*/
		void SpawnRandomEnemy();
		void SpawnItem(Object* object,int itemNumber);

		void LoadEnemyOrdertoCSV(int stagenum);
		void HitItem(Item* item);

	public:
		UnitAdmin();
		~UnitAdmin();
		void Initialize();
		void Finalize();
		void Draw();
		void Update();

		/*== サーチ関数 ================*/
		int SearchEmptyBullet();
		int SearchEmptyUnit();
		int SearchEmptyEnemy();
		int SearchEmptyItem();

		/*==  ================*/
		void GameInit();
		void DrawmHP();
		void Judge();
		Unit* Nearest(Object*);
		bool Collider(Object* origin, Object* target);
		void DrawDebug();
		void SpawnSearchOrder();
		void SpawnBoss();


		/*== Get/Set ================*/
		int			GetScore()		{ return mScore;		}
		int			GetDestroy()	{ return mDestroy;		}
		int			GetMoney()		{ return mMoney;		}
		PlayerUnit*	GetPlayerUnit()	{ return mJiki;			}
		Unit*		GetUnit(int i)	{ return mUnit[i];		}
		Bullet*		GetBullet(int i){ return mBullet[i];	}
		bool		GetBossReadyFlag(){ return flgBossReady;}
		bool		GetBossFlg();
		Subweponbox* GetSubweponBox(){ return &mSWBox;		}
		Audio*		GetSE(int i)	{ return mSE[i];		}

};

