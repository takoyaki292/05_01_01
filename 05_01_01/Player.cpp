#include "Player.h"
#include <Novice.h>
#include <corecrt_math.h>
Player::Player()
{
}

Player::~Player()
{
	//delete enemy_;
}

void Player::Init()
{
	//enemy_ = new Enemy();
}

void Player::Update()
{
	checkCollision(pos_, enemy_->pos_, playerR_, enemy_->R,isAlive);
}

void Player::Draw()
{
	if (isAlive == 1)
	{
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, playerR_, playerR_, 0.0f, WHITE, kFillModeSolid);
	}
	Novice::ScreenPrintf(0, 0, "IsBulletF:%d", isBulletF);
	Novice::ScreenPrintf(0, 50, "playerIsAlive:%d", isAlive);
	if (isBulletF == 1)
	{
		Novice::DrawEllipse((int)bulletPos_.x, (int)bulletPos_.y,bulletR_,bulletR_, 0.0f, RED, kFillModeSolid);
	}
}

void Player::MoveRight()
{
	this->pos_.x += this->speed_;
}

void Player::MoveLeft()
{
	this->pos_.x -= this->speed_;
}

void Player::MoveUp()
{
	this->pos_.y -= this->speed_;
}

void Player::MoveDown()
{
	this->pos_.y += this->speed_;
}

void Player::IsBullet()
{
	isBulletF = true;
}

void Player::MoveBullet()
{
	if (isBulletF== 1)
	{
		this->bulletPos_.y-= this->bulletSpeed_;
		if (this->bulletPos_.y < bulletR_)
		{
			isBulletF = 0;
		}
	}
	if (isBulletF == 0)
	{
		this->bulletPos_ = this->pos_;
	}
	
}

//丸の当たり判定
//void Player::checkCollision(Vector2 playerPos, Vector2 enemyPos, int playerR, int enemyR,int isDistane)
//{
//	float dx = playerPos.x - enemyPos.x;
//	float dy = playerPos.y - enemyPos.y;
//	bool distance =sqrt(dx * dx + dy * dy);
//	int R = playerR + enemyR;
//	if ((int)distance <= R)
//	{
//		isDistane = 1;
//	}
//	else {
//		isDistane = 0;
//	}
//
//}
