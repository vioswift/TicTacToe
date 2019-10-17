#include "stdafx.h"
#include "Player.h"

Player::Player(int type) {
	playerType = type;
}

int Player::getType() {
	return playerType;
}