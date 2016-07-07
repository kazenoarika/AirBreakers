#include "Material.h"


Material::Material(void)
{
	mId = -1;
	mName = "";
}
Material::~Material(void)
{
}

/*==  ================*/


/*== Get/Set ================*/
int Material::GetId(){
	return mId;
}
char* Material::GetName(){
	return mName;
}