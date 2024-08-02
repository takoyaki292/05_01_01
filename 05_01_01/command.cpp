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

void MoveUpCommand::Exec(Player& player)
{
	player.MoveUp();
}

void MoveDownCommand::Exec(Player& player)
{
	player.MoveDown();
}

void PCommand::Exec(Player& player)
{
	
	if (player.isBulletF == 0)
	{
		player.IsBullet();
	}
	
}
