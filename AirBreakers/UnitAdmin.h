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

		int			mScore;					// �X�R�A
		int			mDestroy;				// �j��
		int			mCount;					// �J�E���^
		int			mMoney;					// �l�����z
		bool		flgBossReady;			// �{�X���o������������

		int			mLastSpawnOrder;		// �G�l�~�[�I�[�_�[�p
		Subweponbox	mSWBox;					// �T�u�E�F�|���擾�p
		
		/*== �O���t�B�b�N�X ================*/
		int			GhBullets[12];			// �e
		int			GhItems[5];				// �h���b�v�A�C�e��
		int			GhEnemy;				// �G

		/*== �I�[�f�B�I ================*/
		Audio*		mBGM;					// BGM
		Audio*		mSE[MaxSE];				// SE

		/*== �Q�[���I�u�W�F�N�g ================*/
		Item*		mItem[MaxObject];		// �A�C�e��
		EnemyOrder	mEnemyOrder[200];		// �G�@
		PlayerUnit* mJiki;					// ���@
		BigUnit*	mBigUnit;				// �{�X
		Enemy*		mEnemy[MaxUnit-2];		// �G�@
		Bullet*		mBullet[MaxBullet];		// �e

		Unit*		mUnit[MaxUnit];			// �Ǘ��p�z��

		/*== �X�|�[���֐� ================*/
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

		/*== �T�[�`�֐� ================*/
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

