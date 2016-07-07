#include "DxLib.h"
#include "seqTest.h"

Test::Test(ISceneChanger* changer):BaseScene(changer){
	// 3Dモデルの読み込み
	if((modelHandle = MV1LoadModel("../ModelData/Sphere.x")) == -1)
	printfDx("エラー");
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
