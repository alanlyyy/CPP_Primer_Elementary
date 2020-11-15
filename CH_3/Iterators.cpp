#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

void Interator_ex() {

	vector<int> nums = { 56, 70, 99, 54,2 };

	//begin declares first element in vector
	auto first = nums.begin();

	//end declares last element in vector
	//last points to the iterator object with value of 2
	auto last = nums.end() - 1;

	cout << *first << " " << *last << endl;

	string s("some string");

	if (s.begin() != s.end()) {
		// make sure s is not empty.

		//it is a pointer that points to beginning of object s
		auto it = s.begin();	//denotes first character in s

		//get the value of it which is the first character is object s
		//convert the first character to uppercase and reassign back to object s
		*it = toupper(*it);
	}

	s = "MyNameMing";
	//process characters in s until we run out of characters or we hit a white space.
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
	{
		*it = toupper(*it); // capitalize the current character
		cout << *it << endl;
	}
	vector<string> v;
	//auto it3 = v.cbegin(); //it3 has type vector<int>::const_iterator

	//(*it3).empty();	// dereferences it3 and calls the function empty() for the dereferenced string object.

	vector<string> text = { "MAGA", " ", "Trump2020", " ", "SleepyJoeBiden", " ", "ColbyCovington", " ",
							"Kim Klacik", " ", "Candace Owens" };

	//print each line in text up to the first blank line
	for (auto it = text.cbegin();
		it != text.cend() && !it->empty(); ++it)

		//dereference the string.
		cout << *it << endl;


	//to compute the iterator nearest the middle of the vector
	//auto mid = v.begin() + v.size() / 2;
}

int binary_search(vector<int> text, int sought)
{
	auto beg = text.begin(), end = text.end();
	auto mid = text.begin() + (end - beg)/2; // original midpoint

	//while there are still elements to look at and we havent yet found sought
	while (mid != end && *mid != sought)
	{
		if (sought < *mid)	//is there element we want in the first half
			end = mid;		//if so, adjust range to ignore the second half
		else
			beg = mid+1;		//the element we want is in the second half

		mid = beg + (end - beg) / 2;	//set the new midpoint
	}

	//if mid = sought return sought, if mid = end then return 0.
	return (*mid);
}
void ex_3_4_1() {
	//ex_3_21
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };

	for (auto i = v.begin(); i != v.end(); ++i)
	{
		//dereference i, square the value and set it to the dereferenced i
		*i = (*i) * (*i);
		cout << *i << endl;
	}

	//verify if the vector values in v were changed.
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		//dereference i, square the value and set it to the dereferenced i
		cout << *i << endl;
	}

	//ex_3.2
	vector<string> text = { "MAGA", " ", "Trump2020", " ", "SleepyJoeBiden", " ", "ColbyCovington", " ",
						"Kim Klacik", " ", "Candace Owens" };

	//print each line in text up to the first blank line
	for (auto it = text.begin();
		it != text.end() && !it->empty(); ++it)
	{
		//for each character in each line
		for (auto &jt : *it)
		{
			//change each letter to upper case
			jt = toupper(jt);
		}

		cout << *it << endl;
	}

	//ex 3_23
	vector<int> ten_elements;

	//add ten elements into the vector
	for (unsigned int i = 0; i < 10; ++i)
	{
		ten_elements.push_back(i);
	}

	//for each element in ten_elements double each value stored in the vector
	for (auto it = ten_elements.begin(); it != ten_elements.end(); ++it)
	{
		*it *= 2;
	}

	//for each element in ten_elements print each value stored in the vector
	for (auto it = ten_elements.begin(); it != ten_elements.end(); ++it)
	{
		cout << *it << endl;
	}

}
void ex_3_4_2() {
	//3.16 and 3.17
	string word;
	vector<string> words;

	//read input into words vector
	for (int i=0; i < 5; ++i)
	{
		cin >> word;
		words.push_back(word);
	}

	//using iterator iterate through entire vector and print word.
	for (auto it = words.begin(); it != words.end(); ++it)
	{	
		//for each character of word, change to upper case
		for (auto& c : *it)
			c = toupper(c);
		cout << *it << endl;
	}

	//grade clustering

	//count the number of grades by clusters of 10: 0to9,11to20,21to30,...,100
	vector<unsigned> scores(11, 0);	//11 buckets, all initally 0

	unsigned grade;

	while (cin >> grade)	//read the grades
	{
		if (grade <= 100)	//handle only valid grades
		{
			//go to the grade/10 position, dereference the iterator, and add 1 to the position
			*(scores.begin() + grade / 10) += 1;

			cout << *(scores.begin() + grade / 10) << endl;
		}
	}
}

int main_iterator() {

	//Interator_ex();
	//ex_3_4_1();

	vector<int> ele = {1,2,3,5,9,17, 44, 156, 900,12093 };
	
	cout << binary_search(ele, 99) << endl;

	//ex_3_4_2();
	return 0;
}