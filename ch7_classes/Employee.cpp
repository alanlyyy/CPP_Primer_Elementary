#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

class Employee {
	friend std::istream& read(std::istream&, Employee&);
	friend std::ostream& print(std::ostream&, const Employee&);

	public:

		//define constructors
		Employee() = default;
		Employee(unsigned emp_id, std::string emp_status, double num_hours, unsigned emp_age, double emp_salary) :
			ID(emp_id), Employee_status(emp_status), hours_per_week(num_hours), age(emp_age), salary(emp_salary) {};
		Employee(std::istream&);

		//getters return copies of members of const type
		int get_ID() const {
			return ID;
		}

		std::string get_employee_status() const {
			return Employee_status;
		}

		double get_hours() const {
			return hours_per_week;
		}

		int get_age() const{
			return age;
		}

		double get_salary() const {
			return salary;
		}
	private:
		int ID= 0;
		std::string Employee_status= " ";
		double hours_per_week = 0;
		int age = 0;
		double salary= 0.0;
};


std::ostream& print(std::ostream& os, const Employee& emp) {

	//pass in reference bound to Sales_data object, print contents of object.
	os << emp.get_ID() << " " << emp.get_age() << " "
		<< emp.get_employee_status() << " " <<emp.get_hours() << " " << emp.get_salary();

	return os;
}

std::istream& read(std::istream& is, Employee& emp)
{
	//read in input values
	std::cout << "ID, Employment Status, hours worked per week, salary, age " << std::endl;
	is >> emp.ID >> emp.Employee_status>> emp.hours_per_week >> emp.salary >> emp.age;
	return is;
}

//Constructor that reads from standard input
Employee::Employee(std::istream& is) {
	read(is, *this);	//read will read a transaction from is into "this" object (itself)
}

void test_employee() {
	Employee e1 = Employee(std::cin);
	Employee e2 = Employee();
	Employee e3 = Employee(950123, "FTE", 40, 25, 67500);

	print(std::cout,e1);
	print(std::cout, e2);
	print(std::cout, e3);
}

int main50() {
	test_employee();
	return 0;
}