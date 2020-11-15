#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "Chapter6.h"
//using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;

int ex_my_func(string c, int d) {
	cout << c << ' ' << d;
	return 0;
}
int factor(int val) {
	//factorial function, val !
	int num = 1;
	while (val > 1)
	{
		num *= val--;
	}
	return num;
}
void call_fact_2() {
	int num;

	cout << "Please enter a number to convert to factorial: " << endl;
	cin >> num;	
	cout << fact(num) << endl;
}

float abs_num_2(float num) {
	//return absolute value of number
	return std::abs(num);
}

size_t count_calls()
{
	static size_t ctr = 0;	//value will persist across calls
	return ctr++;
}
int main_squeeze() {
	//call_fact();

	//the static variable holds the value of count_calls until program terminates.
	for (size_t i = 0; i != 11; i++)
	{
		cout << count_calls() << endl;
	}
	return 0;
}