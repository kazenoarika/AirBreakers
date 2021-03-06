#pragma once

#include "Unit.h"

class View;
class UnitAdmin;
class EnemyOrder;

typedef enum{
	mMoverLeft,
	mMoverUp,
	mMoverRight,
	mMoverDown,

	mMoverLeftDown,
	mMoverRightDown,

	mMoverDownToLeft,
	mMoverDownToUp,
	mMoverDownToRight,
	mMoverDownToDown,

	mMoverDownToUpLeft,
	mMoverDownToUpRight,
	mMoverDownToLeftDown,
	mMoverDownToRightDown,

	eMoverNone
}eMover;
typedef struct{
	int HP;
	int	MoveKind;
	int Kind;
	int AtackTime;
	int AtackCount;
	int AtackBulletColor;
	int WaitTime;
}EnemyState;

class Enemy : public Unit{
	protected:
		EnemyState mState;
		eMover mNextMover;

		/*== 移動関数群 ================*/
		void (Enemy::*Mover[15])();
		void MoverDown();			// ひたすらに下へ
		void MoverUp();				// ひたすらに上へ
		void MoverLeft();			// ひたすらに左へ
		void MoverRight();			// ひたすらに右へ

		void MoverLeftDown();		// 左下へ
		void MoverRightDown();		// 右下へ
		
		void MoverDownToLeft();		// 下がって止まって左へ
		void MoverDownToUp();		// 下がって止まって上へ
		void MoverDownToRight();	// 下がって止まって右へ
		void MoverDownToDown();		// 下がって止まって下へ

		void MoverDownToUpLeft();	// 下がって止まって左上
		void MoverDownToUpRight();	// 下がって止まって右上
		void MoverDownToLeftDown();	// 下がって止まって左下
		void MoverDownToRightDown();// 下がって止まって右下
		
		void MoverCos();			// 左右に揺れながら降りてくる


		/*== 射撃関数群 ================*/
		void (Enemy::*Shooter[1])();// 
		void ShooterTargetShoot();	// 対象のターゲットを狙い打つ

		/*==  ================*/
		void Move();
		void Shot();

	public:
		Enemy(UnitAdmin*);
		~Enemy();

		/*==  ================*/
		void SetImage(int* img);
		void Spawn(float x,float y,float angle) override;
		void Spawn(EnemyOrder* order);

		/*==  ================*/
		void Initialize()	override;
		void Finalize()		override;
		void Update()		override;
		void Draw()			override;
		
};

