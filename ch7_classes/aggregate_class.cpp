#include <iostream>
#include <string>
#include <vector>

struct Data {
	int ival;
	std::string s;
};

struct Sales_data_4 {
	std::string bookNo;
	unsigned units_Sold = 0;
	double revenue = 0.0;
};
void test_agg_class() {

	//initialize data members of aggregate class by providing a braced list of member initializers
	Data val1 = { 0, "Anna" };	//val.ival = 0, val.s = string("Anna")

	//Data val2 = { "Anna", 1024 };	--error cant use Anna to initialize ival, or 1024 to initialize s

	Sales_data_4 item = { "978-0590353403", 25, (15.99*25) };

	std::cout << item.bookNo << " " << item.units_Sold << " " << item.revenue<<std::endl;

}

class Debug {
	//constexpr means we can compile code in compile time.
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

	constexpr bool any() {
		return hw || io || other;
	}

	void set_io(bool b) {
		io = b;
	}

	void set_hw(bool b) { hw = b; }

	void set_other(bool b) { hw = b; }

private:
	bool hw, io, other;
};

class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);

	//member functions can use static members directly, without the scope operator
	void calculate() { amount += amount * interestRate; }

private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
	static constexpr int period = 30;	// period is a constant expression
	double daily_tbl[period];	//daily_tbl is an array of 30 elements, period is a const cannot be changed.
};

//accessing static member functions inside or outside the class body.
void Account::rate(double newRate) {
	interestRate = newRate;
}

int main() {
	test_agg_class();

	Debug io_sub(false, true, false);	//debuging io
	Debug prod(false);	//no debugging during production

	if (io_sub.any()) {
		//equivalent to if true
		std::cerr << "print appropriate error messages" << std::endl;
	}

	if (prod.any())	//equivalent to if(false)
	{
		std::cerr << "print an error message" << std::endl;
	}


	//access a static member directly through the scope operator
	double r;
	r = Account::rate();	//access a static member using the scope operator

	Account ac1;
	Account* ac2 = &ac1;

	//equivalent ways to call the static member rate function
	r = ac1.rate();		//through an account object or reference
	r = ac2->rate();	//through a pointer to an account object
	return 0;
}