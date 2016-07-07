#pragma once

#include "Object.h"
class Bullet;

class Unit : public Object{
	protected:
		int mHP;			// �ϋv�l
		bool flgDestroyed;	// �j����
		int cntDestroyed;	// �A�j���[�V�����p
		int mUniInvisible;	// ���G����

	public:
		/*==  ================*/
		Unit(UnitAdmin* unitadmin);
		virtual ~Unit();

		/*==  ================*/
		virtual void Spawn(float x,float y,float angle)=0;
		void DrawmHP();
		void Hit(Bullet* objBullet);
		void Hit(Object* objObbject);

		/*== ���C�� ================*/
		virtual void Update() override =0;
		virtual void Draw() override;

		/*== Get/Set ================*/
		int GetHP();
		int GetInvisible(){ return mUniInvisible; }
};
