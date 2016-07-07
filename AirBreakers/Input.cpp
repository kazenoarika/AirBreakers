#include "DxLib.h"
#include "Input.h"

/*==  ================*/
//引数
//	configpad NewPad：新しいキー割り振りの数値群
//戻り値：なし
//動作	：キーの割り振り
/*==  ================*/
void Input::SetPadInput(configpad NewPad){
	this->Pad = NewPad;
}

/*==  ================*/
//引数	：なし
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::IsPushLeft(){
	return statePad[Pad.left];
}

/*==  ================*/
//引数	：なし
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::IsPushUp(){
	return statePad[Pad.up];
}

/*==  ================*/
//引数	：なし
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::IsPushRight(){
	return statePad[Pad.right];
}

/*==  ================*/
//引数	：なし
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::IsPushDown(){
	return statePad[Pad.down];
}

/*==  ================*/
//引数	：なし
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::IsPushShot(){
	return statePad[Pad.shot];
}

/*==  ================*/
//引数	：なし
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::IsPushBom(){
	return statePad[Pad.bom];
}

/*==  ================*/
//引数	：なし
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::IsPushChange(){
	return statePad[Pad.change];
}

/*==  ================*/
//引数	：なし
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::IsPushSlow(){
	return statePad[Pad.slow];
}

/*==  ================*/
//引数	：なし
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::IsPushStart(){
	return statePad[Pad.start];
}

/*==  ================*/
//引数	：キーの番号
//戻り値：入力されている時間
//動作	：引数のキーの押されている時間を返す
/*==  ================*/
int Input::CheckStateKey(unsigned char Handle){
	return stateKey[Handle];
}

/*==  ================*/
//引数	：なし
//戻り値：うまくいった？
//動作	：外部呼び出し用統括関数
/*==  ================*/
bool Input::All(){
	this->GetHitKeyStateAll();
	this->GetHitPadStateAll();
	return 0;
}

/*==  ================*/
//引数	：ボタンの番号
//戻り値：入力されている時間
//動作	：引数のボタンの押されている時間を返す
/*==  ================*/
int Input::CheckStatePad(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){
		return statePad[Handle];
	} else {
		printfDx("CheckStatePadに渡した値が不正です\n");
		return -1;
	}
}

/*==  ================*/
//引数	：なし
//戻り値：0->成功
//動作	：入力されているキーの判定
/*==  ================*/
int Input::GetHitKeyStateAll(){
	char GetHitKeyStateAll_Key[256];
	DxLib::GetHitKeyStateAll( GetHitKeyStateAll_Key );
	for(int i=0; i<256; i++){
		if(GetHitKeyStateAll_Key[i]==1) stateKey[i]++;
		else							stateKey[i]=0;
	}
	return 0;
}

/*==  ================*/
//引数	：なし
//戻り値：なし
//動作	：キーとパッドの押されている時間の長い方をパッドの変数に入れる
/*==  ================*/
void Input::GetHitPadStateAll(){

	int i, PadInput, mul =1;
	PadInput = DxLib::GetJoypadInputState( DX_INPUT_PAD1 );
	for(i=0;i<PAD_MAX;i++){
		if(PadInput & (1<<i))	statePad[i]++;
		else					statePad[i]=0;
	}
	InputPadOrKey(&statePad[Pad.left]	,CheckStateKey(KEY_INPUT_LEFT	));
	InputPadOrKey(&statePad[Pad.up]		,CheckStateKey(KEY_INPUT_UP		));
	InputPadOrKey(&statePad[Pad.right]	,CheckStateKey(KEY_INPUT_RIGHT	));
	InputPadOrKey(&statePad[Pad.down]	,CheckStateKey(KEY_INPUT_DOWN	));
	InputPadOrKey(&statePad[Pad.shot]	,CheckStateKey(KEY_INPUT_Z		));
	InputPadOrKey(&statePad[Pad.bom]	,CheckStateKey(KEY_INPUT_X		));
	InputPadOrKey(&statePad[Pad.change]	,CheckStateKey(KEY_INPUT_C		));
	InputPadOrKey(&statePad[Pad.slow]	,CheckStateKey(KEY_INPUT_LSHIFT	));
	InputPadOrKey(&statePad[Pad.start]	,CheckStateKey(KEY_INPUT_SPACE	));
}


/*==  ================*/
//引数	
//	int *p：比較した後統合される変数
//	int  k：*pと比較する数値
//戻り値：なし
//動作	：*pとkを比較して、大きい方を*pに代入する
/*==  ================*/
void Input::InputPadOrKey(int *p, int k){
	*p = *p>k ? *p : k;
}

/*==  ================*/
//引数	：なし
//戻り値：なし
//動作	：コンストラクタ
/*==  ================*/
Input::Input(){
/*== 初期キーコンフィグ ================*/
	Pad.down = 0;
	Pad.left = 1;
	Pad.right = 2;
	Pad.up = 3;
	Pad.bom = 6;
	Pad.shot = 7;
	Pad.slow = 11;
	Pad.start = 13;
	Pad.change = 4;	
}

