#pragma once
#include <string>

class Transform;
class CImages{
private:
	int m_GraphicHandle;

public:
	CImages(void);
	~CImages(void);

	void SetImages(int const gh);

	int GetGHandle() const { return m_GraphicHandle; }
};

