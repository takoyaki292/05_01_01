#include "GameManager.h"
#include <Novice.h>
GameManager::GameManager()
{
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClaerScene>();
	sceneArr_[OVER] = std::make_unique<OverScene>();

	currentSceneNo_ = TITLE;
}

GameManager::~GameManager()
{
}

int GameManager::Run()
{
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	while (Novice::ProcessMessage() == 0)
	{
		//フレーム開始
		Novice::BeginFrame();
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		//シーンのチェック
		prevSceneNo_ = currentSceneNo_;

		currentSceneNo_ = sceneArr_[prevSceneNo_]->GetSceneNo();

		//シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_)
		{
			sceneArr_[currentSceneNo_]->Init();
		}
		sceneArr_[currentSceneNo_]->Update(keys, preKeys);
		sceneArr_[currentSceneNo_]->Draw();

		//フレーム終了
		Novice::EndFrame();
		//escキーが押されたら、終了する
		if (!preKeys[DIK_ESCAPE] && keys[DIK_ESCAPE])
		{
			break;
		}
	}
	return 0;
}