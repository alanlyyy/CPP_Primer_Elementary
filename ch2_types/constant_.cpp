#include <iostream>

void ref_2_obj() {

	const int ci = 1024;

	//ci is referenced by r1 which is a type int, constant value
	const int &r1 = ci;

	
	//r1 = 42; -- error r1 is a reference to const type, value cannot be changed.
	//int& r2 = ci; -- error non constant reference r2 cannot reference constant int ci

	int i = 42;

	// i is bound to reference r1
	//r1 = i;

	//int 42 is bound to 42
	const int& r2 = 42;

	//value of r1 * 2 is bound to r3
	const int& r3 = r1 * 2;

	// int& r4 = r * 2; -- error non constant reference

	double dval = 3.14;
	const int& ri = dval;

	const double pi = 3.14;

	//ptr points to the address of pi
	//double* ptr = &pi;

	//cptr pointer type double points to address pi
	const double* cptr = &pi;

	//*cptr = 42; -- error cannot asign vale to cptr because cptr is a constant type pointer.

	//cptr now points to dval, but can't change value of dval through cptr.
	cptr = &dval;

	int errNumb = 0;

	//curErr will always point to errNumb
	//pointer can change existing value of errNumb but not what object it points to.
	int* const curErr = &errNumb;
	*curErr = 23;

	//pi = 3.14159;

	// pip is a const pointer to a const 
	//1. pointer can't point to a different object
	//2. pointer can't change existing value
	const double* const pip = &pi;

}

void ex_2_4_2() {
	//int i = -1, &r = 0;
	//int i, * const cp;
	//int* p1, *const p2;
	//const int ic, & r = ic;
	//const int* const p3;
	const int ci = 42;
	//int& r = ci; --error // cant bind int to const int object
}

void type_aliases() {

	//old way of definining aliases

	//wages is a synonym for double
	typedef double wages;

	//base is a synonym for double, p is synonym for double*
	typedef wages base, * p;

	//new way of defining aliases
	using wages = double;
	using base = double;
	using p = double*;

	//double* numbers
	p* numbers;

	//double double_value
	base double_value =24.07;

	typedef char* pstring;

	//cstr is a constant pointer to char
	const pstring cstr = 0; 

	//pstr is a pointer that points to a constant pointer that points to char.
	const pstring* ps; 


	// the type of item is deduced from the type of the result of adding double_value1 + double_value2
	auto item = double_value + double_value; // item initialized to the result of double_val1 + double_val2
	std::cout << "item: " << item << std::endl;

	const int ci = 20, &cr = ci;

	auto c = cr;

}

void ex_2_5_2() {
	const int i = 42;
	auto j = i;
	const auto& k = i;
	auto* p = &i;
	const auto j2 = i, & k2 = i;

	//k = 35; //-- since k is bound to i which is type const int, we cant change the value of k.
	p = &j2; //p now points to j2 which is a const int.
	//p = 35; // error since adjust the value of object j2 which refers to i, is a const int, cannot be adjusted.
	j = 69; //now j is a type int

	std::cout << i << "\n"
			<< j << "\n"
			<< k << "\n"
			<< p << "\n"
			<< j2 << "\n"
			<< k2 << "\n"
			<< std::endl;
				

}
void ex_2_5_3() {
	
	//EX 1
	int a = 3, b = 4;

	std::cout << a << " " << b << std::endl;
	decltype(a) c = a;
	std::cout << a << " " << c << std::endl;
	decltype((b)) d = a;
	std::cout << a << " " << b << " " << d << std::endl;

	++c;
	++d;
	std::cout << a << " " << b << " " << c << " " << d << std::endl;

	//EX 2
	a = 3, b = 4;
	decltype(a) e = a; //c = 3
	decltype (a = b) f = a; //d = 3
	std::cout << a << " " << b << " " << e <<" " << f << std::endl;
}
int main5() {

	type_aliases();
	ex_2_5_2();

	const int bufSize = 512; // input buffer size
	//bufSize = 512; -- error because can't adjust const type
	//const int k; -- error because of uninitialized constant

	int i = 42;
	const int ci = i; // the value in i is copied into ci
	int j = ci; // the value in ci is copied into j

	// file_1.cc defines and initialized a const that is accessible to other files
	//extern const int bufSize = fcn();

	//file_1.h
	//extern const int bufSize; //same bufSize as defined in file_1.cc
	ex_2_5_3();

	return 0;
}


void decl_types_ex(){

	//get the type of i and declare m with the same type of i.
	//decltype(i) m =56;
	//std::cout << m << "\n"; 

	// ci = type const int, cj is a const reference bound to ci, you cant change its value
	const int ci = 0, &cj = ci;

	//x is a const int 
	decltype(ci) x = 0;

	//y is a counst int reference bound to x, you cant change its value
	decltype(cj) y = x;

	//decltype(cj) z; -- error z is a reference and must be initialized.

	//decltype of an expression can be a reference type
	int i = 42, * p = &i, & r = i;
	decltype(r + 0) b;	//addition yields an int, b is an int
	//decltype(*p) c; // --error c is int& and must be initialized
	
	//decltype of  paranthesized variable is always a reference
	//decltype((i)) d;	//error: d is int& and must be initialized
	decltype(i) e;		//e is an uninitialized int



}