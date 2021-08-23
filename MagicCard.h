#pragma once
#include "Card.h"

enum class Type {
	trap,
	buff,
	spell
};

class MagicCard : virtual public Card
{
public:
	MagicCard();
	MagicCard(const string&, const string&, const unsigned int, const Type&);
	~MagicCard() = default;
	MagicCard& operator=(const MagicCard&);
	void set_type(const Type&);
	Type get_type() const;

	bool operator==(const MagicCard&)const;

	Card* clone() const override;

protected:
	Type turn_string_to_enum(const string&) const;
	string turn_enum_to_string(const Type&) const;
	Type type;
};

