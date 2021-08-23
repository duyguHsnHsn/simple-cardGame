#pragma once
#include "Card.h"
#include <iostream>

class MonsterCard : virtual public Card
{
public:
	MonsterCard();
	MonsterCard(const string&, const string&, const unsigned int, const unsigned int, const unsigned int);
	~MonsterCard() = default;
	MonsterCard& operator=(const MonsterCard&);
	unsigned int get_attack_point()const;
	unsigned int get_defense_points()const;

	void set_attack_points(const unsigned int);
	void set_defense_points(const unsigned int);

	bool operator==(const MonsterCard&)const;

	Card* clone() const override;

protected:
	unsigned int attack_points;
	unsigned int defense_points;
};
