#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using std::string;

void change_string(string s, string oldVal, string newVal)
{
	//changes matching substring of oldVal in s with newVal using iterators


	string::iterator first_char = s.begin();
	string::iterator oldVal_first_char = oldVal.begin();

	//make a copy of first_char, used for string replace operation
	string::iterator keep_track = first_char;


	while (first_char != s.end()){

		//if the first letter of the substr in s matches oldVal
		if ((*first_char) == (*oldVal_first_char)) {

			//update the iterator of oldVal
			++oldVal_first_char;
		}
		else {
			//if substr in s does not match oldVal, reset the iterator
			oldVal_first_char = oldVal.begin();
		}

		++first_char;


		//if the iterator for oldVal has reached its end, we have found a match to the substring
		if (oldVal_first_char == oldVal.end())   {

			//keep track of starting position of substr oldVal in s
			keep_track = first_char - oldVal.size();

			//replace substr between iterator keep_track and first_char with newVal
			s.replace(keep_track, first_char, newVal);

			//reset oldVal iterator again
			oldVal_first_char = oldVal.begin();

			//reset keep track back to current iterator position
			keep_track = first_char;
		}

}
	std::cout << s << std::endl;

}

void change_string_index(string s, string oldVal, string newVal)
{
	//changes matching substring of oldVal in s with newVal using array indicies


	int first_char = 0;
	int oldVal_first_char = 0;

	//make a copy of first_char, used for string replace operation
	int keep_track = first_char;

	//loop until we hit end of string
	while (first_char != s.size()-1) {

		//if the first letter of the substr in s matches oldVal
		if ((s[first_char]) == (oldVal[oldVal_first_char])) {

			//update the iterator of oldVal
			++oldVal_first_char;
		}
		else {
			//if substr in s does not match oldVal, reset the iterator
			oldVal_first_char = 0;
		}

		++first_char;


		//if the iterator for oldVal has reached its end, we have found a match to the substring
		if (oldVal_first_char ==( oldVal.size() -1)) {

			//keep track of starting position of substr oldVal in s
			keep_track = first_char - (oldVal.size()-1);

			//replace substr starting at keep_track with newVal
			s.replace(keep_track,oldVal.size(), newVal);

			//reset oldVal iterator again
			oldVal_first_char = 0;

			//reset keep track back to current iterator position
			keep_track = first_char;
		}

	}
	std::cout << s << std::endl;

}

std::string prefix_suffix(string name, string prefix, string suffix) {

	name = " " + name;
	suffix = " " + suffix;
	prefix.append(name);
	prefix.append(suffix);

	return prefix;
}

std::string prefix_suffix_insert(string name, string prefix, string suffix) {

	name = " " + name + " ";


	name.insert(0,prefix);
	name.insert(name.size(),suffix);

	return name;
}

void ex_9_5_2() {

	//ex_9_4_3
	string my_word = "thot thope thote thought thome";
	string oldVal = "tho";
	string newVal = "tha";

	//std::cout << *(my_word.begin()) << *(my_word.begin() + 1) << std::endl;
	change_string(my_word, oldVal, newVal);

	//ex_9_4_4
	change_string_index(my_word, oldVal, newVal);

	//ex_9_4_5
	string name = "bobby";
	string prefix = "Mr.";
	string suffix = "III";
	std:: cout<< prefix_suffix(name, prefix, suffix) <<std::endl;

	//ex_9_4_6
	std::cout << prefix_suffix_insert(name, prefix, suffix) << std::endl;
}

void ex_9_4_7() {
	string word = "ab2c3d7R4E6";
	string numbers = "0123456789";
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	std::vector<string::size_type> position_nums;
	std::vector<string::size_type> position_upper_alpha;
	std::vector<string::size_type> position_lower_alpha;

	string::size_type c = 0;
	
	//c consistently needs to be updated with the newest starting position
	while( (c = (word.find_first_of(numbers, c))) != string::npos) {
			position_nums.push_back(c);
			++c;
	}

	//reset c
	c = 0;
		
	while ((c = (word.find_first_of(alphabet, c))) != string::npos){
			position_lower_alpha.push_back(c);
			++c;
		}

	c = 0;
	while ((c = word.find_first_of(Alphabet, c)) !=string::npos) {
			position_upper_alpha.push_back(c);
			++c;
		}

	for (auto num : position_nums) {
		std::cout << num << " ";
	}

	std::cout<< std::endl;

	for (auto lower : position_lower_alpha) {
		std::cout << lower << " ";
	}

	std::cout << std::endl;

	for (auto upper : position_upper_alpha) {
		std::cout << upper << " ";
	}

	std::cout << std::endl;
}

string largest_word_without_descend_ascend(string fileName) {

	string ascend = "idfthklb";
	string descend = "qypgj";

	std::ifstream input(fileName);	//open the file as read mode

	std::string line,word;
	std::string largest_word;

	//continuously read line broken up by \n
	while (getline(input, line)) {

		//convert line to string stream to be broken up to words by whitespace
		std::istringstream string_stream(line);

		//reach each word from the line
		while (getline(string_stream, word, ' ')) {

			auto ascenders = word.find_first_of(ascend);
			auto descenders = word.find_first_of(descend);

			//do nothing if word has ascenders and descenders
			if (ascenders != string::npos) {
				//std::cout << word << " " << ascenders << std::endl;
				;
			}
			else if (descenders != string::npos) {
				//std::cout << word << " " << descenders << std::endl;
				;
			}
			//check if current largest word > next word.
			else {
				std::cout << word << std::endl;
				if (word.size() > largest_word.size()) {
					largest_word = word;
				}
			}
			//std::cout << word << std::endl;
		}
	}

		std::cout << largest_word << std::endl;

		return largest_word;
	}

int main_3() {

	//ex_9_5_2();
	//ex_9_4_7();

	largest_word_without_descend_ascend("test_words.txt");
	return 0;
}