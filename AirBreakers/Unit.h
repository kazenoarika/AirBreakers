#pragma once

#include "Object.h"
class Bullet;

class Unit : public Object{
	protected:
		int mHP;			// 耐久値
		bool flgDestroyed;	// 破壊状態
		int cntDestroyed;	// アニメーション用
		int mUniInvisible;	// 無敵時間

	public:
		/*==  ================*/
		Unit(UnitAdmin* unitadmin);
		virtual ~Unit();

		/*==  ================*/
		virtual void Spawn(float x,float y,float angle)=0;
		void DrawmHP();
		void Hit(Bullet* objBullet);
		void Hit(Object* objObbject);

		/*== メイン ================*/
		virtual void Update() override =0;
		virtual void Draw() override;

		/*== Get/Set ================*/
		int GetHP();
		int GetInvisible(){ return mUniInvisible; }
};
