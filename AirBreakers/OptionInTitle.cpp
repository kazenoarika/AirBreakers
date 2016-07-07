#include "OptionInTitle.h"


COptionInTitle::COptionInTitle(const std::shared_ptr<ITitleChanger> changer):BaseTitle(changer)
{
}


COptionInTitle::~COptionInTitle(void)
{
}

void COptionInTitle::Initialize(){
}

void COptionInTitle::Finalize(){
}

void COptionInTitle::Draw(){
	Player::Instance()->GetSubweponbox()->Draw();
}

void COptionInTitle::Update(){
	if(pInput->IsPushShot() == 1){
		GoToMenu();
	}}