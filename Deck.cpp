#include "Deck.h"
#include <exception>

Deck::Deck(const string& name) : name(name) {}
string Deck::get_name()const {
	return this->name;
}
Deck::Deck(const Deck& from) {
	this->copy_clones(from.myCards);
	this->name = from.name;
}
Deck& Deck :: operator=(const Deck& to) {
	if (this != &to) {
		this->clear_deck();
		this->copy_clones(to.myCards);
		this->name = name;
	}
	return *this;
}
void Deck::add_card(const MagicCard* const new_one) {
	this->myCards.push_back(new_one->clone());
}
void Deck::add_card(const MonsterCard* const new_one) {
	this->myCards.push_back(new_one->clone());
}
void Deck::add_card(const PendulumCard* const new_one) {
	this->myCards.push_back(new_one->clone());
}
void Deck::set_name(const string& name) {
	this->name = name;
}
void Deck::change_card(const int index, const MagicCard* const new_one) {
	for (unsigned int i = 0; i < this->myCards.size(); i++) {
		if (i == index) {
			MagicCard* ptr = dynamic_cast<MagicCard*>(myCards[i]);
			if (ptr) {
				this->myCards.erase(this->myCards.begin() + index);
				this->myCards.insert(this->myCards.begin() + index, new_one->clone());
				ptr = nullptr;
				break;
			}
				throw std :: invalid_argument( "Mismatch of card types. \n");
			}
		}
	
}
void Deck::change_card(const int index, const MonsterCard* new_one) {
	for (unsigned int i = 0; i < this->myCards.size(); i++) {
		if (i == index) {
			MonsterCard* ptr = dynamic_cast<MonsterCard*>(myCards[i]);
			if (ptr) {
				this->myCards.erase(this->myCards.begin() + index);
				this->myCards.insert(this->myCards.begin() + index, new_one->clone());
				ptr = nullptr;
				break;
			}
			else {
				throw std::invalid_argument("Mismatch of card types. \n");
			}
		}
	}
}
bool Deck::is_card_pendulum(Card* card)const {
	PendulumCard* ptr1 = dynamic_cast<PendulumCard*>(card);
	if (ptr1) {
		return true;
	}
	return false;
}
void Deck::change_card(const int index, const PendulumCard* new_one) {
	for (unsigned int i = 0; i < this->myCards.size(); i++) {
		if (i == index) {
			if (is_card_pendulum(myCards[i])) {
				this->myCards.erase(this->myCards.begin() + index);
				this->myCards.insert(this->myCards.begin() + index, new_one->clone());
				break;
			}
			else {
				throw std::invalid_argument("Mismatch of card types. \n");
			}
		}
	}
}
int Deck::get_magic_card_count()const {
	int counter = 0;
	for (unsigned int i = 0; i < this->myCards.size(); i++) {
		MagicCard* ptr = dynamic_cast<MagicCard*>(myCards[i]);
		if (ptr) {
			if (is_card_pendulum(myCards[i])) {
				continue;
			}
			else {
				counter++;
			}
		}
	}
	return counter;
}
int Deck::get_monster_card_count()const {
	int counter = 0;
	for (unsigned int i = 0; i < this->myCards.size(); i++) {
		MonsterCard* ptr = dynamic_cast<MonsterCard*>(myCards[i]);
		if (ptr) {
			if (is_card_pendulum(myCards[i])) {
				continue;
			}
			else {
				counter++;
			}
		}
	}
	return counter;
}
int Deck::get_pendulum_card_count()const {
	return this->myCards.size() - (get_monster_card_count() + get_magic_card_count());
}
int Deck::get_all_cards_count()const {
	return this->myCards.size();
}
Deck :: ~Deck() {
	this->clear_deck();
}
void Deck::clear_deck() {
	for (auto p : myCards)
	{
		delete p;
	}
	this->myCards.clear();
}
void Deck::shuffle() {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine rng(seed);
	std::shuffle(this->myCards.begin(), this->myCards.end(), rng);
}
string Deck::substring(const string& from, const int& index, int starting) {
	string substring;
	while (starting != index) {
		substring += from[starting];
		starting++;
	}
	return substring;
}
Card* Deck::get_card(const int index) const {
	return this->myCards[index];
}
void Deck::copy_clones(const vector<Card*> other_cards) {
	for (const auto* Cards : other_cards) {
		this->myCards.push_back(Cards->clone());
	}
}
ostream& operator<<(ostream& output, const Deck& to_print) {
	output << to_print.name << '|' << to_print.get_all_cards_count() << '|' << to_print.get_monster_card_count() << '|' << to_print.get_magic_card_count() << '|' << to_print.get_pendulum_card_count();
	output << "\n";
	for (unsigned int i = 0; i < to_print.myCards.size(); i++) {
		MonsterCard* ptr = dynamic_cast<MonsterCard*>(to_print.myCards[i]);
		if (ptr) {
			if (to_print.is_card_pendulum(to_print.myCards[i])) {
				continue;
			}
			else {
				output << *(ptr);
				output << "\n";
			}
		}
	}
	for (unsigned int i = 0; i < to_print.myCards.size(); i++) {
		MagicCard* ptr = dynamic_cast<MagicCard*>(to_print.myCards[i]);
		if (ptr) {
			if (to_print.is_card_pendulum(to_print.myCards[i])) {
				continue;
			}
			else {
				output << *(ptr);
				output << "\n";
			}
		}
	}
	for (unsigned int i = 0; i < to_print.myCards.size(); i++) {
		PendulumCard* ptr1 = dynamic_cast<PendulumCard*>(to_print.myCards[i]);
		if (ptr1) {
			output << *(ptr1);
			output << "\n";
		}
	}
	return output;
}
istream& operator>>(istream& input, Deck& to_write) {
	to_write.clear_deck();
	string whole_line;
	int overall_count = 0;
	int monsterCount = 0;
	int magicCount = 0;
	int pendulumCount = 0;
	int counter_for_lines = 0;
	while (getline(input, whole_line)) {
		if (counter_for_lines == 0) {
			int index = 0;
			int counter = 0;
			for (unsigned int i = 0; i < whole_line.size(); i++) {
				if (whole_line[i] == '|' && counter == 0) {
					to_write.name = to_write.substring(whole_line, i, index);
					counter++;
					index = i + 1;
				}
				else if (whole_line[i] == '|' && counter == 1) {
					overall_count = stoi(to_write.substring(whole_line, i, index));
					index = i + 1;
					counter++;
				}
				else if (whole_line[i] == '|' && counter == 2) {
					monsterCount = stoi(to_write.substring(whole_line, i, index));
					index = i + 1;
					counter++;
				}
				else if (whole_line[i] == '|' && counter == 3) {
					magicCount = stoi(to_write.substring(whole_line, i, index));
					index = i + 1;
					counter++;
				}
				else if (counter == 4) {
					pendulumCount = stoi(to_write.substring(whole_line, whole_line.size() + 1, index));
					break;
				}
			}
			counter_for_lines++;
		}
		else {
			counter_for_lines++;
			if (counter_for_lines > 1 && counter_for_lines <= 1 + monsterCount) {
				MonsterCard new_one;
				stringstream(whole_line) >> new_one;
				to_write.add_card(&new_one);
			}
			if (counter_for_lines > 1 + monsterCount && counter_for_lines <= 1 + monsterCount + magicCount) {
				MagicCard new_one;
				stringstream(whole_line) >> new_one;
				to_write.add_card(&new_one);
			}
			if (counter_for_lines > 1 + monsterCount + magicCount && counter_for_lines <= 1 + monsterCount + magicCount + pendulumCount) {
				PendulumCard new_one;
				stringstream(whole_line) >> new_one;
				to_write.add_card(&new_one);
			}
		}
	}
	return input;
}