#pragma once
#include "IScene.h"
#include "Player.h"

class TitleScene :public IScene
{
public:	
	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
	
private:

};