#pragma once

#include "Object.h"

class Cloud;

class BackGround : public Object{
	private:
		enum{MaxCloud = 12};

		bool flgScroll;
		int mImgWidth;
		int mImgHeight;

		Cloud* cloud[MaxCloud];
		
	public:
		BackGround(int*, int*);
		~BackGround();
		void Initialize()	override;
		void Draw()			override;
		void Update()		override;
};

