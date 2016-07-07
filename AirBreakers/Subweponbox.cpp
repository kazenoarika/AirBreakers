#include <string>

#include "DxLib.h"
#include "Subweponbox.h"

Subweponbox::Subweponbox(void)
{
	for(int i = 0;i<MaxBox;i++){
		mSubwepon[i] = *(new Subwepon());
	}

	mEqipment[0] = 0;
	mEqipment[1] = 0;
}
Subweponbox::~Subweponbox(void)
{
/*
	for(int i=0;i<MAX_BOX;i++){
		delete &mSubwepon[i];
	}
*/
}

/*==  ================*/
void Subweponbox::Initialize(){
}
int Subweponbox::SearchEnpty(){
	for(int i=0;i<MaxBox;i++){
		if(mSubwepon[i].GetStatus().Id == -1){
			return i;
		}
	}
	return -1;
}
int Subweponbox::Insert(Subwepon sw){
	int tmp = SearchEnpty();

	if(tmp != -1){
		mSubwepon[tmp] = sw;
		return 0;
	}

	return -1;
}
void Subweponbox::GetSubweponForCSV(int id){
	int n, num, i, fp;
	char fname[256];
	int input[64];
	char inputc[64];

	
	sprintf_s(fname, "dat/Database/dbSW.csv");
	fp = FileRead_open(fname);	// �t�@�C���ǂݍ���
	if(fp == NULL){
		printfDx("read error\n");
		return;
	}
	for(i=0;i<2;i++)	// �ŏ���2�s��ǂݔ�΂�
		while(FileRead_getc(fp)!='\n');

	n=0, num=0;

	SubweponStatus tmpStatus;

	while(1){
		for(i=0;i<64;i++){
			inputc[i]=input[i]=FileRead_getc(fp);//1�����擾����
			if(inputc[i]=='/'){//�X���b�V���������
				while(FileRead_getc(fp)!='\n');//���s�܂Ń��[�v
				i=-1;//�J�E���^���ŏ��ɖ߂���
				continue;
			}
			if(input[i]==',' || input[i]=='\n'){//�J���}�����s�Ȃ�
				inputc[i]='\0';//�����܂ł𕶎���Ƃ�
				break;
			}
			if(input[i]==EOF){//�t�@�C���̏I���Ȃ�
				goto EXFILE;//�I��
			}
		}
		switch(num){
			case  0: tmpStatus.Name			=inputc;	  break;
			case  1: tmpStatus.Kind			=atoi(inputc);break;
			case  2: tmpStatus.Damage		=atoi(inputc);break;
			case  3: tmpStatus.HitArea		=atoi(inputc);break;
			case  4: tmpStatus.Speed		=atoi(inputc);break;
			case  5: tmpStatus.Rappid		=atoi(inputc);break;
			case  6: tmpStatus.Penetoration	=atoi(inputc);break;
			case  7: tmpStatus.LoadNumber	=atoi(inputc);break;
			case  8: tmpStatus.Price		=atoi(inputc);break;
		}
		num++;
		if(num==9){
			tmpStatus.Id = n;
			if(n==id){
				Subwepon tmp;
				tmp.SetSubwepon(tmpStatus);
				Insert(tmp);
				break;
			}
			num=0;
			n++;
		}
	}
	EXFILE:
		FileRead_close(fp);}
void Subweponbox::Draw(){
	int height = 16;

	int color = GetColor(255,255,255);
	DrawFormatString(0, 0,color,"Equipments:[slot1:[%d], slot2:[%d]]",mEqipment[0],mEqipment[1]);
	DrawFormatString(0,height,color,"Have Subwepons");
	for(int i=0;i<MaxBox;i++){
		DrawFormatString(0,(i*height)+30,color,
			"SW[%d]:[Name:%s, Damage:%d]",
			i, mSubwepon[i].GetStatus().Name.c_str(), mSubwepon[i].GetStatus().Damage
		);
	}

}

/*== Get/Set ================*/
Subwepon* Subweponbox::GetSubwepon(int num){
	if(num < 0 && MaxBox <= num){
		num = 0;
	}
	return &(this->mSubwepon[num]);
}
void Subweponbox::SetSubwepon(Subwepon* sw){
	int i;
	for(int i=0;i<MaxBox;i++){
		if(mSubwepon[i].GetStatus().Id == -1) break;
	}

	if(i != MaxBox){
		mSubwepon[i] = *sw;
	}
}
void Subweponbox::SetEquipSW(int slotNum, int boxnum){
	mEqipment[slotNum] = boxnum;
}

