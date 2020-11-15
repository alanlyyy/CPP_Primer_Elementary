#include <iostream>
#include <string>
//#include "Sales_data.h"

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int Sales_data_operation() {
	Sales_data data1, data2;

	double price = 0; //price per book used to calculate total revenue

	//read first transactions: ISBN, number of books sold, price per book
	std::cin >> data1.bookNo >> data1.units_sold >> price;

	//calculate total reveue from price and units sold
	data1.revenue = data1.units_sold * price;

	//read second transaction
	std::cin >> data2.bookNo >> data2.units_sold >> price;

	//calculate revenue of second transacction
	data2.revenue = data2.units_sold * price;

	//if both transactions contain the same bookNo
	if (data1.bookNo == data2.bookNo) {

		unsigned totalCnt = data1.units_sold + data2.units_sold;

		double totalRevenue = data1.revenue + data2.revenue;

		std::cout << data1.bookNo << " " << totalCnt << " "
			<< " " << totalRevenue << " ";

		//if total units sold is greater than 0 price the cost/unit
		if (totalCnt != 0)
			std::cout << totalRevenue / totalCnt << std::endl;
		else
			std::cout << "(no sales )" << std::endl;
		
		//indicate success
		return 0;
	}
	else {
		//error transactions were not the same
		std::cerr << " Data must refer to the same ISBN"
			<< std::endl;
		
		//indicate failure
		return -1;
	}
}

int main() {
	Sales_data_operation();
	return 0;
}