#pragma once
#include "DxLib.h"

class Transform
{
private:
	VECTOR	mPosition;
	float	mAngle;

public:
	Transform(void);
	~Transform(void);
	void Move(float speedX, float speedY);

	VECTOR	GetPosition()	const{ return mPosition;	}
	float	GetX()			const{ return mPosition.x;	}
	void	SetX(float x)		 { mPosition.x = x;		}
	void	AddX(float tx)		 { mPosition.x += tx;	}

	float	GetY()			const{ return mPosition.y;	}
	void	SetY(float y)		 { mPosition.y = y;		}
	void	AddY(float ty)		 { mPosition.y += ty;	}

	float	GetZ()			const{ return mPosition.z;	}
	void	SetZ(float z)		 { mPosition.z = z;		}
	void	AddZ(float tz)		 { mPosition.z += tz;	}

	float	GetAngle()		const{ return mAngle;		}
	void	SetAngle(float angle){ mAngle = angle;		}
	void	AddAngle(float tAngle){ mAngle += tAngle;	}
};

