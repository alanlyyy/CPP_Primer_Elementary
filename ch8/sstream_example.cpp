#include <iostream>
#include <string>
#include "C:\Users\Alan\Documents\Visual Studio 2019\Code Snippets\Visual C++\C++_Primer\7\Sales_data.h"
#include <fstream>
#include <vector>
#include <sstream>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;

struct PersonInfo {
	string name;
	vector<string> phones;
};

void sstream_ex_1(){
	string line, word;	//will hold a line and word from input, respectively.
	vector<PersonInfo> people; //will hold all the records from the input

	string text = "morgan 2015552368 8625550123\n drew 9735550130 97355501311112 \n lee 6095550132 2015550175 8005550000";
	std::istringstream string_stream(text); //using the string generate a string stream object.

	//read a string one line at a time from "text" string
	while (getline(string_stream, line)) {
		PersonInfo info;	//create an object to hold this records data

		std::istringstream record(line);	//bind record to the line we just read

		record >> info.name;	//read the name

		while (record >> word) {	//read the phone numbers
			info.phones.push_back(word);	//store phone numbers
		}
		people.push_back(info); //append this record to people.
	}

	for (vector<PersonInfo>::iterator start = people.begin(); start != people.end(); start++) {
		
		std::cout << (*start).name << " " << (*start).phones[0] <<std::endl;
	}

	for (const auto& entry : people) {		//for each entry in people
		std::ostringstream formatted, badNums;	//objects created on each loop

		for (const auto& nums : entry.phones) {
			 //for each number

			//if length of nums is not 10
			if (nums.length() != 10) {
				badNums << " " << nums;
			}
			else {
				//writes to formatted string 
				formatted << " " << nums;
			}
		}
		if (badNums.str().empty()) {
			//there were no bad numbers
			std::cout << entry.name << " "	//print the name
				<< formatted.str() << endl;	//and reformatted numbers
		}
		else {
			std::cerr << "input error: " << entry.name
				<< " invalid number (s) " << badNums.str() << endl;
		}
	}
}
void ex_8_3_1(std::string file_name) {
	std::ifstream input(file_name);	//open the file constructor create a new file

	std::vector<std::string> file_content;

	std::string line;

	//read from file - store contents in vector
	//continuously read line, until eof is reached 
	while (getline(input, line)) {

		//append line to vector of strings
		file_content.push_back(line);

		std::cout << line << std::endl;
	}

	auto start = file_content.begin();
	auto end = file_content.end();

	cout << endl;
	cout << endl;

	//iterate over entire vector and write out the contents
	while (start != end) {

		std::string word;

		//grab value from pointer, dereference pointer
		//cout << *start << endl;

		//pass entire string into string stream object
		std::istringstream record(*start);

		//break each word by " " in the string, print out word one at a time.
		while (record >> word) {
			cout << word << endl;
		}

		//update iterator
		start += 1;
	}

	//terminate file stream.
	input.close();
}

int main() {
	//ex_8_3_1("book_input.txt");
	sstream_ex_1();
	return 0;
}