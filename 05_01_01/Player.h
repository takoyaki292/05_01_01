#pragma once
#include "Vector2.h"
class Player {
private:

	Vector2 pos_ = {300,200};
	float speed_ = 3.0f;
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();
	//移動するときの処理の関数
	void MoveRight();
	void MoveLeft();

	
};