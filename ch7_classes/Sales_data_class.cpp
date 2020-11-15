#include <iostream>
#include <string>
#include <vector>

struct Sales_data {
	//addded access specifier
	//add default constructor

	//friend declarations for nonmembers of Sales_data_2 class, operations added.
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);

	public:

		Sales_data() = default;

		//explicitly initialize bookNo with std::string&s, units_sold and revenue are default initialized to 0
		Sales_data(const std::string& s) : bookNo(s) {}

		//equivalent to Sales_data(const std::string&s): bookNo(s),units_sold(0), revenue(0) {}
		//explicitly initialize  bookNo with s , units_sold with n, and initialize revenue with p*n
		Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p* n) {}

		Sales_data(std::istream &);

	//------------------------------------------------------

		// new members : operations on Sales_data objects
		std::string isbn() const {
			//value of bookNo is a const type, we cant change the value
			return bookNo;
		}
		Sales_data& combine(const Sales_data&);

		//default constructor initialized to default in class values
		Sales_data(std::string&, unsigned, double) : bookNo(" "), units_sold(0), revenue(0.0) {}
	
		double avg_price() const;

		double get_revenue() const {
			return revenue;
		}
		
		unsigned get_units_sold() const{
			return units_sold;
		}

		bool get_flag() const {
			return flag;
		}

	private:
		//data members are unchanged from 2.6.1
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;

		//stop transactions == 1
		bool flag = 0;	
};

//non member Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
//input transactions contain ISBN, number of copies sold, and sales price
std::istream& read(std::istream&, Sales_data&);

std::ostream& print(std::ostream& os, const Sales_data& item) {

	//pass in reference bound to Sales_data object, print contents of object.
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();

	return os;
}

std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;

	//read in input values
	std::cout << "continue?, bookNo, units_sold, price" << std::endl;
	is >> item.flag >> item.bookNo >> item.units_sold >> price;


	item.revenue = price * item.units_sold;

	return is;
}


Sales_data::Sales_data(std::istream& is) {
	read(is, *this);	//read will read a transaction from is into "this" object (itself)
}

//member functions of class Sales_data defined outside the class
inline double Sales_data::avg_price() const {
	//revenue is a const type that only has read level priviledges
	//cannot modify any objects of Sales_data
	if (units_sold) {
		return revenue / units_sold;
	}
	else {
		return 0;
	}
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	//pass in reference bound to Sales_data object with read only priviledges
	//add transactions to 'this' object.

	units_sold += rhs.units_sold;	//add members of rhs into members of this
	revenue += rhs.revenue;	//add members of rhs to the members of this object
	return *this;	//return the object on which the function was called.
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;	//copy data members from lhs into sum
	sum.combine(rhs);		//add data members from rhs into lhs
	return sum;				//return Sales_data object of the sum of lhs and rhs.
}


void constructor_practice() {
	//using 3 parameter constructor
	Sales_data S1 = Sales_data("123-ABC", 5, 1.99);

	//use default constructor
	Sales_data S2 = Sales_data();

	//use 1 parameter constructor, default initialized revenue and units_sold
	Sales_data S3 = Sales_data("123-CCC");

	//initializing constructor reading inputs from input stream
	Sales_data S4 = Sales_data(std::cin);

	std::cout << S1.isbn() << " " << S1.get_units_sold() << " " << S1.get_revenue() << std::endl;
	std::cout << S2.isbn() << " " << S2.get_units_sold() << " " << S2.get_revenue() << std::endl;
	std::cout << S3.isbn() << " " << S3.get_units_sold() << " " << S3.get_revenue() << std::endl;
	std::cout << S4.isbn() << " " << S4.get_units_sold() << " " << S4.get_revenue() << std::endl;

}

void transaction_program_with_constructor() {

	//added a flag to Sales_data class to keep track of stop condition for program.
					//variable to hold the running sum

	Sales_data total = Sales_data(std::cin);

	if (total.get_flag() != 1) {		// read the first transaction, if bookNo is empty skip if statement.
		
		Sales_data trans = Sales_data(std::cin);				// variable to hold data for the next transaction

		while (trans.get_flag() != 1) {	//read the remaining transactions as long as bookNo is not empty, and flag != 1

			if (total.isbn() == trans.isbn()) {	//update running total
				total.combine(trans);
			}
			else {
				print(std::cout, total) << std::endl;		//print total
				total = trans;	//reset total to new transaction
				
				//total = trans is equivalent to
				//total.bookNo = trans.bookNo;
				//total.units_sold = trans.units_sold;
				//total.revenue = trans.revenue;
			}
			trans = Sales_data(std::cin);	//process the next book

		}
		print(std::cout, total) << std::endl;			//print the last transaction
	} else{
		std::cerr << "No data?!" << std::endl;			//notify the user
	}
}
void transaction_program() {

	//added a flag to Sales_data class to keep track of stop condition for program.
					//variable to hold the running sum

	Sales_data total;
	if (read(std::cin, total)) {		// read the first transaction, if bookNo is empty skip if statement.
		Sales_data trans;				// variable to hold data for the next transaction

		while (read(std::cin, trans)) {	//read the remaining transactions as long as bookNo is not empty, and flag != 1

			if (total.isbn() == trans.isbn()) {	//update running total
				total.combine(trans);
			}
			else if (trans.get_flag() == 1) {
				break;
			}
			else {
				print(std::cout, total) << std::endl;		//print the results
				total = trans;								//process the next book
			}

		}
		print(std::cout, total) << std::endl;			//print the last transaction
	}
	else {
		std::cerr << "No data?!" << std::endl;			//notify the user
	}
}
int main2() {
	transaction_program_with_constructor();
	constructor_practice();
	return 0;
}