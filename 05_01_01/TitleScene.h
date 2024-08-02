#pragma once
#include "IScene.h"
#include "Player.h"

class TitleScene :public IScene
{
public:
	//TitleScene();
	//~TitleScene();
	
	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
	
private:
	Player* player = nullptr;
	//Enemy* enemy = nullptr;
};