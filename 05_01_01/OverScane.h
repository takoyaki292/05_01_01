#pragma once
#include "IScene.h"


class OverScene :public IScene
{
public:
	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

};