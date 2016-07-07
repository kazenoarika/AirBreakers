#pragma once

//パッドキーの最大数
const int PAD_MAX = 16;

class Input{
	private:
		struct configpad{
			int left,right,up,down,shot,bom,slow,start,change;
		};

		unsigned int stateKey[256];
		//unsigned char KeySS[256][16];
		int statePad[PAD_MAX];
		int memInput[PAD_MAX];
	
		configpad Pad, Key;
		//configpad Config[16];

		void InputPadOrKey(int *p, int k);
		void MemoryInput();
		void GetHitPadStateAll();
		int GetHitKeyStateAll();
	public:
		Input();
		bool All();

		void SetPadInput(configpad NewPad);

		int IsPushLeft();
		int IsPushUp();
		int IsPushRight();
		int IsPushDown();
		int IsPushShot();
		int IsPushBom();
		int IsPushChange();
		int IsPushSlow();
		int IsPushStart();

		int CheckStateKey(unsigned char Handle);
		int CheckStatePad(unsigned int Handle);
};
