#include <stack>
#include <deque>
#include <string>
#include <iostream>
#include <vector>

void stack_example() {
	std::deque<int> deq = { 0,2,3,4,5 };
	std::stack<int> stk(deq);	//copies elements from deq into stk

	//empty stack implemented on top of a vector
	std::stack<std::string, std::vector<std::string>> str_stk;


	std::vector<std::string> svec = { "0", "AB", "ABC" };

	//str_stk2 is implemented on top of vector and initially holds a copy of svec
	std::stack<std::string, std::vector<std::string>> str_stk2(svec);

	std::stack<int> intStack; //empty stack

	//fill up the stack
	for (size_t ix = 0; ix = 10; ++ix) {
		intStack.push(ix);	//intStack holds 0 ... 9 inclusive
	}

	while (!intStack.empty()) {
		//while there are still values in the stack

		//peek at top of the stack
		int value = intStack.top();

		intStack.pop(); //pop the top element, and repeat
	}
}