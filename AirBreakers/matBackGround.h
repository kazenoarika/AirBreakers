#pragma once
class matBackGround
{
private:
	char name[256];
	char path[256];
	int sizeX;
	int sizeY;

public:
	matBackGround(void);
	~matBackGround(void);

	int GetImage();
};

