#pragma once
#include "PendulumCard.h"
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono> 

class Deck
{
public:
	Deck() = default;
	Deck(const string&);
	Deck(const Deck&);
	void copy_clones(const vector<Card*> other_cards);
	Deck& operator=(const Deck&);
	~Deck();

	Card* get_card(const int index) const;

	void set_name(const string&);

	int get_magic_card_count()const;
	int get_monster_card_count()const;
	int get_pendulum_card_count()const;
	int get_all_cards_count()const;

	void add_card(const MagicCard* const);
	void add_card(const MonsterCard* const);
	void add_card(const  PendulumCard* const);

	void change_card(const int, const MagicCard* const);
	void change_card(const int, const MonsterCard* const);
	void change_card(const int, const PendulumCard* const);

	void clear_deck();
	void shuffle();

	friend ostream& operator<<(ostream& output, const Deck& to_print);
	friend istream& operator>>(istream& input, Deck& to_write);

	string get_name() const;
private:
	bool is_card_pendulum(Card*)const;
	string substring(const string&, const int&, int);
	string name;
	vector<Card*> myCards;
};