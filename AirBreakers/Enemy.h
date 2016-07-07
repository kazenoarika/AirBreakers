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

		/*== �ړ��֐��Q ================*/
		void (Enemy::*Mover[15])();
		void MoverDown();			// �Ђ�����ɉ���
		void MoverUp();				// �Ђ�����ɏ��
		void MoverLeft();			// �Ђ�����ɍ���
		void MoverRight();			// �Ђ�����ɉE��

		void MoverLeftDown();		// ������
		void MoverRightDown();		// �E����
		
		void MoverDownToLeft();		// �������Ď~�܂��č���
		void MoverDownToUp();		// �������Ď~�܂��ď��
		void MoverDownToRight();	// �������Ď~�܂��ĉE��
		void MoverDownToDown();		// �������Ď~�܂��ĉ���

		void MoverDownToUpLeft();	// �������Ď~�܂��č���
		void MoverDownToUpRight();	// �������Ď~�܂��ĉE��
		void MoverDownToLeftDown();	// �������Ď~�܂��č���
		void MoverDownToRightDown();// �������Ď~�܂��ĉE��
		
		void MoverCos();			// ���E�ɗh��Ȃ���~��Ă���


		/*== �ˌ��֐��Q ================*/
		void (Enemy::*Shooter[1])();// 
		void ShooterTargetShoot();	// �Ώۂ̃^�[�Q�b�g��_���ł�

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

