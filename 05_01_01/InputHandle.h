#pragma once
#include <Command.h>
class InputHandler {
public:
	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();
	void AssignMoveUpCommand2PressKeyW();
	void AssignMoveDownCommand2PressKeyS();
	void AssignCommand2PressKeyP();


private:
	ICommand* pressKeyD_;
	ICommand* pressKeyA_;
	ICommand* pressKeyW_;
	ICommand* pressKeyS_;
	ICommand* pressKeyP_;

};