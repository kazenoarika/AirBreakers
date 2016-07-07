#include "BaseInterval.h"

#include "Game.h"

BaseInterval::BaseInterval(IIntervalChanger* changer){
	mInterChanger = changer;
	mCount = 0;
	pInput = Game::Instance()->GetInput();
}


BaseInterval::~BaseInterval(void){
}

void BaseInterval::Finalize(){
}

void BaseInterval::Draw(){
}

