#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <string>


void example() {

	std::vector<int> vec = { 0,1,2,42,3,5,67,8 };
	int val = 42; //value we are looking for

	//result will denote the element we want if its in vec or vec.cend() if not
	auto result = std::find(vec.cbegin(), vec.cend(), val);

	//report the result
	std::cout << "The value " << val
	<< (result == vec.cend() ? " is not present" : " is present")
	<< std::endl;

	std::string valSTR = "a value"; //value we are loking for

	std::vector<std::string> lst = {"ABC", "a value", "BCD", "dog" };
	auto result2 = find(lst.cbegin(), lst.cend(), valSTR);

	std::cout << *result2;
}

int main() {
	example();
	return 0;
}