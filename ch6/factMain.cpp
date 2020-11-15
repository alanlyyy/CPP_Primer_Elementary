#include "Chapter6.h" 
#include <initializer_list>
#include <vector>
//declaring header includes function declarations found in Chapter6.h 
//Chapter6.h links the header definitions with the function declarations to main
using std::initializer_list;
using std::vector;

bool check_upper(const string& s) {

	for (char c : s) {

		//if upper case leeter found return true otherwise keep iterating.
		if ((int)c > 64 || (int)c < 91) {
			return 1;
		}
	}
	return 0;
}

void change_lower(string &s) {
	//change the value of all chars in string s to lower case.
	for (decltype(s.size()) i = 0; i < s.size(); ++i ) {

		s[i] = tolower(s[i]);
	}
}

int sizer(int num1, const int* num2) {
	//compares the dereferenced value of a pointer which pointer points to  with an integer
	//return the bigger value
	
	if (num1 > * num2) {
		return num1;
	}
	else {
		return *num2;
	}
}

void ptr_swap(int* ptr1, int* ptr2) {

	//print address and value of pointers before swap
	cout << "ptr 1: " <<ptr1 << " " << *ptr1 << endl;
	cout << "ptr 2: " <<ptr2 << " " << *ptr2 << endl;

	//initialize temporary pointers to hold pointers
	int* temp1 = ptr1, *temp2 = ptr2;

	//ptr1 now points to ptr2
	ptr1 = temp2;

	//ptr2 now points to ptr1
	ptr2 = temp1;
	//print address and value of pointers after swap
	cout << "ptr 1: " << ptr1 << " " << *ptr1 << endl;
	cout << "ptr 2: " << ptr2 << " " << *ptr2 << endl;
}

void print(int num) {
	cout << num << endl;
}
void print(int *arr, size_t s) {
	//overloaded print function

	//print all values in the array starting at index 0
	for (int i = 0; i < s; i++) {
		cout << *(arr+i) << " ";
	}
	cout << endl;
}

