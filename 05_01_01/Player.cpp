#include "Player.h"
#include <Novice.h>
#include <corecrt_math.h>
Player::Player()
{
	isAlive = 1;
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
	//checkCollision(pos_, enemy_->pos_, playerR_, enemy_->R, isAlive);
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
		Novice::DrawEllipse((int)bulletPos_.x, (int)bulletPos_.y, bulletR_, bulletR_, 0.0f, RED, kFillModeSolid);
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
	if (isAlive == 1)
	{
		isBulletF = true;

	}
}

void Player::MoveBullet()
{
	if (isBulletF == 1)
	{
		this->bulletPos_.y -= this->bulletSpeed_;
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



Vector2 Player::GetWorldPosition()
{
	Vector2 pos;
	pos.x = this->pos_.x;
	pos.y = this->pos_.y;

	return pos;
}

Vector2 Player::GetWorldBullet()
{
	Vector2 pos;
	pos.x = this->bulletPos_.x;
	pos.y = this->bulletPos_.y;

	return pos;
}

AABB Player::GetPlayerAABB()
{
	Vector2 worldPos = GetWorldPosition();

	AABB aabb;
	aabb.min = {
		worldPos.x - this->playerR_, worldPos.y - this->playerR_ };
	aabb.max = {
		worldPos.x + this->playerR_, worldPos.y + this->playerR_};
	return aabb;
}

AABB Player::GetPlayerBulletAABB()
{
	Vector2 worldPos = GetWorldBullet();

	AABB aabb;
	aabb.min = {
		worldPos.x - this->bulletR_, worldPos.y - this->bulletR_ };
	aabb.max = {
		worldPos.x + this->bulletR_, worldPos.y + this->bulletR_ };
	return aabb;
}
