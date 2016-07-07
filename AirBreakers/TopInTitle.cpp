#include "DxLib.h"
#include "Game.h"
#include "TopInTitle.h"


CTopInTitle::CTopInTitle(const std::shared_ptr<ITitleChanger> changer):BaseTitle(changer){
}


CTopInTitle::~CTopInTitle(void){
}

void CTopInTitle::Initialize(){

	mGraphics[0]->SetImages(LoadGraph("dat/image/title/cloud00.png")	);	// ”wŒi
	mGraphics[1]->SetImages(LoadGraph("dat/image/title/lo_ti000.png")	);	// ƒ^ƒCƒgƒ‹ƒƒS
	mGraphics[2]->SetImages(LoadGraph("dat/image/title/lo_ti001.png")	);	//
	mGraphics[3]->SetImages(LoadGraph("dat/image/title/lo_ti002.png")	);	//
	mGraphics[4]->SetImages(LoadGraph("dat/image/title/lo_ti003.png")	);	//

	mAudios[0]->SetAudio(LoadSoundMem("dat/audio/music/kouya.ogg"));
		mAudios[0]->SetLoopFlag(true);
	mAudios[1]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system14.ogg"));
		mAudios[1]->SetVolume(150);
	mAudios[2]->SetAudio(LoadSoundMem("dat/audio/se/se_maoudamashii_system16.ogg"));
		mAudios[2]->SetVolume(150);

	mInput = Game::Instance()->GetInput();
	printfDx("%d", mInput.use_count());
}

void CTopInTitle::Finalize(){
}

void CTopInTitle::Update(){
	if(mInput->IsPushShot()==1){
		mAudios[2]->Play();
		spTitleChanger->ChangeScene(eStateMenu);
	}
}

void CTopInTitle::Draw(){
	DrawGraph(0, 0, mGraphics[0]->GetGHandle(), true);	// ”wŒi

	/*== ƒ^ƒCƒgƒ‹ƒƒS ================*/
	const int logoBaseX = Game::Instance()->WindowWidth /2;
	const int logoBaseY = Game::Instance()->WindowHeight/2;

	DrawRotaGraph(logoBaseX, logoBaseY   , 1, 0, mGraphics[1]->GetGHandle(), true);
	DrawRotaGraph(logoBaseX, logoBaseY+50, 1, 0, mGraphics[2]->GetGHandle(), true);
	DrawRotaGraph(logoBaseX, logoBaseY-50, 1, 0, mGraphics[3]->GetGHandle(), true);

	if(mTimer % 100 > 30){
		DrawRotaGraph(logoBaseX, logoBaseY+200, 1, 0, mGraphics[4]->GetGHandle(), true);
	} 
}
