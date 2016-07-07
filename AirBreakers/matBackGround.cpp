#include "matBackGround.h"

#include "DxLib.h"

matBackGround::matBackGround(void)
{
}


matBackGround::~matBackGround(void)
{
}


int matBackGround::GetImage(){
	return LoadGraph(this->path);
}