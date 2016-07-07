#include "DxLib.h"
#include "PasResult.h"


PasResult::PasResult(IPhaseChanger* changer):BasePhase(changer)
{
}


PasResult::~PasResult(void)
{
}

void PasResult::Initialize(){
	GhResult = LoadGraph("../image/play/frame/resultboard.png");		//	���U���g�{�[�h
}

void PasResult::Finalize(){
}

void PasResult::Draw(){
	DrawGraph(0,0,GhResult,true);
}

void PasResult::Update(){
}