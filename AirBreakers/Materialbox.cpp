#include "Materialbox.h"


Materialbox::Materialbox(void)
{
	for(int i=0;i<MAX_BOX;i++){
		lMaterial[i].mMaterial = new Material();
	}
}
Materialbox::~Materialbox(void)
{
	for(int i=0;i<MAX_BOX;i++){
		delete lMaterial[i].mMaterial;
	}
}

/*==  ================*/
void Materialbox::UseMaterial(){
	
}

int Materialbox::SearchMaterial(ListMaterial* mat){
	for(int i=0;i<MAX_BOX;i++){
		// ����i�����Ɏ����Ă����
		if(lMaterial[i].mMaterial->GetId() == mat->mMaterial->GetId()){
			return i;
		}
	}
	return -1;
}
int Materialbox::SearchMaterialEnpty(){
	for(int i=0;i<MAX_BOX;i++){
		if(lMaterial[i].mMaterial->GetId() == -1) return i;
	}
	return -1;
}
void Materialbox::InsertMaterial(ListMaterial listmat){
	int tmp = 0;

	if( (tmp = SearchMaterial(&listmat)) == -1 )	// �Ώۂ̃}�e���A���������Ă��Ȃ����
	{
		if(SearchMaterialEnpty() !=-1)	// ��̗v�f��T��
		{
			lMaterial[tmp]  = listmat;
		}
	} else {
		lMaterial[tmp].number+=listmat.number;	// ����Ό���ǉ�
	}
}
void Materialbox::InsertMaterial(Material mat){
	ListMaterial tmp;
	tmp.mMaterial = &mat;
	tmp.number = 1;

	InsertMaterial(tmp);
}

/*== Get/Set ================*/
Material* Materialbox::GetMaterial(int i){
	return lMaterial[i].mMaterial;
}


