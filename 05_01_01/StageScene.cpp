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
	this->player_->isAlive = 1;
	for (int i = 0; i < 3; i++)
	{
		Enemy* newEnemy = new Enemy();
		//newEnemy = nullptr;
		Vector2 pos = { 200.f + 80 * i,100.f };
		//newEnemy->isBulletF = 1;
		newEnemy->isAlive = 1;
		int bulletTimer = 0;
		newEnemy->bulletPos_ = newEnemy->pos_;
		newEnemy->Init(pos, bulletTimer);
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
	if (player_->isAlive == 1)
	{
		player_->MoveBullet();
		
		player_->Update();
		playerCollisios();
		playerBulletCollisios();
		//claerに切り替える
		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
		{
			sceneNo = CLEAR;
		}
	}
	else if (player_->isAlive == 0)
	{
		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
		{
			sceneNo = OVER;
		}
	}


	for (Enemy* enemy : enemies_) {
		if (!enemy) {
			//claerに切り替える
			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
			{
				sceneNo = CLEAR;
			}
			continue;
		}
		else {
			if (enemy->isAlive == 1)
			{
				enemyBulletCollisios();
				enemyCollisios();
				enemy->MoveEnemy();
				enemy->Update();
				enemy->MoveBullet();
				enemy->TimerBullet();
			}
			
			
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
		if (enemy->isAlive == 1)
		{
			enemy->Draw();

		}
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
void StageScene::playerCollisios()
{
	AABB aabb1, aabb2;
	aabb1 = player_->GetPlayerAABB();

	for (Enemy* enemy : enemies_)
	{
		aabb2 = enemy->GetPosAABB();
		if (IsCollision(aabb1,aabb2))
		{
			player_->isAlive = 0;
			
		}
	}
}

void StageScene::enemyCollisios()
{
	AABB aabb1, aabb2;
	aabb1 = player_->GetPlayerBulletAABB();

	for (Enemy* enemy : enemies_)
	{
		aabb2 = enemy->GetBulletAABB();
		if (IsCollision(aabb1, aabb2))
		{
			enemy->isBulletF = 0;
			player_->isBulletF = 0;

		}
	}
}



void StageScene::playerBulletCollisios()
{
	AABB aabb1, aabb2;
	aabb1 = player_->GetPlayerBulletAABB();

	for (Enemy* enemy : enemies_)
	{
		aabb2 = enemy->GetPosAABB();
		if (IsCollision(aabb1, aabb2))
		{
			enemy->isAlive = 0;
			enemy->isBulletF = 0;
			
			//player_->isBulletF = 0;
		}
	}
}

void StageScene::enemyBulletCollisios()
{
	AABB aabb1, aabb2;
	aabb1 = player_->GetPlayerAABB();

	for (Enemy* enemy : enemies_)
	{
		aabb2 = enemy->GetBulletAABB();
		if (IsCollision(aabb2, aabb1))
		{
			player_->isAlive = 0;
			player_->isBulletF = 0;

			//player_->isBulletF = 0;
		}
	}
}

bool StageScene::IsCollision(AABB a, AABB b)
{
	bool isF = false;
	if (a.max.x > b.min.x && a.min.x<b.max.x
		&& a.max.y > b.min.y && a.min.y < b.max.y) {
		isF = true;
	}
	return isF;
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