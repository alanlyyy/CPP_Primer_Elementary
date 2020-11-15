#include <iostream>
#include <list>
#include <deque>
#include <vector>

void ex_9_2() {
	std::list<std::deque<int>>;
}

bool ex_9_2_1(std::vector<int>::iterator begin , std::vector<int>::iterator end, int num) {
	//iterate over vector, if current iterator value == num, return true.

	bool found = 0;

	while (begin != end) {

		if ((*begin) == num) {
			found = 1;
			break;
		}
		else {
			begin++;
		}
	}

	return found;
}

std::vector<int>::iterator return_iterator (std::vector<int>::iterator begin, std::vector<int>::iterator end, int num) {

	//iterate over vector, return iterator of requested element.

	while (begin != end) {

		if ((*begin) == num) {
			break;
		}
		else {
			begin++;
		}
	}
	return begin;
}

void ex_() {
	std::list<std::string> a = { "Milton", "Shakespeare", "Austen" };

	auto it1 = a.begin();	//list<string>::iterator
	auto it2 = a.rbegin();	//list<string>::reverse_iterator
	auto it3 = a.cbegin();	//list<string>::const_iterator
	auto it4 = a.crbegin();	//list<string>::const_reverse_iterator
}