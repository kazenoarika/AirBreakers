#pragma once

#include "Object.h"

class Cloud : public Object{
	private:
		int scrollSpeed;

	public:
		Cloud(int, int*);
		~Cloud();
		void Spawn(float x, float y);

		void Draw() override;
		void Update() override;
};
