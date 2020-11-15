#include <iostream>
#include <string>
#include <vector>

struct Person {

	//friend declarations to use non members for Person class
	friend std::istream& read(std::istream& is, Person& item);
	friend std::ostream& print(std::ostream& os,const Person& item);

	private:
		std::string name;
		std::string address;
	public:
		//initialized constructor passing in parameters of name and address
		Person(const std::string&name, const std::string&address) : name(name), address(address){}

		Person() = default;	//default constructor

		//explicit call to default constructor
		//Person(const std::string&, const std::string&) : name(" "), address(" ") {}

		//declare constructor
		//Person(std::istream&);
		//read input to istream and initialize the parameters in the constructor.
		Person(std::istream& is) {
			read(is, *this);
		}

		//non member functions
		std::string get_name() const {
			//value of name is a const type, we cant change the value
			return name;
	}

		std::string get_address() const {
			//value of address is a const type, we cant change the value
			return address;
		}
};
//non member functions used by person class
std::ostream& print(std::ostream& os, const Person& item) {

	//pass in reference bound to Sales_data object, print contents of object.
	os << item.name << " " << item.address;

	return os;
}

std::istream& read(std::istream& is, Person& item)
{
	//read in input values
	std::cout << "name, address" << std::endl;
	is >> item.name >> item.address;

	return is;
}
int main3() {
	std::string s1 = "kyle";
	std::string s2 = "rittenhouse";

	Person p1 = Person(std::cin);
	Person p2 = Person(); //default constructor
	Person p3 = Person(s1,s2);

	std::cout << p1.get_name() << " "<<  p1.get_address() << std::endl;
	std::cout << p2.get_name() << " " << p2.get_address() << std::endl;
	std::cout << p3.get_name() << " " << p3.get_address() << std::endl;

	return 0;
}

