#pragma once
#include "IScene.h"
#include "InputHandle.h"
#include "command.h"
#include "Player.h"
#include "Enemy.h"
#include <list>

class StageScene :public IScene
{
public:
	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
	StageScene();
	~StageScene();
	//void checkCollision(Vector2 playerPos, Vector2 enemyPos, int playerR, int enemyR, int isDistane);
private:
	InputHandler* inputHandler_ = nullptr;
	ICommand* iCommand_=nullptr;
	Player* player_=nullptr;
	
	std::list<Enemy*> enemies_;
};