#include "BaseScene.h"

BaseScene::BaseScene(ISceneChanger* changer){
	stdCount = 0;

	mSceneChanger = changer;
}
BaseScene::~BaseScene(void){
}
void BaseScene::Finalize(){
}
void BaseScene::Draw(){
}

