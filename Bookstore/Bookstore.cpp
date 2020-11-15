#include <iostream>
#include "C:\Users\Alan\Documents\Visual Studio 2019\Code Snippets\Visual C++\C++_Primer\1\Sales_item.h"

int main()
{
	//variable to hold data for next transaction
	Sales_item total;

	// read the first transaction and ensure that there are data to process
	if (std::cin >> total)
	{
		//variable to hold the running sum
		Sales_item trans;

		//read and process the remaining transactions
		while (std::cin >> trans)
		{
			//if we are still processing the same book
			if (total.isbn() == trans.isbn())
			{
				//update the running total
				total += trans;
			}
			else
			{
				//print results for the previsou book
				std::cout << total << std::endl;

				//total now refers to the next book
				total = trans;
			}
		}

		// print the last transaction
		std::cout << total << std::endl; 
	}

	else {

		//no input found warns user
		std::cerr << "No data ?!" << std::endl;

		//incident failure
		return -1;
	}

	return 0;


}