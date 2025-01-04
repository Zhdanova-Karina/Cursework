#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"
#include <cwchar>

Player::Player() : score(0) {
    wcscpy(name, L"");
}

Player::Player(const wchar_t* playerName) : score(0) {
    wcscpy(name, playerName);
}

const wchar_t* Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

void Player::incrementScore() {
    score++;
}

void Player::resetScore() {
    score = 0;
}

void Player::setName(const wchar_t* playerName) {
    wcscpy(name, playerName);
}
