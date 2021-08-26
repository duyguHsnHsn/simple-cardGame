#include "Duelist.h"


Duelist::Duelist() : myDeck(), myMoney() {
	this->name = "";
}
Duelist::Duelist(const string& name) {
	this->name = name;
}
Duelist::Duelist(const string& name, const Deck& deck) {
	this->name = name;
	this->myDeck = deck;
	this->myMoney.set_gold(0);
	this->myMoney.set_silver(0);
}
Duelist::Duelist(const Duelist& from) {
	this->myDeck = from.myDeck;
	this->name = from.name;
	this->myMoney.set_gold(from.myMoney.get_gold());
	this->myMoney.set_silver(from.myMoney.get_silver());
}
Deck& Duelist::return_deck() {
	return this->myDeck;
}
void  Duelist::set_name(const string& name) {
	this->name = name;
}
string Duelist::get_name()const {
	return this->name;
}
void Duelist::set_Deck(const Deck& deck) {
	this->myDeck = deck;
}
void Duelist::add_silver(const int silver) {
	this->myMoney.add_silver(silver);
}
void Duelist::add_gold(const int gold) {
	this->myMoney.add_gold(gold);
}
void Duelist::remove_silver(const int silver) {
	this->myMoney.remove_silver(silver);
}
void Duelist::remove_gold(const int gold) {
	this->myMoney.remove_gold(gold);
}