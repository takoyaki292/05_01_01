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
	Novice::DrawBox((int)pos_.x, (int)pos_.y, 50, 50, 0.0f, GREEN, kFillModeSolid);
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
