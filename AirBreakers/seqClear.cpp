#include "seqClear.h"
#include "Game.h"

Clear::Clear(ISceneChanger* changer):BaseScene(changer){
}
void Clear::Initialize(){
	pInput = Game::Instance()->GetInput();
}
void Clear::Finalize(){
}

void Clear::Update(){
	switch(state){
		case STAFFROLL:
			break;
		case ENDCARD:
			break;
	}
}
void Clear::Draw(){
	switch(state){
		case STAFFROLL:
			break;
		case ENDCARD:
			break;
	}
}

