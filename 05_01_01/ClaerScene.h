#pragma once
#include "IScene.h"


class ClaerScene :public IScene
{
public:
	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

};