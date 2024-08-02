#pragma once
#include "IScene.h"
#include "Player.h"
//#include "Enemy.h"
class OverScene :public IScene
{
public:
	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

private:
	Player player_;
};