#include "Player.h"
#include <Novice.h>
Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	
}

void Player::Draw()
{
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, r, r, 0.0f, WHITE, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "IsBulletF:%d", isBulletF);
}

void Player::MoveRight()
{
	//右に行く
	this->pos_.x += this->speed_;
}

void Player::MoveLeft()
{
	//左に行く
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

void Player::MoveBullet()
{
	//if (isBulletF == false)
	//{
	//	isBulletF = true;
	//	//bulletTimer = 0;
	//}
	//else if(isBulletF==true)
	//{
	//
	//}
	isBulletF = true;
}
