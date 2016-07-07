#define _USE_MATH_DEFINES
#include <cmath>

#include "DxLib.h"
#include "Object.h"

Object::Object(UnitAdmin* unitadmin){
	pUnitAdmin = unitadmin;

	mObjFlag		= false;
	mObjHostility	= false;
	mForce.x		= 0.0f;
	mForce.y		= 0.0f;
	mForce.z		= 0.0f;
	mObjMoveSpeed	= 0.0f;
	mObjHitArea		= 0;
	mObjCount		= 0;
}
Object::Object(){
	mObjFlag		= false;
	mObjHostility	= false;
	mForce.x		= 0.0f;
	mForce.y		= 0.0f;
	mForce.z		= 0.0f;
	mObjMoveSpeed	= 0.0f;
	mObjHitArea		= 0;
	mObjCount		= 0;
	pUnitAdmin		= 0;
	mObjKind		= eObjKindNone;
}
Object::~Object()
{
}


void Object::AddForce(VECTOR* force){
	mForce.x += force->x;
	mForce.y += force->y;
	mForce.z += force->z;
}

void Object::Draw(){
	if(mObjFlag){
		DrawRotaGraphF(mObjTransform.GetX(), mObjTransform.GetY(),1.0,mObjTransform.GetAngle()+M_PI/2,(*mObjImg),1,0);
	}
}

int Object::DrawRotaGraphGameObjects(){
	const float defX = mObjTransform.GetX() + FeeldZeroX;
	const float defY = mObjTransform.GetY() + FeeldZeroY;
	const float defAngle = mObjTransform.GetAngle();

	return DrawRotaGraphF(defX, defY, ExRate, defAngle, (*mObjImg), true);
}

/*==  ================*/
//引数	：なし
//戻り値：なし
//動作	：フレーム分のズレを考慮した描画。だいたい使うのはこれ
/*==  ================*/
int Object::DrawRotaGraphFdF( float xd, float yd, float ExRate, float Angle, int GrHandle, int TransFlag, int TurnFlag  ) {
	return DrawRotaGraphF((float)xd+FeeldZeroX,(float)yd+FeeldZeroY,ExRate,Angle,GrHandle,TransFlag,TurnFlag);
}

int Object::DrawRotaGraphFdF( const Transform* transfrom, float ExRate, float angle, int grHandle, int TransFlag, int TurnFlag){
	return DrawRotaGraphF(
		(float)transfrom->GetX()+FeeldZeroX,
		(float)transfrom->GetY()+FeeldZeroY,
		ExRate, angle, grHandle, TransFlag, TurnFlag);
}

/*==  ================*/
//引数	：なし
//戻り値：なし
//動作	：フレーム分のズレを考慮した描画。だいたい使うのはこれ
/*==  ================*/
int Object::DrawRotaGraphFdF() {

	return DrawRotaGraphF((float)FeeldZeroX+mObjTransform.GetX(),(float)FeeldZeroY+mObjTransform.GetY(),ExRate,0,(*mObjImg),true,false);
}

/*==  ================*/
//引数	：なし
//戻り値：なし
//動作	：文字列を数字の添字にして返す
/*==  ================*/
int Object::stoimg(char str){
	char ALPHA[] = {"abcdefghijklmnopqrstuvwxyz"};

	int i=0;
	if(str==' ') return 0;
	for(i=0;i<26;i++){ if(str==ALPHA[i]) return i; }
	return 0;		
}