void error_msg(initializer_list<string> il) {
	
	//il acts like a vector
	for (auto beg = il.begin(); beg != il.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
}

int sum_list(initializer_list<int> nums) {

	int running_total = 0;
	for (const int* index = nums.begin(); index != nums.end(); ++index) {
		running_total += *index; //dereference value and add to running total.
	}
	return running_total;
}

char& get_val(string& str, string::size_type ix) {
	return str[ix];	//get_val assumes the given index is valid
}

int& get(int* arry, int index) {
	//ex6.32 pass in array pointer which points to 0th index of arry
	//return a reference to pointer to arry at  index
	return arry[index]; 
}

string recursive_vec(vector<string>::iterator beg, vector<string>::iterator end) {
	//recursively iterate through vector and combine all elements into a single string.
	if (beg != end) {
		return (*beg) + ' ' + recursive_vec((beg + 1), end);
	}
	return "\n";
}

string &arrRef(string g[]){
	//accepts a pointer to an arr 10 strings, returns first element of array
	return *g;
}

void ex_6_3_3() {
	//function declaration
	string arr1[8];
	string arr2[] = { "bill","barr", "jill", "julio", "michael", "tyrone", "mahjid","plies" };
	cout << arrRef(arr2 + 1) << endl;	//arrRef returns a reference to array of 5 strings

	//type alias
	string (arrRef(arr2));


	//declaration using decltype 
	decltype(arr1)& arrRef(arr2);

	//trailing return type
	//auto arrRef(arr2)->string (&)[8];
}
int ff(int a, int b = 0, int c = 0) {
	return a;
}

char* init(int ht, int wd = 80, char bckgrnd = ' ') {
	//default parameter intialization is legal because the default parameters are at the end of the parameter list.
	return &bckgrnd;
}

void make_plural(string word, char plural = 's') {
	cout << word << ' ' << (word + plural) << endl;
}
void ex_6_5_1() {
	//ex 6.4
	cout << ff(3)<<endl;

	//cout << init() << endl; //error because ht is missing a default parameter
	cout << init(24, 10);
	cout << init(14, '*');	// legal but may lead to unexpected outcome for user. '*' will be converted to ascii code 
	cout << endl;

	//6.42
	make_plural("tomohawk missle");
}

inline string isShorter(string str1, string str2) {
	//compiler converts this inline function to  str1.size() >str2.size() ? str1 : str2;
	if (str1.size() > str2.size()) {
		return str1;
	}
	else {
		return str2;
	}
}

void print2(const int ia[], size_t size) {
	//this code only executes if NDEBUG header is not defined. #define NDEBUG skips code
#ifndef NDEBUG
	//__func__ is a local static defined by the compiler that holds the functions name
	std::cerr << __func__ << ": array size is " << size << endl;

	//sample error message using compile time string literals used in debugging.
	if (sizeof(ia)/sizeof(ia[0]) != size) {
		std::cerr << "Error: " << __FILE__
			<< " : in function " << __func__
			<< " at line " << __LINE__ << endl
			<< " num read was \"" << *ia
			<< "\": Length too short" << endl;
	}
#endif
}
string recursive_vec_debug(vector<string>::iterator beg, vector<string>::iterator end) {
	//recursively iterate through vector and combine all elements into a single string.
	if (beg != end) {

		//run debug code, if NDEBUG is off.
		#ifndef NDEBUG


		std::cerr << "File: " << __FILE__
			<< " : in function " << __func__
			<< " at line " << __LINE__ << endl
			<< " num read was \"" << *beg
			<< "\": Length too short" << endl;

		#endif

		return (*beg) + ' ' + recursive_vec((beg + 1), end);
	}
	return "\n";
}
void ex_6_5_3() {
	vector<string> my_str = { "bill","barr", "jill", "julio", "michael", "tyrone", "mahjid","plies" };
	cout << recursive_vec_debug(my_str.begin(), my_str.end());
}

int main2() {
	//call_fact();
	
	cout << fact(5) << endl;
	cout << abs_num(-3.0) << endl;
	//call_fact();

	int i = 64, n = 26;
	int* p = &i;	//p points to address of i
	int* q = &n;	//q points to address of n
	cout << "i: " << i << " n: " << n << endl;

	swap(p, q);	//pass p and q pointers to compute the swap

	cout << "i: " << i << " n: " << n << endl;

	//swap i and n using pass by references
	swap_ref(i, n);

	cout << "i: " << i << " n: " << n << endl;

	//pass by reference example
	const string s = "ooeooffop";
	string::size_type ctr=0;

	//s is passed in as reference, ctr is passed in as reference.
	cout <<s << " "<< ctr << endl;
	cout << "First index of occurence: " << find_char(s, 'a', ctr) << endl;
	cout << "Occurences: " << ctr << endl;

	//pass k into function, pass by reference creates an invisible object bound to k
	//changing the value of k to 0
	int k = 35;
	reset(k);
	cout << " k: " << k << endl;



	//pass by reference example
	
	const string j = "Billy Bob";
	string d = "JoHn DoE";	//earlier we accidentally reinitialized variable k, which was an int, to a string
	//after changing the variable name the code worked normally.

	cout << check_upper(j) << endl;
	cout << d << endl;
	change_lower(d);
	cout <<"lower case: " <<  d << endl;

	int num1 = 5, num3 = 36;
	const int *num2 = &num3;	//num2 points to num3

	cout << "Expected: " << *num2 << " Actual: " <<  sizer(num1, num2) << endl;

	//pointer swapping
	int* num4 = &num1, * num5 = &num3;
	ptr_swap(num4, num5);

	int m[] = { 0,1 };
	print(k);
	print(m, 2);

	//------------using initializer list --------------------------------------
	//passing in initializer list to hold const value parameters
	string b;
	getline(cin,b);

	if (b == "bear") {
		error_msg({ "functionX", "bear", b });
	}
	else {
		error_msg({ "functionX", "okay" });
	}

	//function calls and lvalues
	string st("a value");
	cout << st << endl;	//prints a value
	get_val(st, 0) = 'A';	//get_val is a reference bound to the 0th index of st, change the 0th index of st to A
	cout << st << endl;


	//recursion
	cout << factorial(5)<<endl;

	int arry[10];
	//for each index of arry, get the reference of each index and change the value of arry index bound by reference.
	for (int i = 0; i != 10; ++i)
	{
		get(arry, i) = i;
		cout << arry[i] << " " ;
	}
	vector<string> my_str = { "bill","barr", "jill", "julio", "michael", "tyrone", "mahjid","plies" };
	cout << recursive_vec(my_str.begin(), my_str.end());

	//ex_6_3_3();

	ex_6_5_1();

	//print2(arry, 5);
	ex_6_5_3();
	
	return 0;
}