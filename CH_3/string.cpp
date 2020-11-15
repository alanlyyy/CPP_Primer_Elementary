#include <iostream>
#include "C:\Users\Alan\Documents\Visual Studio 2019\Code Snippets\Visual C++\C++_Primer\1\Sales_item.h"

//using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
using std::cout; 
using std::endl;
using std::string;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

void ex_1() {
	//using statement std::cin only
	int i;

	cin >> i; //cin is a synonum for std::cin
	//cout << i; //error no 'using' declaration; we must use full name.
	std::cout << i; //explicitly use cout from namespace std
}

void ex_2() {
	//'using statement from std::endl, std::cout , and std::cin
	cout << "Enter two numbers:" << endl;
	int v1, v2;
	cin >> v1 >> v2;

	cout << "The sum of " << v1 << " and " << v2
		<< " is " << v1 + v2 << endl;
}

void exercise_3_1() {

	//pt 1
	int sum = 0, val = 1;

	while (val <= 10) {
		sum += val;
			++val;
	}
	cout << "Sum of 1 to 10 inclusive is " << sum
		<< endl;

	//pt2
	double price = 0;

	Sales_data data1, data2;

	cin >> data1.bookNo >> data1.units_sold >> price;

	data1.revenue = data1.units_sold * price;
	cout << " Revenue: " << data1.revenue << endl;

	cin >> data2.bookNo >> data2.units_sold >> price;
	cout << " Revenue: " << data2.revenue << endl;
}

void strings_ex() {
	string s1;	//default initialization empty string

	string s2 = s1; // s2 is a copy of s1

	//copy form initialization
	string s3 = "hiya"; //s3 is a copy of string literal

	//direct initialization omit = sign
	string s4(10, 'c'); // s4 is ccccccccccc, initialize s4 10 copies of c

	string s5 = "hiya"; //copy initialization
	string s6("hiya"); //direct initialization 
	string s7(10, 'c'); //direct initialization; s7 is ccccccc
	
	string s8 = string(10, 'c'); //direct initialization; s7 is cccccccccc
	// == 
	string temp(10, 'c'); //temp is cccccccc
	s8 = temp; // copy temp into s8

	// if input is Hello World! Output is  'Hello' leading and trailing whitespaces are dropped 
	string s; //empty string
	cin >> s; //read a whitespace-separate string into s
	cout << s << endl; // write s to the output

	//if input is Hello World! Output is 'HelloWorld!'
	string s10, s20;
	cin >> s10 >> s20; //read first input into s1, second into s2
	cout << s10 << s20 << endl; //write both strings

	string word;
	//while (cin >> word) //read until end of file
	//	cout << word << endl;	//write  each word followed by a new line

	string line;
	// read input a line at a time until end of files is detected
	while (getline(cin, line))
		//print string withs 80 characters or more
		if (line.size() > 80)
			cout << line << endl;
		else
			cout << "line" << " too short. " << endl;

	//get size of string line, declare type for len during compile time
	//len has type string::size_type
	auto len = line.size();

	//string comparison rules
	string str = "Hello"; //str is less than phrase
	string phrase = "Hello World";
	string slang = "Hiya"; //slang, Hi vs He is greater than str and phrase
	
	string st1(10, 'c'), st2; //st1 is cccccccccc ; st2 is empty string
	st1 = st2; //assignment replace contents of st1 with copy of st2, both st1 and st2 are empty strings.

	//string concatenation
	s1 = "hello, ", s2 = "world\n";
	s3 = s1 + s2; //s3 is hello world\n
	s1 += s2; //equivalent to s1 = s1 +s2 or hello world\n

	s1 = "hello", s2 = "world";
	s3 = s1 + ", " + s2 + "\n";

	//string concatenation with literal works, literal to literal concatenation does not work.
	s4 = s1 + ", "; //ok adding a string and literal
	//string s5 = "hello" + ", " ; //error no string operand
	s6 = s1 + ", " + "world"; //each + has a string operand
	//string s7 = "hello" + ", " + s2;//error can't add string literals

}

