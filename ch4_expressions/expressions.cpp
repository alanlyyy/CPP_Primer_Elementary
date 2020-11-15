#include <iostream>
#include <vector>
#include <string>

//using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void ex_4_1_2() {

	//left to right associativity
	//multiplication and division comes before addition and subtraction.
	//multiplication comes before division in this case due to left to right associativity.
	cout << (5 + 10 * 20 / 2) <<' ' << ( (5 + 10 * 20 / 2) == 105 )<< endl;
}

void ex_4_2() {

	//ex4.4
	cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;
	cout << (((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2) << endl;

	//ex4.5
	cout << " a. " << -30 * 3 + 21 / 5 << ' ' << "-90 + 4 = -86 " << endl;
	cout << "b. " << -30 + 3 * 21 / 5 << ' ' << " -30 + 63/5 = -18 " << endl;
	cout << "c. " << 30 / 3 * 21 % 5 << ' ' << " (10 *21) % 5 == 0" << endl;
	cout << "d. " << -30 / 3 * 21 % 4 << ' ' << " (-10 *21) % 4 == -2" << endl;

	//ex4.6
	int val;
	cin >> val;

	if ((val % 2) == 0) {
		cout << "Even" << ": " << val <<endl;
	}
	else if (val == 0) {
		cout  << val << endl;
	}
	else {
		cout << "Odd:" << val << endl;
	}



}

void ex_4_3() {

	//constantly read a num until 42 is reached.
	int num = 0;

	while (num != 42) {
		cin >> num;
		cout << num << ' ';
	}
	cout << endl;

	int a=5, b=4, c=45, d=2;

	cout << " (a > b) && (b > c) && (c > d): " << ((a > b) && (b > c) && (c > d)) << endl;
}

void ex_4_4() {
	//4.13
	int i;
	double d;
	d = i = 3.5;
	cout << d << ' ' << i << "|| " << "3, 3" << endl;
	i =d = 3.5;
	cout << i << ' ' << d << "|| " << "3, 3.5" << endl;
}

void lesson() {
	int ival, jval=36;
	ival = jval = 0;	//set ival and jval to 0.
	cout << ival << ' ' <<  jval;

	int * pval; //ival is an int; pval is a pointer to int
	//ival = pval = 0; //error cannot assign the value of a pointer to an int

	string s1, s2;
	s1 = s2 = "OK";	//string literal "OK" converted to string

	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto pbeg = vi.begin();

	//print elements up to the first negative value
	while ((pbeg != (vi.end())) && (*pbeg >= 0))
	{
		cout << *(pbeg++) << endl;
	}

	string s = "Hello world!";

	//capitalize the first word in the input as long as not last char or space.
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
	{
		//dereference value of it and convert to upper case and set to value of it
		*it = toupper(*it);
	}

	for (char& c : s) {
		cout << c << ' ';
	}

	string s5 = "a string", * p = &s5;

	auto n = s5.size();	//run the size member of the string s1
	n = (*p).size();	//run size on the object to which p points to &s1
	n = p->size();	//equivalent to (*p).size()

	//run the size member of p, then dereference the result
	//*p.size();		//error p is a pointer and has no member named size no parenthesis.

	//conditional operator
	int grade = 79;
	string finalgrade = (grade < 60) ? "fail" : "pass";
	cout << grade << endl;

	//nested conditional operator
	// check is grade > 90, if not then check grade < 60
	finalgrade = (grade > 90) ? "high pass"
		: (grade < 60) ? "fail" : "pass";

	//bit wise shift left
	unsigned num = 3;
	num = num << 3;	//bit wise shift num left by 3 bits // 00000011 -> 00011000 = 24
	cout << num << endl;

	//bit wise shift right
	num = 80;	//01010000
	num = num >> 3; //00001010 == 10
	cout << num << endl;

	//bit wise not operator
	cout << ~num;	//11111111-11111111-11111111-11110101 

	int arrB[] = { 0,1,2,3,4,5,6,7,8,9 };

	//get the size of the array, total size of all elements in array / size of first element in array
	constexpr size_t sz = sizeof(arrB) / sizeof((*arrB));

	cout << sz << endl;

	int arr2[sz] = { 0 };	//create an array of sz elements default initialized to 0

	for (int num : arr2)
		cout << num << ' ';
	cout << endl;

	vector<int> ivec  ( 10,0 ); //initialize ivec to 10 0's
	vector<int>::size_type cnt = ivec.size();

	//assign values from size.. 1 to the elements in ivec
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;

	for (int num : ivec)
		cout << num << ' ';


	int iz[10];	//array of 10 ints
	int* ip = iz;	//implictly convert iz to a pointer to first element

	int j = 5, i = 3;
	double slope = static_cast<double>(j) / i;	//cast j explicitly to double
}
void ex_4_10() {
	//ex4.31 using postfix increment and decrement

	vector<int> ivec(10, 0); //initialize ivec to 10 0's
	vector<int>::size_type cnt = ivec.size();

	//assign values from size.. 1 to the elements in ivec
	for (vector<int>::size_type ix = 0; ix < ivec.size(); ix++, cnt--)
		ivec[ix] = cnt;

	for (int num : ivec)
		cout << num << ' ';

	cout << endl;


	//casting
	void* p = &ivec[0];	// address of any non const object can be stored in a void*

	//converts void * back to the original pointer type
	double* dp = static_cast<double*>(p);

	const char* pc;
	char* d = const_cast<char*>(pc);	//p is undefined


	const char* cp;
	//char* q = static_cast<char*>(cp);	//error static_cast cannot cast away const type
	static_cast<string>(cp);	//converts string literal to string
	//const_cast<string>(cp);	//error const_cast only changes const-ness

	int* ip;
	char* dc = reinterpret_cast<char*>(ip);



}

void ex_4_11_3(){

	//4.37
	int i; double d; const string* ps; char* pc; void* pv;

	//a
	pv = (void*)ps;
	pv = const_cast<string*>(ps);	//remove "const" from ps, -> string* ps
	pv = static_cast<void*>(pv);	//convert string* to void* -> void* ps

	//b
	i = int(*pc);
	i = static_cast<int>(*pc);//convert char pointer to int pointer

	//c
	pv = &d;
	pv = static_cast<void*>(&d);	//convert the address of d to void pointer

	//d. 
	pc = (char*)pv;
	pc = static_cast<char*>(pv);	//convert pv to char*


}

void ex_4_8() {
	unsigned long ul1 = 3, ul2 = 7;
	cout << (ul1 & ul1) << endl; //00000011 & 00000111 == 00000011 (3)
	cout << (ul1 | ul2) << endl; //00000111 (7)
	cout << (ul1 && ul2)<< endl; // true
	cout << (ul1 || ul2) << endl; //true

}

void ex_4_7() {

	//ex 4.21
	vector<int> nums = { 0,1,2,3,4,5,6,7,8,9 };

	for (auto it = nums.begin(); it < nums.end(); ++it)
	{
		//if number is odd, dereference iterator and multiply value by 2
		//if even, keep value the same
		*it = (!(*it % 2) == 0) ? (*it) * 2 : *it;
	}

	for (int &num : nums)
		cout << num << ' ';

	//ex 4.22
	//conditional operator
	int grade = 84;
	string finalgrade = (grade < 60) ? "fail" : "pass";
	cout << grade << endl;
	//nested conditional operator
	// check is grade > 90, if not then check grade < 60
	finalgrade = (grade > 90) ? "high pass"

		: ((grade > 60) && (grade < 75)) ? "low pass" : 
		(grade < 60) ? "fail" : "pass";

	cout << grade << ' ' << finalgrade << endl;

}
void ex_4_9() {

	//ex 4.28
	cout << sizeof(int) <<' '; //4 bytes
	cout << sizeof(char) << ' '; // 1 byte 
	cout << sizeof(long) << ' '; //8 bytes
	cout << sizeof(bool) << ' '; //1 byte
	cout << sizeof(short) << ' '; //2 bytes
	cout << endl;

	//ex4.29
	int x[10]; int* p = x;
	cout << sizeof(x) << ' ' << sizeof(*x) << ' '<< sizeof(x) / sizeof(*x) << endl;	
	//size of entire array of ints x, 10 ints * 4 bytes, divided by size of first element in array 4 bytes, result is 10 ints

	cout << sizeof(p) << ' ' << sizeof(*p) << ' ' << sizeof(p) / sizeof(*p) << endl; 
	// size of object located at address of p 4 bytes,  divided by first element in array x 4 bytes , 1

}
int main() {
	ex_4_7();
	ex_4_8();
	ex_4_9();
	ex_4_10();
	lesson();
	ex_4_11_3();
	return 0;
}