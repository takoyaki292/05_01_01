#include "Enemy.h"
#include "Novice.h"
Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
}

void Enemy::Update()
{
}


void Enemy::Draw()
{
	Novice::DrawBox((int)pos_.x, (int)pos_.y, 50, 50, 0.0f, RED, kFillModeSolid);
}
