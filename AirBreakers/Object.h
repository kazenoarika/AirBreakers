/*============================================================  ================*/
//	�I�u�W�F�N�g�N���X
/*============================================================  ================*/
#pragma once
#include "Transform.h"

typedef enum{
	eObjKindPlayer,
	eObjKindFellow,
	eObjKindEnemy,
	eObjKindBoss,
	eObjKindBullet,
	eObjKindObject,

	eObjKindNone
}eObjectKind;

class UnitAdmin;
class Object{
protected:
	enum{
		FeeldZeroX	= 16,
		FeeldZeroY	= 16,
		FeeldMaxX	= 600,
		FeeldMaxY	= 568,

		DefaultHitArea	= 16,			// �f�t�H���g�̓����蔻��(r)
		ExRate			= 1,			// �`�掞�̊g�嗦

	};

	bool			mObjFlag;			// �o���t���O
	bool			mObjHostility;		// �G�Δ���
	Transform		mObjTransform;		// �|�W�V�����ƃA���O��
	VECTOR			mForce;				// �����x
	VECTOR			mObjSize;			// �T�C�Y
	float			mObjHitArea;		// �����蔻��(r)
	unsigned int	mObjCount;			// �J�E���g
	float			mObjMoveSpeed;		// �ړ����x
	int*			mObjImg;			// �C���[�W
	UnitAdmin*		pUnitAdmin;			// ���j�b�g�A�h�~��
	eObjectKind		mObjKind;			// �I�u�W�F�N�g�̎��

	int stoimg(char str);				// �����񂩂�Y���ԍ��ւ̕Ԋ�

	int DrawRotaGraphFdF( float xd, float yd, float ExRate, float Angle, int GrHandle, int TransFlag, int TurnFlag  );
	int DrawRotaGraphFdF( const Transform* transfrom, float ExRate, float angle, int grHandle, int TransFlag, int TurnFlag);
	int DrawRotaGraphFdF();
	int DrawRotaGraphGameObjects();

public:
	Object(UnitAdmin* unitadmin);
	Object();
	~Object();
	virtual void Initialize(){}
	virtual void Finalize(){}
	virtual void Update()=0;
	virtual void Draw();

	/*== Get/Set ================*/
	bool	GetFlag()		const	{ return mObjFlag;		}
	Transform	GetTransform() const{ return mObjTransform; }
	VECTOR	GetForce()		const	{ return mForce;		}
	float	GetHitArea()	const	{ return mObjHitArea;	}
	bool	GetHostility()	const	{ return mObjHostility; }
	long	GetCount()		const	{ return mObjCount;		}
	float	GetMoveSpeed()	const	{ return mObjMoveSpeed; }

	void	AddForce(VECTOR* force);
	void	SetTransform(Transform* transform)		{ mObjTransform =*transform;	}
	void	SetForce(VECTOR* force)					{ mForce		=*force;		}
	void	SetMoveSpeed(float speed)				{ mObjMoveSpeed = speed;		}
	void	Spawn(Transform* transform)				{ mObjTransform =*transform;	}

};
