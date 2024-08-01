#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"
class TitleScene :public IScene
{
public:
	//TitleScene();
	//~TitleScene();
	
	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
	//void checkCollision(Vector2 playerPos, Vector2 enemyPos, int playerR, int enemyR, int isDistane);
private:
	//Player* player_ = nullptr;
	//Enemy* enemy_ = nullptr;
	
};