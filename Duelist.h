#pragma once
#include "Deck.h"

class Duelist
{
public:
	Duelist();
	Duelist(const string&);
	Duelist(const string&, const Deck&);
	Duelist(const Duelist&);

	Deck& return_deck();

	void set_name(const string&);
	string get_name()const;

	void set_Deck(const Deck&);

private:
	Deck myDeck;
	string name;
};

