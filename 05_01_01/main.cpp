#include <Novice.h>
#include "GameManager.h"
const char kWindowTitle[] = "GC2B_08_シミズ_タクミ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	GameManager game;
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	game.Run();
	//game.~GameManager();
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}