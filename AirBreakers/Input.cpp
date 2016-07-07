#include "DxLib.h"
#include "Input.h"

/*==  ================*/
//����
//	configpad NewPad�F�V�����L�[����U��̐��l�Q
//�߂�l�F�Ȃ�
//����	�F�L�[�̊���U��
/*==  ================*/
void Input::SetPadInput(configpad NewPad){
	this->Pad = NewPad;
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::IsPushLeft(){
	return statePad[Pad.left];
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::IsPushUp(){
	return statePad[Pad.up];
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::IsPushRight(){
	return statePad[Pad.right];
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::IsPushDown(){
	return statePad[Pad.down];
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::IsPushShot(){
	return statePad[Pad.shot];
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::IsPushBom(){
	return statePad[Pad.bom];
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::IsPushChange(){
	return statePad[Pad.change];
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::IsPushSlow(){
	return statePad[Pad.slow];
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::IsPushStart(){
	return statePad[Pad.start];
}

/*==  ================*/
//����	�F�L�[�̔ԍ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃L�[�̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::CheckStateKey(unsigned char Handle){
	return stateKey[Handle];
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F���܂��������H
//����	�F�O���Ăяo���p�����֐�
/*==  ================*/
bool Input::All(){
	this->GetHitKeyStateAll();
	this->GetHitPadStateAll();
	return 0;
}

/*==  ================*/
//����	�F�{�^���̔ԍ�
//�߂�l�F���͂���Ă��鎞��
//����	�F�����̃{�^���̉�����Ă��鎞�Ԃ�Ԃ�
/*==  ================*/
int Input::CheckStatePad(unsigned int Handle){
	if(0<=Handle && Handle<PAD_MAX){
		return statePad[Handle];
	} else {
		printfDx("CheckStatePad�ɓn�����l���s���ł�\n");
		return -1;
	}
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F0->����
//����	�F���͂���Ă���L�[�̔���
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
//����	�F�Ȃ�
//�߂�l�F�Ȃ�
//����	�F�L�[�ƃp�b�h�̉�����Ă��鎞�Ԃ̒��������p�b�h�̕ϐ��ɓ����
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
//����	
//	int *p�F��r�����㓝�������ϐ�
//	int  k�F*p�Ɣ�r���鐔�l
//�߂�l�F�Ȃ�
//����	�F*p��k���r���āA�傫������*p�ɑ������
/*==  ================*/
void Input::InputPadOrKey(int *p, int k){
	*p = *p>k ? *p : k;
}

/*==  ================*/
//����	�F�Ȃ�
//�߂�l�F�Ȃ�
//����	�F�R���X�g���N�^
/*==  ================*/
Input::Input(){
/*== �����L�[�R���t�B�O ================*/
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

