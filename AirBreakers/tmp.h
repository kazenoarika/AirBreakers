#pragma once

#include "define.h"
#include "Sequence.h"
#include "Menu.h"

class Interval : public Sequence{
	private:
		enum{
			READY,
			TOP,
			MATERIAL,
			EQUIPMENT,
			SAVE,
		}state;

		// Input* input;

	public:
		// Interval(Input*);

		void Draw();

		Sequence* Update();

		void SetTop();
};