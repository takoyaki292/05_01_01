#pragma once
#include "Vector2.h"
class Enemy {
private:

	float speed_ = 3.0f;
	float bulletSpeed_ = 5.0f;

	int bulletTimer_ = 0;
public:
	Enemy();
	~Enemy();

	Vector2 pos_ = { 300,200 };
	Vector2 bulletPos_ = { pos_.x,pos_.y };
	int R = 30;
	int bulletR = 20;
	void Init(const Vector2& pos, const int& bulletTimer);
	void Update();
	void Draw();
	//移動するときの処理の関数
	void MoveRight();
	void MoveLeft();
	void MoveEnemy();
	void MoveBullet();
	int isAlive = 1;
	int isBulletF = 0;
	void TimerBullet();
};