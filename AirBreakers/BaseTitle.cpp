#include "BaseTitle.h"


BaseTitle::BaseTitle(const std::shared_ptr<ITitleChanger> changer){
	spTitleChanger.reset(changer.get());
}


BaseTitle::~BaseTitle(void)
{
}

void BaseTitle::Finalize(){
}

void BaseTitle::Draw(){
}