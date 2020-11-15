#include <iostream>
#include <string>
#include <vector>

struct X {
	friend void f() {//friend function can be defined in the class body
		;
	}

	X(int i, int j) : base(i), rem(i% j) {}

	//X() { f(); } // error no declaration for f
	void g();
	void h();

	int rem, base;

};

//void X::g() { return f(); } // error f hasn't been declared
void f();	//declares the function defined inside X
void X::h() { return f();  } // declaration for f is now in the scope

class ConstRef {
public:
	ConstRef(int ii);
private:
	int i;
	const int ci;
	int& ri;
};

//wrong way to write this constructor, because const type ci and int& ri was not initialized in the class 
//cannot assign ci, and ri with a constructor.
//ConstRef::ConstRef(int ii)
//{
//	i = ii;	//assignment is okay
	//ci = ii;	//error cannot assign to a const
	//ri = i;		//error ri was never initialized.
//};

//explicityly initialize reference and const members
ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i) {};

class NoDefault {
	NoDefault(int i);
};
class C {
	C();			//default constructor for C
	NoDefault member;	//member is a no default object
};
void example() {
	X newX(11,2);

	std::cout << newX.base << " " << newX.rem << std::endl;
}

//exercise 7.58
class Example1 {
public:
	static double rate = 6.5;
	static const int vecSize = 20;
	static std::vector<double> vec[vecSize];
	
};
std::vector<double> Example1::vec;
double Example1::rate;

int main10() {
	example();
	return 0;
}