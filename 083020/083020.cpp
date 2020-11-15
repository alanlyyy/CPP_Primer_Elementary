#include <iostream>
#include "C:\Users\Alan\Documents\Visual Studio 2019\Code Snippets\Visual C++\C++_Primer\1\Sales_item.h"
#include "C:\Users\Alan\Documents\Visual Studio 2019\Code Snippets\Visual C++\C++_Primer\Version_test.h"


void test1()
{
	//currVal is the number we are counting; we'll read new values into val
	int currVal = 0, val = 0;

	// read first number and ensure that we have data to process
	if (std::cin >> currVal)
	{
		//store the count for the current value we're processing.
		int cnt = 1;

		// read remaining numbers
		while (std::cin >> val)
		{
			//read first number and ensure that we have data to process
			if (val == currVal) {
				++cnt;
			}
			// prnt the count for the previous value
			else {
				std::cout << currVal << " occurs "
					<< cnt << " times" << std::endl;

				//remember the new value
				currVal = val;

				//reset the counter
				cnt = 1;
			}
		}
		//print the count for the last value in the file
		std::cout << currVal << " occurs "
			<< cnt << " times" << std::endl;
	}
}

void test2() {

	// Create a sales_item object called book
	Sales_item book;

	//read ISBN, number of copies sold, and sales price
	std::cin >> book;

	//write isbn, number of copies sold, total revenue, and average price
	std::cout << book << std::endl;
}

void test3() {

	//create 2 Sale_item objects
	Sales_item item1,item2;

	//take all inputs
	while (std::cin >> item1)
	{

		//add the 2 object parameters together
		// the "+" operator is overloaded in the Sales_item class
		item2 += item1;
		std::cout << item2 << std::endl;

		//reset the oject
		Sales_item item1;
	}
	std::cout << item2 << std::endl;
}
void test4() {

	//create 2 Sale_item objects
	Sales_item item1, item2;

	//read 8 inputs for 2 item objects
	std::cin >> item1 >> item2;

	//add the 2 object parameters together
	// the "+" operator is overloaded in the Sales_item class
	std::cout << item1 + item2 << std::endl;
}

int test5() {

	//initialize to item objects
	Sales_item item1, item2;

	//gather inputs for 2 item objects
	std::cin >> item1 >> item2;

	//first check that item1 and item2 represent the same book
	if (item1.isbn() == item2.isbn()) {
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	else {
		std::cerr << "Data must refer to same ISBN"
			<< std::endl;
		return -1; //indicate failure
	}
}
int main2()
{
	int sum = 0, value = 0;

	//read until end of file, calculating a running total of all values read

	while (std::cin >> value)
		sum += value;

	std::cout << "Sum is: " << sum << std::endl;

	return 0;
}

int main() {
	test5();
	return 0;

}