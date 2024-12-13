#include "InputHandle.h"
#include "command.h"
#include <Novice.h>
void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	ICommand *command = new MoveLetfCommand();
	this->pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	ICommand *command = new MoveRightCommand();
	this->pressKeyD_ = command;
}

void InputHandler::AssignMoveUpCommand2PressKeyW()
{
	ICommand *command = new MoveUpCommand();
	this->pressKeyW_ = command;
}

void InputHandler::AssignMoveDownCommand2PressKeyS()
{
	ICommand *command = new MoveDownCommand();
	this->pressKeyS_ = command;
}

void InputHandler::AssignCommand2PressKeyP()
{
	ICommand* command = new PCommand();
	this->pressKeyP_ = command;
}





ICommand* InputHandler::HandleInput()
{
	//入力処理を入れて、変数に返している
	if (Novice::CheckHitKey(DIK_D))
	{
		return pressKeyD_;
	}
	if (Novice::CheckHitKey(DIK_A))
	{
		return pressKeyA_;
	}
	if (Novice::CheckHitKey(DIK_W))
	{
		return pressKeyW_;
	}
	if (Novice::CheckHitKey(DIK_S))
	{
		return pressKeyS_;
	}
	if (Novice::CheckHitKey(DIK_P))
	{
		return pressKeyP_;
	}
	return nullptr;
}