#include "command.h"
#include "Player.h"
 
ICommand::~ICommand()
{
}

void MoveRightCommand::Exec(Player& player)
{
	player.MoveRight();
}

void MoveLetfCommand::Exec(Player& player)
{
	player.MoveLeft();
}
