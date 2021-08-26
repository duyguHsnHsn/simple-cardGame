#include "Money.h"

void Money::turn_silver_to_gold() {
	if (this->myMoney.second > 99) {
		this->myMoney.first = this->myMoney.second / 100;
		this->myMoney.second = this->myMoney.second % 100;
	}
}
void Money::turn_gold_to_silver() {
	if (this->myMoney.first != 0) {
		this->myMoney.second += this->myMoney.first * 100;
		this->myMoney.first = 0;
	}
}
Money::Money() {
	this->myMoney.first = 0;
	this->myMoney.second = 0;
}
Money::Money(const int gold,const int silver) {
	set_gold(gold);
	set_silver(silver);
}
Money& Money :: operator=(const Money& second) {
	if (this != &second) {
		set_gold(second.get_gold());
		set_silver(second.get_silver());
	}
	return *this;
}
void Money::set_gold(const int gold) {
	this->myMoney.first = gold;
}
void Money::set_silver(const int silver) {
	this->myMoney.second = silver;
	turn_silver_to_gold();
}
void Money::add_silver(const int silver) {
	this->myMoney.second += silver;
	turn_silver_to_gold();
}
void Money::remove_silver(const int silver) {
	turn_gold_to_silver();
	if (this->myMoney.second >= silver) {
		this->myMoney.second -= silver;
	}
	else {
		std::cout << "Not enough money!\n";
	}
	turn_silver_to_gold();
}
void Money::add_gold(const int gold) {
	this->myMoney.first += gold;
}
void Money::remove_gold(const int gold) {
	if (this->myMoney.first >= gold) {
		this->myMoney.first -= gold;
	}
	else {
		std::cout << "Not enough gold!\n";
	}
}
int Money::get_gold() const{
	return this->myMoney.first;
}
int Money::get_silver() const{
	return this->myMoney.second;
}
string Money ::print () const{
	string helper;
	helper += "Gold: ";
	helper += std::to_string(this -> myMoney.first);
	helper += "    Silver: ";
	helper += std::to_string(this->myMoney.second);
	return helper;
}