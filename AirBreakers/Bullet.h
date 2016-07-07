#pragma once
#include "Object.h"

class UnitAdmin;

typedef enum{
	eKindHoming,
	eKindDrill,

	eKindNomal
}eBulletKind;

struct BulletStatus{
	eBulletKind Kind;	// �^�C�v
	int Penetoration;	// �ђʗ�
	int Damage;			// �З�
	int Speed;			// �e��
	double HitArea;		// �����蔻��
	bool AfterImage;	// �c��
	bool Homing;		// �z�[�~���O

	BulletStatus(){
		Kind = eKindNomal;
		Penetoration = 0;
		Damage = 0;
		Speed = 0;
		HitArea = 0.0;
		AfterImage = false;
		Homing = false;
	}
};

class Bullet : public Object{
	public:
		enum{
			ImageCount = 12,
			
			DefSpeed = 20

		};
	private:
		BulletStatus mStatus;
		int* GhBullets[ImageCount];

		struct Point{
			double X;
			double Y;
		}lastPoint[5];

	public:
		Bullet(UnitAdmin* unitadmin);
		~Bullet();

		/*==  ================*/
		void Hit();
		void Shot(float x,float y,float angle);
		void Shot(float x,float y,float angle, bool hostility, BulletStatus* state);
		void Shot(Transform* transform, BulletStatus* state, bool hostility);


		/*== ���C�� ================*/
		void Initialize()	override;
		void Finalize()		override;
		void Draw()			override;
		void Update()		override;

		/*== Get/Set ================*/
		BulletStatus GetStatus();
		void SetStatus(BulletStatus* BulStatus);
		void SetImage(int* ghBullet);

};

