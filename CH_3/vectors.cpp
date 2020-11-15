#include <iostream>
#include <vector>

//using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void vector_ex_3_3_2() {

	//ex 3.14
	vector<int> nums;
	vector<string> text;
	int val;
	string word;

	//read in numbers from std input
	while (cin >> val)
	{
		//add val to nums vector
		nums.push_back(val);
	}

	//ex 3.15
	while (cin >> word)
	{
		//add word to text vector
		text.push_back(word);
	}


	for (int c : nums)
		cout << c << endl;

	for (char c : word)
		cout << c << endl;

}

void vector_ex_3_3_3() {
	//ex3.16
	vector<vector<int>> vec_of_vec;
	vector<vector<string>> vec_of_vec_str;
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string> v6{ 10 };
	vector<string> v7{ 10, "hi" };

	vec_of_vec = { v1,v2,v3,v4,v5 };
	vec_of_vec_str = { v6, v7 };

	for (vector<int> vec_int : vec_of_vec)
	{
		for (int i : vec_int)
		{
			cout << i;
		}
		cout << endl;
	}

	for (vector<string> vec_str : vec_of_vec_str)
	{
		for (string i : vec_str)
		{
			cout << i;
		}
		cout << endl;
	}
	//ex3.17
	vector<string> sentence;

	//read in words and store into vector sentenace
	for (unsigned int index = 0; index < 5; ++index)
	{
		string word;
		cin >> word;
		sentence.push_back(word);
	}

	//iterate over each word in sentence list and change characters to uppercase.
	for (string word : sentence)
	{
		//c is a reference to each character in word
		for (char& c : word) {

			//change each character to upper case
			c = toupper(c);
		}
		cout << word << endl;
	}

	//ex3.19 3 ways to assign 10 values of 42 to a int vector.
	vector<int> num_ten(10,42);	//
	num_ten = { 42,42,42,42,42,42,42,42,42,42 };
	num_ten = {};
	for (int i = 0; i < 10; ++i)
	{
		num_ten.push_back(42);
	}
	
	//ex3.20

	//reads in 5 numbers from std input
	vector<int> store_int;

	for (int i=0; i < 10; ++i)
	{
		unsigned int num;
		cin >> num;
		store_int.push_back(num);
	}

	int button = 1;

	if( button == 0)
	{
		//iterate through each number in the vector and add the adjacent numbers.
		for (decltype(store_int.size()) i = 0; i < store_int.size(); ++i)
		{
			if (i == 0)
			{
				cout << store_int[i] + 0 << endl;
			}
			else
				cout << store_int[i] + store_int[i - 1] << endl;
		}
	}
	else {
		//iterate through each number in the vector and add the first and last numbers.
		for (decltype(store_int.size()) i = 0; i < (store_int.size()/2); ++i)
		{
			cout << store_int[i] + store_int[store_int.size()-1-i] << endl;
		}
	}
}
void vector_examples() {

	//default intialization of a vector with no elements.
	vector<int> ivec;	//ivec holds objects of type int
	//vector <Sales_item> Sales_vec; //holds objects of type Sales_items
	vector<vector<string>> file; // vector whose elements are vectors

	//initialize some values for ivec
	ivec = { 0,1,3,4 };

	vector<int> ivec2(ivec); //copy elements of ivec into ivec2
	vector<int> ivec3 = ivec; //copy elements of ivec into ivec3

	//print each number from ivec2
	for (auto i : ivec2)
		cout << i << endl;

	//print each number from ivec3
	for (auto i : ivec3)
		cout << i << endl;

	//vector<string> svec(ivec2); -- incompatability error: svec holds string objects, while ivec holds int objects

	//list initialization
	vector<string> articles = { "a", "an", "the" };

	vector<string> v1{ "a", "an", "the" };
	//vector<string> v2("a", "an", "the"); // error must use curly braces

	ivec= vector<int>(10, -1);		//ten int elements, each initalized to -1

	vector<string> svec(10, "hi");	//ten strings; each element is "hi!"

	ivec = vector<int>(10);	//10 elements, each initialized to 0
	svec = vector<string>(10);	//10 elements, each an empty string.

	//different ways to initialize vectors
	vector<int> v10(10);		//v1 has ten elements with value 0
	vector<int> v2{10};		//v2 has one element with value 10
	vector<int> v3(10, 1);	//v3 has ten elements with value 1
	vector<int> v4{ 10, 1 };//v4 has 2 elements with values 10 and 1

	vector<string> v5{ "hi" };	//list initialization: v5 has one element
	//vector<string> v6("hi");	//error: can't construct a vector from a string literal

	vector<string> v7{ 10 };	//v7 has ten default initialized elements of empty string
	vector<string> v8{ 10, "hi" };	//v8 has ten elements with value "hi'
	
	//print every value in v7
	for (auto& string : v7)
		cout << string << endl;

	//print every value in v8
	for (auto& string : v8)
		cout << string << endl;

	vector<int> v20;	//empty vector
	for (int i = 0; i != 100; ++i)
		v20.push_back(i);	///append sequential integers to v2 to end of vector
	//at end of the loop v2 has 100 elements, values 0 .. 99

	//append word from std input to vector 
	string word;
	vector<string> text;	//empty vector
	while (cin >> word) {
		text.push_back(word);	//append word to text
	}
}
void vector_examples_2()
{
	//count the number of grades by clusters of 10: 0to9,11to20,21to30,...,100
	vector<unsigned> scores(11, 0);	//11 buckets, all initally 0

	unsigned grade;

	while (cin >> grade)	//read the grades
	{
		if (grade <= 100)	//handle only valid grades
			++scores[grade / 10];	//increment the counter for current cluster
	}
}
int main5() {
	//vector_examples();

	vector_ex_3_3_3();
	return 0;
}