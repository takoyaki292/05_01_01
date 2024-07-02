#pragma once
#include<memory>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClaerScene.h"

class  GameManager
{
private:
	//シーンを保持する
	std::unique_ptr<IScene> sceneArr_[3];
	//現在のシーンの変数
	int currentSceneNo_;
	//前のシーンの変数
	int prevSceneNo_;

public:
	GameManager();
	~GameManager();
	int Run();
};