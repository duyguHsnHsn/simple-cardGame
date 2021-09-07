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
ostream& operator<<(ostream& output, const PendulumCard& to_print) {
	output << to_print.name << '|' << to_print.effect << '|' << to_print.rarity << '|' << to_print.attack_points
		<< '|' << to_print.defense_points << '|' << to_print.pendulum_number << '|';
	output << to_print.turn_enum_to_string(to_print.type);
	return output;
}
istream& operator>>(istream& input, PendulumCard& to_write) {
	string helper;
	int index = 0;
	getline(input, helper);
	int counter = 0;
	for (unsigned int i = 0; i < helper.size(); i++) {
		if (helper[i] == '|' && counter == 0) {
			to_write.name = to_write.substring(helper, i, index);
			counter++;
			index = i + 1;
		}
		else if (helper[i] == '|' && counter == 1) {
			to_write.effect = to_write.substring(helper, i, index);
			counter++;
			index = i + 1;
		}
		else if (helper[i] == '|' && counter == 2) {
			to_write.rarity = stoi(to_write.substring(helper, i, index));
			counter++;
			index = i + 1;
		}
		else if (helper[i] == '|' && counter == 3) {
			to_write.attack_points = stoi(to_write.substring(helper, i, index));
			counter++;
			index = i + 1;
		}
		else if (helper[i] == '|' && counter == 4) {
			to_write.defense_points = stoi(to_write.substring(helper, i, index));
			index = i + 1;
			counter++;
		}
		else if (helper[i] == '|' && counter == 5) {
			to_write.pendulum_number = stoi(to_write.substring(helper, i, index));
			index = i + 1;
			counter++;
		}
		else if (counter == 6) {
			to_write.type = to_write.turn_string_to_enum(to_write.substring(helper, helper.size() + 1, index));
			break;
		}
	}
	return input;
}