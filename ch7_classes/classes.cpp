#include <iostream>
#include <string>
#include <vector>

class Sales_data_2 {
	//class is declared because we use private access specifiers: public and private
	//struct is used when only public specifiers are used.

	//friend declarations for nonmembers of Sales_data_2 class, operations added.
	friend Sales_data_2 add(const Sales_data_2&, const Sales_data_2&);
	friend std::istream& read(std::istream&, Sales_data_2&);
	friend std::ostream& print(std::ostream&, const Sales_data_2&);

public:
	Sales_data_2() = default;
	Sales_data_2(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) { }
	Sales_data_2(const std::string& s) : bookNo(s) {}
	Sales_data_2(std::istream&);
	std::string isbn() const { return bookNo; }
	Sales_data_2& combine(const Sales_data_2&);
private:
	double avg_price() const {
		return units_sold ? revenue / units_sold : 0;
	}
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

class Sales_data_3 {
	friend std::istream& read(std::istream&, Sales_data_3&);
	friend std::ostream& print(std::ostream&, const Sales_data_3&);
public:
	//non delegating constructor initializes members from corresponding arguments
	Sales_data_3(std::string s, unsigned cnt, double price) :
		bookNo(s), units_sold(cnt), revenue(cnt* price) {};

	//remaining constructors all deletegate to another  constructor
	Sales_data_3() : Sales_data_3("", 0, 0) {}	//calling default constructor "delegates to constructor that initializes Sales_data_3 to "", 0, 0
	Sales_data_3(std::string s) : Sales_data_3(s, 0, 0) {} // delegates to constructor that assigns bookNo to s while units_sold and revenue are 0 
	Sales_data_3(std::istream &is) : Sales_data_3()	//delegates to default constructor.
	{
		read(is, *this);
	}

private:
	double avg_price() const {
		return units_sold ? revenue / units_sold : 0;
	}
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//declarations for non member parts of the Sales_data_2 interface
Sales_data_2 add(const Sales_data_2&, const Sales_data_2&);	//add returns a Sales_data_2 type object
std::istream& read(std::istream&, Sales_data_2&);
std::ostream& print(std::ostream&, const Sales_data_2&);
