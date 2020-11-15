#include <iostream>
#include <string>
#include "C:\Users\Alan\Documents\Visual Studio 2019\Code Snippets\Visual C++\C++_Primer\7\Sales_data.h"
#include <fstream>
#include <vector>
std::istream& print5(std::istream& is) {
	
	std::string file_contents;

	while (is >> file_contents)
	{
		//print contents of input stream
		std::cout << file_contents << std::endl;

		//reset the input stream
		is.clear();
	}

	//return a reference to the stream
	return is;
}


void read_write() {

	//when passing in argv as input, ran into issues because i was not correctly passing in input file name and output file name.

	std::ifstream input("book_input.txt");	//open the file of sales transactions
	//std::ofstream output("book_output2.txt");	//open the write enabled output file
	std::ofstream output("book_output2.txt",std::ofstream::app);	//open the append enabled output file

	std::cout << "HERE" << std::endl;
	Sales_data total;				//variable to hold the running sum

	if (read(input, total)) {	//read first input
		Sales_data trans;		//variable to hold the next transaction

		while (read(input, trans)) {	//read the remaining transactions
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);	//update running total
			}
			else {
				print(output, total) << std::endl;	//print results/write results to output file/stream
				total = trans;						//process new book
			}
		}
		print(output, total) << std::endl;	//print the last transaction
	}
	else {
		std::cerr <<"No data?!" << std::endl;
	}
}

void read_write2(std::string ifile, std::string ofile) {

	std::ifstream in(ifile);	//constructor of an ifstream and open the given file.
	std::ofstream out;	//output file stream that is not associated with any file

	//check that open succeeded
	if (out)
		out.open(ifile + ".copy"); //open specified file

	in.close();		//close the file stream
	in.open(ifile + "2");	//open another file
}

void read_write_multi(std::vector< std::string>::iterator start, std::vector< std::string>::iterator stop)
{
	//pass in start pointer and stop pointer for vector<string> object that contain filenames
	for (auto p = start; p !=stop; ++p) {

		//create input and open the file
		std::ifstream input(*p);

		if (input) {
			std::cout<< *p << std::endl;
		}
		else {
			std::cerr << "couldn't open: " + std::string(*p);
		}
		std::cout<<std::endl;
	}
	
}

void ex_8_2_1(std::string file_name) {
	std::ifstream input(file_name);	//open the file constructor create a new file
	std::ifstream input2(file_name);//used for reading individual chars instead of lines

	std::vector<std::string> file_content;
	std::vector<std::string> file_content2;

	std::string line;

	//continuously read line, until eof is reached
	while (getline(input, line)) {

		//append line to vector of strings
		file_content.push_back(line);

		std::cout << line<<std::endl;
	}

	//continuously read word until empty space is detected
	while (getline(input2, line,' ')) {

		//append line to vector of strings
		file_content2.push_back(line);

		std::cout << line << std::endl;
	}

	auto start = file_content.begin();
	auto end = file_content.end();
	
	std::cout << std::endl;
	std::cout << std::endl;

	//iterate over entire vector and write out the contents
	while (start != end) {

		//grab value from pointer, dereference pointer
		std::cout << *start <<std::endl;

		//update iterator
		start += 1;
	}

	//terminate file stream.
	input.close();
}


int main4() {

	read_write();
	std::vector< std::string> filenames = { "book_input.txt", "book_input2.txt", "book_input3.txt" };
	std::vector< std::string>::iterator start = filenames.begin();
	std::vector< std::string>::iterator stop = filenames.end();

	//read_write_multi(start, stop);
	//ex_8_2_1("book_input.txt");

	return 0;
}