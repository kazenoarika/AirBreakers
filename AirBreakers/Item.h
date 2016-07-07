#pragma once
#include "object.h"

typedef enum{
	eItemKindScore,
	eItemKindPower,
	eItemKindEnegy,
	eItemKindMoney,
	eItemKindSubwepon
}eItemKind;

class Item : public Object{
private:
	eItemKind mKind;
	float mRank;
	float mVeiwAngle;

public:
	Item(UnitAdmin* unitadmin);
	~Item(void);
	void Update()	override;
	void Draw()		override;

	void Spawn(float x, float y, float angle, eItemKind kind);
	void Spawn(Transform* transform, eItemKind kind);
	void Hit();

	/*== Get/Set ================*/
	void SetImage(int* img){ mObjImg = img; }
	eItemKind GetKind(){ return mKind; }
	float GetRank(){ return mRank; }

};

