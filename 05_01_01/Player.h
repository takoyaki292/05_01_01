#pragma once
#include "Vector2.h"
class Player {
private:

	Vector2 pos_ = { 500,400 };

	float speed_ = 5.0f;
	int r = 30;
	Vector2 bulletPos_ = {pos_.x,pos_.y};
	int isBulletF = false;
	//int bulletTimer = 0;
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();
	//移動するときの処理の関数
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void MoveBullet();
};