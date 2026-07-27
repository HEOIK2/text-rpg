#include "player.h"
#include <iostream>
using namespace std;

Player::Player(string name, int hp, int mp, int power, int defence) : name(name), hp(hp), mp(mp), power(power), defence(defence), level(1), exp(0), maxExp(100), maxHP(hp), maxMP(mp) {}

int Player::getHP() {
	return hp;
}
int Player::getMP() {
	return mp;
}
int Player::getMaxHP() {
	return maxHP;
}
int Player::getMaxMP() {
	return maxMP;
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
int Player::getExp() {
	return exp;
}
int Player::getMaxExp() {
	return maxExp;
}
int Player::getLevel() {
	return level;
}
void Player::setHP(int newHP) {
	hp = newHP;
}
void Player::setMP(int newMP) {
	mp = newMP;
}
void Player::setMaxHP(int newMaxHP) {
	maxHP = newMaxHP;
}
void Player::setMaxMP(int newMaxMP) {
	maxMP = newMaxMP;
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
void Player::setExp(int newExp) {
	exp = newExp;
}
void Player::gainExp(int amount) {
	exp += amount;
	if (exp >= maxExp) {
		int prelevel = level;
		level += 1;
		exp = 0;
		maxHP += 10;
		maxMP += 5;
		power += 5;
		maxExp += 50;
		hp = maxHP;
		cout << "레벨 업! Lv." << prelevel << "->" << "Lv." << level << "\n";
		cout << "최대HP +10, 최대MP +5, 공격력 +5 증가!";
	}
}
void Player::printPlayerStatus() {
	cout << "\n" << "<" << name << ">" << "\n";
	cout << "Level: " << level << "\n";
	cout << "EXP: " << exp << " / " << maxExp << "\n";
	cout << "HP: " << hp << " / " << maxHP << "\n";
	cout << "MP: " << mp << " / " << maxMP << "\n";
	cout << "PWR: " << power << "\n";
	cout << "DEF: " << defence << "\n";
}