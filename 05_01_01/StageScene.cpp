#include "StageScene.h"
#include <Novice.h>
#include <stdio.h>

void StageScene::Init()
{
	inputHandler_ = new InputHandler();
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();

	player_ = new Player();
}

void StageScene::Update(char* keys, char* preKeys)
{
	iCommand_ = inputHandler_->HandleInput();

	if (this->iCommand_)
	{
		iCommand_->Exec(*player_);
	}
	//claerに切り替える
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
	{
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
	//Novice::ScreenPrintf(0,0,"player:%f,%f",player_.)
	//Novice::DrawBox(0, 0, 1280, 720, 0.0f, WHITE, kFillModeSolid);
	player_->Draw();
}