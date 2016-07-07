#define _USE_MATH_DEFINES
#include <cmath>
#include "Transform.h"


Transform::Transform(void){
	mPosition.x = 0.0f;
	mPosition.y = 0.0f;
	mPosition.z	= 0.0f;
	mAngle		= 0.0f;
}


Transform::~Transform(void)
{
}

void Transform::Move(float speedX, float speedY){
	mPosition.x = cos(mAngle)*speedX;
	mPosition.y = sin(mAngle)*speedY;
}