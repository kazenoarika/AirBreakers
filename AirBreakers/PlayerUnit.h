#pragma once

#include "Unit.h"
#include "SubWepon.h"

class View;
class UnitAdmin;
class Input;
class Item;

class PlayerUnit : public Unit{
	private:
		/*==  ================*/
		Input* pInput;			// input�󂯎��p

		int mRappid;			//�A�ˑ��x
		bool flgShot;			// �V���b�g�t���O
		bool flgSlow;			// �V�t�g�ړ��t���O

		Subwepon mSubwepon[2];	// �������Ă���T�u�E�F�|�����
		int mSelectSW;			// �g�p���Ă���T�u�E�F�|��

		/*== �O���t�B�b�N ================*/
		int GhPlayer[3];		// ���@�摜
		int GhBooster;			// �u�[�X�^�[�p
		int GhBullet;			// ���@�̒e

		/*== �V���[�^�[ ================*/
		void (PlayerUnit::*Shooter[5])(Subwepon* subwepon);
		void ShooterTwinStrike(Subwepon* subwepon);
		void ShooterLanceShot(Subwepon* subwepon);
		void ShooterRazr(Subwepon* subwepon);
		void ShooterDrill(Subwepon* subwepon);
		void ShooterParticle(Subwepon* subwepon);

	public:
		PlayerUnit(UnitAdmin*);
		~PlayerUnit();

		/*== ���C�� ================*/
		void Update() override;
		void Draw() override;
		void Move();
		void Initialize();
		void Finalize();

		/*==  ================*/
		void Spawn(
			float m_x =((FeeldMaxX - FeeldZeroX) / 2.0),
			float m_y =((FeeldMaxY - FeeldZeroY) * (3.0/4.0)),
			float m_angle= -(3.141592/2.0)
		)override;
		void Spawn(Transform* transform);

		void ToggleSW();

		void TurnShotFlg();

		void TurnSlowFlg();

		void ShotSubWepon();

		void Shot();

		void UpdataInit();

		void InputAccept();

		/*== Get/Set ================*/
		bool GetSlow(){ return flgSlow; }
		bool GetShot(){ return flgShot; }
		int GetSelectSW(){ return mSelectSW; }
		Subwepon* GetSubwepon(){ return mSubwepon; }
};

