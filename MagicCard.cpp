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