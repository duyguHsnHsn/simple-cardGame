#pragma once
#include <string>
using namespace std;

// this is the abstract base class for all of the cards

class Card
{
public:
	Card();
	Card(const string& name, const string& effect, const unsigned int rarity);

	virtual ~Card() = default;
	virtual Card* clone() const = 0;

	Card& operator=(const Card&);
	string get_name()const;
	string get_effect() const;
	unsigned int get_rarity() const;

	void set_name(const string& name);
	void set_effect(const string& effect);
	void set_rarity(const unsigned int rarity);

	bool operator<(const Card&)const;  // this operators will be used to  compare rarity 
	bool operator>(const Card&)const;

protected:
	void set_all(const string&, const string&, const unsigned int);
	string substring(const string&, const int&, int);
	string name;
	string effect;
	unsigned int rarity;
};

