#include "MagicCard.h"

MagicCard::MagicCard() : Card() {
	this->type = Type::buff;
}
MagicCard::MagicCard(const string& name, const string& effect, const unsigned int rarity, const Type& type) : Card(name, effect, rarity) {
	this->type = type;
}
Type MagicCard::get_type() const {
	return this->type;
}
void MagicCard::set_type(const Type& type) {
	this->type = type;
}
bool MagicCard :: operator==(const MagicCard& second)const {
	if (this->name == second.name && this->rarity == second.rarity && this->effect == second.effect && this->type == second.type) {
		return true;
	}
	return false;
}
Type MagicCard::turn_string_to_enum(const string& myEnum) const {
	if (myEnum == "buff") {
		return Type::buff;
	}
	else if (myEnum == "trap") {
		return Type::trap;
	}
	else {
		return Type::spell;
	}
}
string MagicCard::turn_enum_to_string(const Type& myType) const {
	if (myType == Type::buff) {
		return "buff";
	}
	else if (myType == Type::trap) {
		return "trap";
	}
	else {
		return "spell";
	}
}
MagicCard& MagicCard :: operator=(const MagicCard& second) {
	if (this != &second) {
		this->type = second.type;
		Card :: operator=(second);
	}
	return *this;
}
Card* MagicCard::clone() const {
	return new MagicCard(*this);
}
istream& operator>>(istream& input, MagicCard& to_write) {
	int index = 0;
	string helper;
	getline(input, helper);
	int counter = 0;
	for (unsigned int i = 0; i < helper.size(); i++) {
		if (helper[i] == '|' && counter == 0) {
			to_write.name = to_write.substring(helper, i, index);
			index = i + 1;
			counter++;
		}
		else if (helper[i] == '|' && counter == 1) {
			to_write.effect = to_write.substring(helper, i, index);
			index = i + 1;
			counter++;
		}
		else if (helper[i] == '|' && counter == 2) {
			to_write.rarity = stoi(to_write.substring(helper, i, index));
			index = i + 1;
			counter++;
		}
		else if (counter == 3) {
			to_write.type = to_write.turn_string_to_enum(to_write.substring(helper, helper.size(), index));
			break;
		}
	}
	return input;
}
ostream& operator<<(ostream& output, const MagicCard& to_print) {
	output << to_print.name << '|' << to_print.effect << '|' << to_print.rarity << '|';
	output << to_print.turn_enum_to_string(to_print.type);
	return output;
}