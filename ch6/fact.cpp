//hold function definitions used for factMain.cpp
#include "Chapter6.h"

float abs_num(float num) {
	//return absolute value of number
	return std::abs(num);
}

void call_fact() {
	int num;

	cout << "Please enter a number to convert to factorial: " << endl;
	cin >> num;
	cout << fact(num) << endl;
}
int fact(int val) {
	//factorial function, val !
	int num = 1;
	while (val > 1)
	{
		num *= val--;
	}
	return num;
}
void swap(int *num1, int *num2) {
	//pass 2 pointers, store the dereferenced values of the pointers, and swap the values of both pointers.
	cout << "Before: " <<  *num1 << " " << *num2 << endl;
	int temp1 = *num1;	//store value of num1
	int temp2 = *num2;	//store value of num2

	*num1 = temp2;	//swap num2 with num1
	*num2 = temp1; //swap num1 with num2

	cout << "After: " <<  *num1 << " " << *num2 << endl;
}

bool isShorter(const string& s1, const string& s2) {
	//take 2 strings passed by reference and find the larger string.
	return s1.size() < s2.size();
}

string::size_type find_char(const string& s, char c, string::size_type& occurs)
{
	//returns the index of the first occurence of c in s
	//the reference parameter occurs counts how often c occurs

	auto ret = s.size();	//position of the first occurence, if any
	occurs = 0;	//set the occurence count parameter


	//iterate over entire string
	for (decltype(ret) i = 0; i != s.size(); ++i) {
		
		//if the current index of the string == char c
		if (s[i] == c) {
			
			//if ret is at the end of the string
			if (ret == s.size()) {

				//record first occurence of c
				ret = i;
			}
			//update num occurence counter
			++occurs;
		}
	}
	return ret;	//count is returned implicitly in &occurs
}

void reset(int& num) {
	
	//takes a integer reference and set the value of bound object to 0;
	num = 0;
}

void swap_ref(int& num1, int& num2) {
	//pass 2 references, store the values of bound objects, and swap the values of both bound objects.
	cout << "Before: " << num1 << " " << num2 << endl;
	int temp1 = num1;	//store value of num1
	int temp2 = num2;	//store value of num2

	num1 = temp2;	//swap num2 with num1
	num2 = temp1; //swap num1 with num2

	cout << "After: " << num1 << " " << num2 << endl;
}

int factorial(int val) {
	if (val > 1) {
		return factorial(val - 1) * val;
	}
	return 1;
}