#include "DxLib.h"
#include "Images.h"

#include "Transform.h"


CImages::CImages(void)
{
}


CImages::~CImages(void)
{
	DeleteGraph(m_GraphicHandle);
}


int CImages::SetImages(std::string const filename){
	DeleteGraph(m_GraphicHandle);
	m_GraphicHandle = LoadGraph(filename.c_str());
}

void CImages::SetImages(int const gh){
	DeleteGraph(m_GraphicHandle);
	m_GraphicHandle = gh;
}

