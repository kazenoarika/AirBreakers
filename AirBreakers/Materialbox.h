#pragma once

#include "Material.h"

class Materialbox
{
private:
	enum{MAX_BOX = 10};

	struct ListMaterial{
		Material* mMaterial; // マテリアル
		int number;	// 個数
	}lMaterial[MAX_BOX];

public:
	Materialbox(void);
	~Materialbox(void);

	/*==  ================*/
	void UseMaterial();

	int SearchMaterial(ListMaterial* mat);
	int SearchMaterialEnpty();
	void InsertMaterial(ListMaterial matlist);
	void InsertMaterial(Material mat);

	/*== Get/Set ================*/
	Material* GetMaterial(int i);
};

