#include "StageScene.h"
#include <Novice.h>
#include <stdio.h>

void StageScene::Init()
{
	inputHandler_ = new InputHandler();
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveUpCommand2PressKeyW();
	inputHandler_->AssignMoveDownCommand2PressKeyS();
	inputHandler_->AssignCommand2PressKeyP();


	player_ = new Player();
	enemy_ = new Enemy();
}
void StageScene::Update(char* keys, char* preKeys)
{
	iCommand_ = inputHandler_->HandleInput();

	if (this->iCommand_)
	{
		iCommand_->Exec(*player_);
		enemy_->Update();
	}
	//claerに切り替える
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
	{
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
	player_->Draw();
	enemy_->Draw();
}