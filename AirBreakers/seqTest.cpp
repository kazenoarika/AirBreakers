#include "DxLib.h"
#include "seqTest.h"

Test::Test(ISceneChanger* changer):BaseScene(changer){
	// 3Dƒ‚ƒfƒ‹‚Ì“Ç‚İ‚İ
	if((modelHandle = MV1LoadModel("../ModelData/Sphere.x")) == -1)
	printfDx("ƒGƒ‰[");
}

Test::~Test(){
}

void Test::Initialize(){
}

void Test::Finalize(){
}

void Test::Draw(){
}

void Test::Update(){
	MV1DrawModel(modelHandle);
}
