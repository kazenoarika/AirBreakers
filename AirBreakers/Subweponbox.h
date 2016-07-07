#pragma once
#include "SubWepon.h"

class Subweponbox
{
public:
	enum{
		MaxBox = 10
	};
	
private:
	Subwepon mSubwepon[MaxBox];
	int mEqipment[2];

public:
	Subweponbox(void);
	~Subweponbox(void);

	/*==  ================*/
	void Initialize();
	int SearchEnpty();
	int Insert(Subwepon sw);
	void GetSubweponForCSV(int id);
	void Draw();

	/*== Get/Set ================*/
	Subwepon* GetSubwepon(int num);
	void SetSubwepon(Subwepon* sw);
	int GetEquipSW(int slotnum){ return mEqipment[slotnum]; }

	void SetEquipSW(int slotnum, int boxNum);
};



