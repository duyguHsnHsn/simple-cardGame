#include "PendulumCard.h"

void PendulumCard::set_remaining(const unsigned int attack_points, const unsigned int defense_points, const double& pendulum_scale, const Type& type) {
	MonsterCard::set_attack_points(attack_points);
	MonsterCard::set_defense_points(defense_points);
	MagicCard::set_type(type);
	this->pendulum_number = pendulum_scale;
}
PendulumCard::PendulumCard() : Card() {
	set_remaining(0, 0, 0, Type::buff);
}
PendulumCard::PendulumCard(const string& name, const string& effect, const unsigned int rarity, const unsigned int attack_points, const unsigned int defense_points, const double& pendulum_scale, const Type& type) : Card(name, effect, rarity) {
	set_remaining(attack_points, defense_points, pendulum_scale, type);
}
void PendulumCard::set_pendilum_number(const double& number) {
	this->pendulum_number = number;
}
double PendulumCard::get_pendilum_number() const {
	return this->pendulum_number;
}
bool PendulumCard :: operator==(const PendulumCard& second)const {
	if (this->name == second.name && this->rarity == second.rarity && this->effect == second.effect && this->type == second.type &&
		this->attack_points == second.attack_points && this->defense_points == second.defense_points &&
		this->pendulum_number == second.pendulum_number) {
		return true;
	}
	else {
		return false;
	}
}
PendulumCard& PendulumCard :: operator=(const PendulumCard& second) {
	if (this != &second) {
		MonsterCard :: operator=(second);
		MagicCard :: operator=(second);
		this->pendulum_number = second.pendulum_number;
	}
	return *this;
}
Card* PendulumCard::clone() const {
	return new PendulumCard(*this);
}