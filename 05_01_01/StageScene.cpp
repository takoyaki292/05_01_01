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
	//enemy_ = new Enemy();
	for (int i = 0; i < 1; i++)
	{
		Enemy* newEnemy = new Enemy();
		Vector2 pos = {200.f+80*i,100.f};
		int bulletTimer = 0;
		newEnemy->Init(pos,bulletTimer);
		enemies_.push_back(newEnemy);
	}

}
void StageScene::Update(char* keys, char* preKeys)
{
	iCommand_ = inputHandler_->HandleInput();

	if (this->iCommand_)
	{
		iCommand_->Exec(*player_);
		
	}
	
	//checkCollision(player_->pos_,)
	if (player_->isAlive == 1)
	{
		player_->MoveBullet();
		player_->Update();
		//claerに切り替える
		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
		{
			sceneNo = CLEAR;
		}
	}
	else if(player_->isAlive==0)
	{
		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
		{
			sceneNo = OVER;
		}
	}
	
	
	for (Enemy* enemy : enemies_) {
		if (!enemy) {
			continue;
		}
		else {
			enemy->MoveEnemy();
			enemy->Update();
			enemy->MoveBullet();
			enemy->TimerBullet();
		}
	}
}

void StageScene::Draw()
{
	player_->Draw();
	for (Enemy* enemy : enemies_) {
		if (!enemy) {
			continue;
		}
		enemy->Draw();
	}
}

StageScene::StageScene()
{
}

StageScene::~StageScene()
{
	delete player_;
	//delete enemy_;
	for (Enemy* kEnemy : enemies_) {
		delete kEnemy;
	}
}

void StageScene::checkCollision(Vector2 playerPos, Vector2 enemyPos, int playerR, int enemyR, int isDistane)
{
	float dx = playerPos.x - enemyPos.x;
	float dy = playerPos.y - enemyPos.y;
	bool distance = sqrt(dx * dx + dy * dy);
	int R = playerR + enemyR;
	if ((int)distance <= R)
	{
		isDistane = 1;
	}
	else {
		isDistane = 0;
	}
}
