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

		/*== ˆÚ“®ŠÖ”ŒQ ================*/
		void (Enemy::*Mover[15])();
		void MoverDown();			// ‚Ğ‚½‚·‚ç‚É‰º‚Ö
		void MoverUp();				// ‚Ğ‚½‚·‚ç‚Éã‚Ö
		void MoverLeft();			// ‚Ğ‚½‚·‚ç‚É¶‚Ö
		void MoverRight();			// ‚Ğ‚½‚·‚ç‚É‰E‚Ö

		void MoverLeftDown();		// ¶‰º‚Ö
		void MoverRightDown();		// ‰E‰º‚Ö
		
		void MoverDownToLeft();		// ‰º‚ª‚Á‚Ä~‚Ü‚Á‚Ä¶‚Ö
		void MoverDownToUp();		// ‰º‚ª‚Á‚Ä~‚Ü‚Á‚Äã‚Ö
		void MoverDownToRight();	// ‰º‚ª‚Á‚Ä~‚Ü‚Á‚Ä‰E‚Ö
		void MoverDownToDown();		// ‰º‚ª‚Á‚Ä~‚Ü‚Á‚Ä‰º‚Ö

		void MoverDownToUpLeft();	// ‰º‚ª‚Á‚Ä~‚Ü‚Á‚Ä¶ã
		void MoverDownToUpRight();	// ‰º‚ª‚Á‚Ä~‚Ü‚Á‚Ä‰Eã
		void MoverDownToLeftDown();	// ‰º‚ª‚Á‚Ä~‚Ü‚Á‚Ä¶‰º
		void MoverDownToRightDown();// ‰º‚ª‚Á‚Ä~‚Ü‚Á‚Ä‰E‰º
		
		void MoverCos();			// ¶‰E‚É—h‚ê‚È‚ª‚ç~‚è‚Ä‚­‚é


		/*== ËŒ‚ŠÖ”ŒQ ================*/
		void (Enemy::*Shooter[1])();// 
		void ShooterTargetShoot();	// ‘ÎÛ‚Ìƒ^[ƒQƒbƒg‚ğ‘_‚¢‘Å‚Â

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

