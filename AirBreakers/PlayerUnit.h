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
		Input* pInput;			// input受け取り用

		int mRappid;			//連射速度
		bool flgShot;			// ショットフラグ
		bool flgSlow;			// シフト移動フラグ

		Subwepon mSubwepon[2];	// 装備しているサブウェポン情報
		int mSelectSW;			// 使用しているサブウェポン

		/*== グラフィック ================*/
		int GhPlayer[3];		// 自機画像
		int GhBooster;			// ブースター用
		int GhBullet;			// 自機の弾

		/*== シューター ================*/
		void (PlayerUnit::*Shooter[5])(Subwepon* subwepon);
		void ShooterTwinStrike(Subwepon* subwepon);
		void ShooterLanceShot(Subwepon* subwepon);
		void ShooterRazr(Subwepon* subwepon);
		void ShooterDrill(Subwepon* subwepon);
		void ShooterParticle(Subwepon* subwepon);

	public:
		PlayerUnit(UnitAdmin*);
		~PlayerUnit();

		/*== メイン ================*/
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

