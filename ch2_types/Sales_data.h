//header guards ifdef and ifndef is used to prevent multiple inclusion of same header variables.
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

#endif