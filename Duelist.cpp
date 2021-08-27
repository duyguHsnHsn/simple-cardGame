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

void Duelist::Duel(Duelist& opponent) {
	int silver = 0;
	cout << "Enter the money that both of you are betting in silver: \n";
	cin >> silver;
	if (this->myMoney.get_gold() * 100 + this->myMoney.get_silver() < silver ||
		opponent.myMoney.get_gold() * 100 + opponent.myMoney.get_silver() < silver) {
		throw invalid_argument("Not enough money! \n");
	}
	int rounds = 0;
	cout << "Enter the number of rounds to be played: \n";
	cin >> rounds;
	if (this->myDeck.get_all_cards_count() < rounds || opponent.myDeck.get_all_cards_count() < rounds) {
		throw invalid_argument("Not enough cards! \n");
	}
	else {
		int myScore = 0;
		int opponentScore = 0;
		this->myDeck.shuffle();
		opponent.myDeck.shuffle();
		for (int i = 0; i < this->myDeck.get_all_cards_count(); i++) {
			if (this->myDeck.get_card(i)->operator>(*opponent.myDeck.get_card(i))) {
				myScore++;
			}
			else if (this->myDeck.get_card(i)->operator<(*opponent.myDeck.get_card(i))) {
				opponentScore++;
			}
			else {
				continue;
			}
		}
		if (myScore > opponentScore) {
			cout << "The first duelist " << this->name << "  wins the duel. \n";
			cout << "He raised " << silver << "in this game. ";
			this->myMoney.add_silver(silver);
			cout << "Now he has " << this->myMoney.get_gold() << " gold  and " << this->myMoney.get_silver() << " silver.";

		}
		else if (myScore < opponentScore) {
			cout << "The first duelist " << opponent.name << "  wins the duel. \n";
			cout << "He raised " << silver << "in this game. ";
			opponent.myMoney.add_silver(silver);
			cout << "Now he has " << opponent.myMoney.get_gold() << " gold  and " << opponent.myMoney.get_silver() << " silver.";
		}
		else {
			cout << "Equal score. No money is raised.";
		}
	}
}