#pragma once
#include "MagicCard.h"
#include "MonsterCard.h"

class PendulumCard : public MonsterCard, public MagicCard
{
public:
	PendulumCard();
	PendulumCard(const string&, const string&, const unsigned int, const unsigned int, const unsigned int, const double&, const Type&);
	~PendulumCard() = default;
	PendulumCard& operator=(const PendulumCard&);
	void set_pendilum_number(const double&);
	double get_pendilum_number() const;

	friend ostream& operator<<(ostream& output, const PendulumCard& to_print);
	friend istream& operator>>(istream& input, PendulumCard& to_write);

	bool operator==(const PendulumCard&)const;

	Card* clone() const override;

private:
	void set_remaining(const unsigned int, const unsigned int, const double&, const Type&);
	double pendulum_number;
};
