#include <cstdio>

#include "DxLib.h"
#include "Game.h"
#include "Input.h"


Game::Game():tApplicationName("Air Breakers!!"),tVersion("0.00a"){
	fps.reset(new FPS());

	flgEnd = false;
}

Game::~Game(){
	mSceneManager.Finalize();
}

void Game::Initialize(){
	mSceneManager.Initialize();
}

void Game::Finalize(){
}

bool Game::Update(){
	if(!mInput->All()){
		mSceneManager.Update();	// XV
		mSceneManager.Draw();	// •`‰æ

		if(this->GetIEnd()){
			return false;
		}
	}

// FPS
//	fps->Draw();
//	fps->Wait();
	return true;
}