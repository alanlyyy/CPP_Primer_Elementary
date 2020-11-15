#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

//using declaration; when we use the name cin, we get the one from the namespace std
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::runtime_error;

void lesson() {
	//use case of a null statement 
	char sought = 'b';
	char s;
	while (cin >> s && s != sought)
	{
		;//a null statement similar to 'pass' in python
	}
	//empty block is equivalent to a null statement
	//while (cin >> s && s != sought)
	//{

//}

int ival = 3, v1 = 5, v2 = 6;

//this is equivalent to 
//ival =v1+v2 ;
// ;
ival = v1 + v2;; // second semicolon is null statement

vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
vector<int> grades = { 45,50,70,68,90,76,81,80,85,83,72,63,61,60 };
string lettergrade;
for (auto grade = grades.begin(); grade != grades.end(); ++grade)
{
	//append lettergrade
	if (*grade < 60) {
		lettergrade = scores[0];
	}
	else {
		lettergrade = scores[(*grade - 50) / 10];
	}
	//append + or - sign depending on grade if grade > 60%
	if (!(*grade < 60))
	{

		if (*grade % 10 > 7) {
			lettergrade += '+';
		}
		else if (*grade % 10 < 3) {
			lettergrade += '-';

		}
	}
	cout << *grade << " " << lettergrade << endl;
}
cout << endl;

//initialize counters for each vowel 
unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

char ch;

while (cin >> ch) {
	//if ch is a vowel, increment the appropriate counter
	switch (ch) {
	case 'a':
		++aCnt;
		break;
	case 'e':
		++eCnt;
		break;
	case 'i':
		++iCnt;
		break;
	case 'o':
		++oCnt;
		break;
	case 'u':
		++uCnt;
		break;
	}
}
cout << "Number of vowel a: \t" << aCnt << '\n'
<< "Number of vowel e: \t" << eCnt << '\n'
<< "Number of vowel i: \t" << iCnt << '\n'
<< "Number of vowel o: \t" << oCnt << '\n'
<< "Number of vowel u: \t" << uCnt << endl;


//count any occurence of vowels
unsigned vowelCnt = 0;

//count occurence of non vowels
unsigned otherCnt = 0;
while (cin >> ch) {
	//if ch is a vowel, increment the appropriate counter
	switch (ch) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		++vowelCnt;
		break;
	default:
		++otherCnt;
		break;
	}
}
string rsp;	//used in the condition; can't be defined inside the do

//run the loop once, if following iteration is not empty continue.
do {

	cout << "please enter two values: ";
	int val1 = 0, val2 = 0;
	cin >> val1 >> val2;
	cout << " The sum of " << val1 << " and " << val2
		<< " = " << val1 + val2 << "\n\n"
		<< "More? Enter yes or no: ";
	cin >> rsp;
} while (!rsp.empty() && rsp[0] != 'n');

}
void ex5_3_2() {
	//ex5.1
		//initialize counters for each vowel 
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, blnk = 0, space = 0, newtab = 0, newline = 0;

	//read a stream of data up to 25 characters
	string ch;



	//program accounts for uppercase + lowercase letters by forcing all letters to lower case
	while (getline(cin,ch)) {
		//force ch to lower case, if ch is a vowel, increment the appropriate counter
		if (((int(ch[0]) - 65) < 27) || (int(ch[0]) - 97) < 27){
		ch = tolower(ch[0]);
		}
		switch (ch[0]) {
		case 'a':
			++aCnt;
			break;
		case 'e':
			++eCnt;
			break;
		case 'i':
			++iCnt;
			break;
		case 'o':
			++oCnt;
			break;
		case 'u':
			++uCnt;
			break;
		case ' ':
			++blnk;
			break;
		case '\t':
			++newtab;
			break;
		case '\n':
			++newline;
			break;
		}
		cout << ch << ' ';
	}
	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << '\n'
		<< "Number of vowel space: \t" << blnk << '\n'
		<< "Number of vowel tab: \t" << newtab << '\n'
		<< "Number of vowel newline: \t" << newline << endl;

}
void ex_5_3_1() {
	//ex 5.6

	vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	vector<int> grades = { 45,50,70,68,90,76,81,80,85,83,72,63,61,60 };
	string lettergrade;

	for (auto grade = grades.begin(); grade != grades.end(); ++grade)
	{

		//if letter grade < 60 == F, else grade depends on position of vector
		lettergrade = (*grade <60) ? scores[0] : scores[(*grade - 50) / 10];

		//if letter grade 0,1,2 = '-' , 7,8,9 = '+'
		lettergrade += (*grade < 60) ? ' ' :
						(*grade % 10 > 7) ? '+' : 
							(*grade % 10 < 3) ? '-' : ' ';

		cout << *grade << " " << lettergrade << endl;
	}
	cout << endl;

	//ex5.7


}
void ex_5_4_1() {
	string ch;
	vector<string> words;

	//count largest number of repititions
	int maxcnt = 0;
	int rep_cnt = 1;

	while (getline(cin, ch)) { 
		words.push_back(ch);
	}

	//iterate through entire vector
	for (auto word = words.begin(); word != words.end();  ++word) {

		//if first index update word and continue
		if (word == words.begin())
		{
			continue;
		}

		//if not first index
		else {

			//compare previous word with current word, if words are equal update local repitition count 
			if (*word == *(word - 1)) {
				++rep_cnt;
			}
			else {

				if (rep_cnt > maxcnt)
				{
					//update the new  absolute max count number of repititions
					maxcnt = rep_cnt;
				}

				//reset the counter for local max count of repitions
				rep_cnt = 1;
			}

		}
	}

	cout << "Absolute Maxima of total repittions" << maxcnt << endl;
}

