#include "MonsterCard.h"

MonsterCard::MonsterCard() : Card() {
	this->defense_points = 0;
	this->attack_points = 0;
}
MonsterCard::MonsterCard(const string& name, const string& effect, const unsigned int rarity, const unsigned int attack_points, const unsigned int defense_points) : Card(name, effect, rarity) {
	this->defense_points = defense_points;
	this->attack_points = attack_points;
}
unsigned int MonsterCard::get_attack_point()const {
	return this->attack_points;
}
unsigned int MonsterCard::get_defense_points()const {
	return this->defense_points;
}
void MonsterCard::set_attack_points(const unsigned int new_points) {
	this->attack_points = new_points;
}
void MonsterCard::set_defense_points(const unsigned int new_points) {
	this->defense_points = new_points;
}
bool MonsterCard :: operator==(const MonsterCard& second)const {
	if (this->name == second.name && this->effect == second.effect && this->rarity == second.rarity && this->attack_points == second.attack_points && this->defense_points == second.defense_points) {
		return true;
	}
	return false;
}
MonsterCard& MonsterCard :: operator=(const MonsterCard& second) {
	if (this != &second) {
		this->attack_points = second.attack_points;
		this->defense_points = second.defense_points;
		Card :: operator=(second);
	}
	return *this;
}
Card* MonsterCard::clone() const {
	return new MonsterCard(*this);
}