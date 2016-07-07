/*============================================================  ================*/
//	オブジェクトクラス
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

		DefaultHitArea	= 16,			// デフォルトの当たり判定(r)
		ExRate			= 1,			// 描画時の拡大率

	};

	bool			mObjFlag;			// 出現フラグ
	bool			mObjHostility;		// 敵対判定
	Transform		mObjTransform;		// ポジションとアングル
	VECTOR			mForce;				// 加速度
	VECTOR			mObjSize;			// サイズ
	float			mObjHitArea;		// 当たり判定(r)
	unsigned int	mObjCount;			// カウント
	float			mObjMoveSpeed;		// 移動速度
	int*			mObjImg;			// イメージ
	UnitAdmin*		pUnitAdmin;			// ユニットアドミン
	eObjectKind		mObjKind;			// オブジェクトの種類

	int stoimg(char str);				// 文字列から添字番号への返還

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
