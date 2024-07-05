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
	return nullptr;
}