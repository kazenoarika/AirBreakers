#pragma once
class Material
{
private:
	int mId;
	char* mName;

public:
	Material(void);
	~Material(void);

	/*==  ================*/

	/*== Get/Set ================*/
	int GetId();

	char* GetName();
};