void ex_3_2_2() {

	//ex_1 read one word at a time, cin breaks up white space
	string line, s1, s2;
	int count = 0;
	while (count < 1) {
		cin >> line;
		cout << line << endl;
		count += 1;
	}

	//read to strings verify if strings are equal if not report the larger string
	getline(cin, s1);
	getline(cin, s2);

	if (s1 > s2)
		cout << s1 << endl;
	else if (s2 > s1)
		cout << s2 << endl;
	else
		cout << (s1 == s2) << endl;

	getline(cin, s1);
	getline(cin, s2);

	auto len1 = s1.size();
	auto len2 = s2.size();

	if (len1 > len2)
		cout << len1 << endl;
	else if (len2 > len1)
		cout << len2 << endl;
	else
		cout << (len1 == len2) << endl;

	//create a sentence using standard input and string concatenation
	int button = 2;

	if (button == 1)
	{
		string sentence;
		while (cin >> line) {
			sentence += line + " ";
			cout << sentence << endl;
		}
	}
	else if (button == 2)
	{
		string str("some string");
		//prints the characters in str one character to a line
		for (auto c : str) //for every char  c in a str
			cout << c << endl;
	}

	//range for loop example
	string s("Hello World!!!");

	//punct_Cnt has the same type that s.size returns string::sizetype
	decltype(s.size()) punct_cnt = 0;

	//count the number of punctuation characters in s
	for (auto c : s)	//for every char in s
	{
		if (ispunct(c))	// if the character is punctuation

			++punct_cnt; //increment the punctuation counter

		cout << punct_cnt
			<< " punctuation characters in " << s << endl;
	}


	//Using references to change value of object in for loop

	//for every char in s (c is bound to a character in s)
	for (auto& c : s)

		//change the character in s to upper case
		c = toupper(c);

	cout << s << endl;

	//check if the string is empty, before printing the first letter of the string
	s = "some string";

	if (!s.empty())

		//change first letter to upper case.
		s[0] = toupper(s[0]);
	cout << s[0] << endl;

	//process characters in s until we run out of characters or we hit a whitespace

	//index = string::sizetype
	for (decltype(s.size()) index = 0;
		(index != s.size() && !isspace(s[index])); ++index)

		//capitalize the current character
		s[index] = toupper(s[index]);

	cout << s << endl;
}

void calc_hexdigits()
{
	const string hexdigits = "0123456789ABCDEF"; //possible hex digits

	cout << "Enter a series of numbers between 0 and 15"
		<< "Enter a series of numbers between 0 and 15"
		<< "separated by spaces. Hit ENTER when finished: "
		<< endl;

	//holds the result hexified string
	string result;

	//hold numbers from the input
	string::size_type n;

	while (cin >> n)
	{
		//ignore values greater than 15 and less than 0
		if (n < hexdigits.size())

			//fetch the indicated hex digit
			result += hexdigits[n];

		cout << "Your hex number is: " << result << endl;
	}

	}

void ex_3_2_3() {

	//ex 3.6
	string s(5,'d');

	cout << s << endl;

	for (auto &c : s) {
		c = 'X';
	}
	cout << s << endl;

	//ex3.7
	s = string(5, 'd');

	for (char & c : s) {
		c = 'X';
	}
	cout << s << endl;

	//ex3.8

	//reinitialize string s
	s = string(5, 'd');

	cout << s << endl;

	//__while loop configuration__
	//c is a reference bound to string s
	string& c = s;
	string::size_type count = 0;
	while (count < s.size())
	{	
		//for each character in s, change to X
		c[count] = 'X';
		//update counter variable.
		++count;
	}

	cout << s << endl;

	// use traditional for loop
	s = "MyType";
	cout << s << endl;

	for (decltype(s.size()) index = 0;
		(index < s.size()); ++index)
	{
		//for each character in s, change to X
		s[index] = 'X';
	}
	cout << s << endl;

	//ex3.9
	string sentence = "My name is earl, I like cats.";

	cout << "Before: " <<  sentence << endl;
	//iterate entire string and find all punctuations
	for (char& c : sentence) {
		if (ispunct(c))
		{
			//remove the punctuation with white space.
			c = ' ';
		}
	}
	cout << "After: " << sentence << endl;
}

int main2() {

	//ex_2();
	//exercise_3_1();
	//strings_ex();
	//ex_3_2_2();

	//calc_hexdigits();
	ex_3_2_3();
	return 0;
}