#include "Duelist.h"


Duelist::Duelist() : myDeck() {
	this->name = "";
}
Duelist::Duelist(const string& name) {
	this->name = name;
}
Duelist::Duelist(const string& name, const Deck& deck) {
	this->name = name;
	this->myDeck = deck;
}
Duelist::Duelist(const Duelist& from) {
	this->myDeck = from.myDeck;
	this->name = from.name;
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