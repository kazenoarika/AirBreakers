#pragma once
#include <string>
#include "Transform.h"


class Menu {
	private:
		Transform mTransform;	// •\¦À•W
		std::string strText;	// •\¦•¶š—ñ1

	public:
		Menu();
		Menu(float x, float y, std::string text);
		~Menu();
		void Draw(int color);

		/*== Get/Set ================*/
		void SetMenu(int X, int Y, std::string text);

		float GetX(){ return mTransform.GetX(); }
		float GetY(){ return mTransform.GetY(); }
		float GetZ(){ return mTransform.GetZ(); }

		std::string GetText();
		std::string GetTitle();
};