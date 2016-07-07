#pragma once

#include "Object.h"

class Effect : public Object{
	private:
		int color;
		int kind;
		int effect;
		int bright;
		int speed;
	public:
		Effect(UnitAdmin* unitadmin);
		~Effect();

		void Update();
};
