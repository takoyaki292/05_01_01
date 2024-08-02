#pragma once
#include "Vector2.h"
#include "Enemy.h"
#ifndef STRUCT_H
#define STRUCT_H
struct AABB {
	Vector2 min;
	Vector2 max;
};
#endif
class Player {
private:


	float speed_ = 5.0f;
	int playerR_ = 30;
	int bulletR_ = 30;
	float bulletSpeed_ = 7.0f;

	Enemy* enemy_ = nullptr;
public:
	Vector2 pos_ = { 500,400 };
	Vector2 bulletPos_ = { pos_.x,pos_.y };
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
	void IsBullet();
	void MoveBullet();
	//void checkCollision(Vector2 playerPos, Vector2 enemyPos, int playerR, int enemyR, int isDistane);
	int isAlive = 1;
	int isBulletF = false;

	Vector2 GetWorldPosition();
	Vector2 GetWorldBullet();
	
	AABB GetPlayerAABB();
	AABB GetPlayerBulletAABB();
};