#include "StageScene.h"
#include <Novice.h>
#include <stdio.h>
void StageScene::Init()
{
}

void StageScene::Update(char* keys, char* preKeys)
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, WHITE, kFillModeSolid);
	//claerに切り替える
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
	{
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
}