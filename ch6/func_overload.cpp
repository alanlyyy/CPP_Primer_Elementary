#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void f() {
	cout << "Default Void" << endl;
}

void f(int num) {
	cout << "One argument Int: " << num << endl;
}

void f(int num1, int num2) {
	cout << "Two arguments Int: " << num1 << " " << num2 << endl;
}

void f(double num1, double num2) {
	cout << "Two arguments Double: " << num1 << " " << num2 << endl;
}

int main() {
	f();
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);

	char t = 'x', v = 'y', text = 'b';

	//low level const
	const char* p1 = "a";	//We cannot change the value of the object p1 points to.
							//equivalent to  " const char * p1 "

	//top level const
	char* const p2 = &t;	//We cannot change the object p2 points to, p2 points to t forever

	//p2 = &text; //Error - We cannot change the object p2 points to

	p1 = &v;	//p1 points to object v
	//*p1 = 'd';	//Error - we cannot change the value of object p1 points to.
	cout << *p2 << " " << *p1 << endl;

	return 0;
}