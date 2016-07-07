#pragma once

#include "Enemy.h"
typedef struct{
	int SpawnTime;
	int SpawnX;
	int SpawnY;
	double SpawnSpd;
}OrderState;

class EnemyOrder{
private:
	bool flgSpawned;
	OrderState mOrdState;
	EnemyState mEneState;

public:
	~EnemyOrder(void);
	EnemyOrder(void);

	/*== Get/Set ================*/
	OrderState* GetOrderState() { return &mOrdState; }
	EnemyState* GetEnemyState() { return &mEneState; }
	void SetOrderState(OrderState* state){ mOrdState = *state; }
	void SetEnemyState(EnemyState* state){ mEneState = *state; }
};

