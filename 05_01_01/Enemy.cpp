#include "Enemy.h"
#include "Novice.h"
Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init(const Vector2& pos, const int& bulletTimer)
{
	pos_ = pos;
	bulletTimer_ = bulletTimer;
	isAlive = 1;
}

void Enemy::Update()
{
}


void Enemy::Draw()
{
	if (isAlive == 1)
	{
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, R, R, 0.0f, RED, kFillModeSolid);
	}
	if (isBulletF == 1)
	{
		Novice::DrawEllipse((int)bulletPos_.x, (int)bulletPos_.y, bulletR, bulletR, 0.0f, RED, kFillModeSolid);
	}
}

void Enemy::MoveRight()
{
	//右に行く
	this->pos_.x += this->speed_;
}

void Enemy::MoveLeft()
{
	//左に行く
	this->pos_.x -= this->speed_;
}

void Enemy::MoveEnemy()
{
	//MoveRight();
	if (this->pos_.x > 1280 - this->R) {
		this->speed_ = -3.0f;
	}
	else if (this->pos_.x < 50 - this->R)
	{
		this->speed_ = +3.0f;
	}

}

void Enemy::MoveBullet()
{

	if (isBulletF == 1)
	{
		this->bulletPos_.y += this->bulletSpeed_;
		if (this->bulletPos_.y > 720 - bulletR)
		{
			isBulletF = 0;
		}
	}
	if (isBulletF == 0)
	{
		this->bulletPos_ = this->pos_;
		//bulletTimer_ = 0;
		bulletTimer_++;
	}

}

void Enemy::TimerBullet()
{
	if (isAlive ==1)
	{
		if (isBulletF == 0)
		{
			bulletTimer_++;
		}
	}
	if (bulletTimer_ >= 60)
	{
		isBulletF = 1;
		bulletTimer_ = 0;
	}
}

Vector2 Enemy::GetWorldPosition()
{
	Vector2 pos;
	pos.x = this->pos_.x;
	pos.y = this->pos_.y;

	return pos;
}

Vector2 Enemy::GetWorldBullet()
{
	Vector2 pos;
	pos.x = this->bulletPos_.x;
	pos.y = this->bulletPos_.y;
	return pos;
}

AABB Enemy::GetPosAABB()
{
	Vector2 worldPos = GetWorldPosition();

	AABB aabb;
	aabb.min = {
		worldPos.x - this->R, worldPos.y - this->R };
	aabb.max = {
		worldPos.x + this->R, worldPos.y + this->R };
	return aabb;
}

AABB Enemy::GetBulletAABB()
{
	Vector2 worldPos = GetWorldBullet();

	AABB aabb;
	aabb.min = {
		worldPos.x - this->bulletR, worldPos.y - this->bulletR };
	aabb.max = {
		worldPos.x + this->R, worldPos.y + this->bulletR };
	return aabb;
}