void ex_5_4_2() {
	vector<int> nums1 = { 0,1,1,2 };
	vector<int> nums2 = { 0,1,1,2,3,5,8 };
	int min_size;
	int nums1_sz = sizeof(nums1) / sizeof(nums1[0]);
	int nums2_sz = sizeof(nums2) / sizeof(nums2[0]);

	if (nums1_sz < nums2_sz)
	{
		min_size = nums1_sz;
	}
	else {
		min_size = nums2_sz;
	}

	bool flag = true;

	//iterate over the smaller size vector, if all elements are equal to all elements in bigger vector
	//prefix is true, if not prefix is false.
	for (auto i = 0; i < min_size; ++i)
	{
		if (nums1[i] == nums2[i])
		{
			continue;
		}
		else {
			flag = false;
			break;
		}
	}
	cout << flag << " ";
}

void ex_5_4_3() {
	//compare 2 words to se which word is bigger

	do {
		string word1, word2;
		cout << "Please enter 2 words: " << endl;
		cin >> word1 >> word2;
		
		int len_word1 = word1.length();
		int len_word2 = word2.length();
		if (len_word1 > len_word2) {
			cout << "Word 1 is Bigger " << len_word1;
		}
		else {
			cout << "Word 2 is Bigger " << len_word2;
		}

		cout << "Continue? Y/N";
	} while (cin);
}
void ex_5_5_1() {
	string word, prev_word = " ";
	vector<string> words;
	
	//read in all words, break if \n detected
	while (1) {

		getline(cin, word);

		if (word.empty()) {
			break;
		}

		//only look at words that contain upper case letters for first case.
		if (word[0] != toupper(word[0]))
		{
			continue;
		}
		words.push_back(word);
	}

	//iterate through container of words and find duplicate words in succession.
	for (string w: words){

		if (prev_word == " ") {
			prev_word = w;
			continue;
		}
		else {
			if (w == prev_word) {
				cout << w << " " << prev_word << endl;
				break;
			}
			else {
				prev_word = w;
			}
		}
		//if we are at the last word dereference to get the last word
		if (w == *(words.end()-1)) {
			cout << "No word was repeated." << endl;
		}
	}
}
void ex5_6_3() {
	int num1, num2;

	int flag = 1;

	//throwing an exception
	if (flag == 0) {
		while (cin >> num1 >> num2) {

			if (num2 != 0) {
				cout << num1 / num2 << endl;
			}
			else {
				throw runtime_error("Divide by 0 error.");
			}
		}
	}
	else {
		//exception handling with try - catch block
		while (cin >> num1 >> num2) {
			
			try {
				cout << num1 / num2 << endl;
			}
			catch (std::exception) {
				cout << "Divide by 0 Error!" << endl;
			}
		}
	}
}
int main() {
	//lesson();
	//ex5_3_2();

	//ex_5_4_3();
	//ex_5_5_1();
	ex5_6_3();
	return 0;
}