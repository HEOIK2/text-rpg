#include "player.h"
using namespace std;

Player::Player(string name, int hp, int mp, int power, int defence) : name(name), hp(hp), mp(mp), power(power), defence(defence), level(1) {}

int Player::getHP() {
	return hp;
}
int Player::getMP() {
	return mp;
}
int Player::getPower() {
	return power;
}
int Player::getDefence() {
	return defence;
}
string Player::getName() {
	return name;
}
void Player::setHP(int newHP) {
	hp = newHP;
}
void Player::setMP(int newMP) {
	mp = newMP;
}
void Player::setPower(int newPower) {
	power = newPower;
}
void Player::setDefence(int newDefence) {
	defence = newDefence;
}
void Player::setJob(string newJob) {
	job = newJob;
}
void Player::setLevel(int newLevel) {
	level = newLevel;
}