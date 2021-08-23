#include "Card.h"

void Card::set_all(const string& name, const string& effect, const unsigned int rarity) {
	this->name = name;
	this->effect = effect;
	this->rarity = rarity;
}
Card::Card() {
	set_all("", "", 1);
}
Card::Card(const string& name, const string& effect, const unsigned int rarity) {
	set_all(name, effect, rarity);
}
Card& Card :: operator=(const Card& second) {
	if (this != &second) {
		set_all(second.name, second.effect, second.rarity);
	}
	return *this;
}
string Card::get_name()const {
	return this->name;
}
string Card::get_effect()const {
	return this->effect;
}
unsigned int Card::get_rarity()const {
	return this->rarity;
}
void Card::set_name(const string& name) {
	this->name = name;
}
void Card::set_effect(const string& effect) {
	this->effect = effect;
}
void Card::set_rarity(const unsigned int rarity) {
	this->rarity = rarity;
}
bool Card :: operator<(const Card& second)const {
	if (this->rarity < second.rarity) {
		return true;
	}
	return false;
}
bool Card :: operator>(const Card& second)const {
	if (this->rarity > second.rarity) {
		return true;
	}
	return false;
}
string Card::substring(const string& from, const int& index, int starting) {
	string substring;
	while (starting != index) {
		substring += from[starting];
		starting++;
	}
	return substring;
}