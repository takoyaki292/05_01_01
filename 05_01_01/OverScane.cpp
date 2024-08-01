#include "OverScane.h"
#include <Novice.h>
#include <stdio.h>
void OverScene::Init()
{
}

void OverScene::Update(char* keys, char* preKeys)
{
	//titleに切り替える
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
	{
		sceneNo = TITLE;
	}
	
}

void OverScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, GREEN, kFillModeSolid);
}
