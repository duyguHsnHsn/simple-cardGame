#pragma once
#include <utility>
#include <string>
#include <iostream>
using namespace std;

class Money
{
public:
	Money();
	Money(const int silver, const int gold);
	Money& operator=(const Money& second);

	void set_gold(const int gold);
	void set_silver(const int silver);

	void add_silver(const int silver);
	void remove_silver(const int silver);
	void add_gold(const int gold);
	void remove_gold(const int gold);

	int get_gold() const;
	int get_silver()const;

	string print()const;
private:
	void turn_gold_to_silver();
	void turn_silver_to_gold();
	std::pair<int, int> myMoney; // gold is first and second is silver
};

