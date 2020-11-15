#include <iostream>

void ex_2_3() {
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl; // 32
	std::cout << u - u2 << std::endl; // 2^32 + (10-42)

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl; //32
	std::cout << i - i2 << std::endl; // -32

	std::cout << i - u << std::endl; //0
	std::cout << u - i << std::endl; // 0

}


void ex_2_5_6_7() {

	//a 'a' , 97, "a", address id for the string array 'a'
	std::cout << 'a' << " " << L'a' << " " << "a" << " " << L"a" << std::endl;

	//b 10, 10, 10, 10, ? , 1100 = 12
	std::cout << 10 << " " <<   10u << " " <<  10L << " " << 10uL <<  " " << 012 << " " << 0xC << std::endl;

	//c - 3.14, 3.14, 3.14
	std::cout << 3.14 << " " << 3.14f << " " << 3.14L << std::endl;

	//d   10 10 10 0.1
	std::cout << 10 << " " << 10u << " " << 10. << " " << 10e-2 << std::endl;

	//  octal '\145' = letter e in ascii 
	//  octal '\012' = new line character \n
	std::cout << "Who goes with F\145rgus?\012";

	//Long int 3.14 * 10 , e1 = 10^1
	std::cout << 3.14e1L << std::endl;

	// Long int 3.14
	std::cout << 3.14L << std::endl;

	//ex 2_8
	//print 2M followed by new line
	std::cout <<  "2\x4d" << "\012";

	//print 2 tab then M followed by new line
	std::cout << "2\t\x4d\012";

}

void ex_2_2_1() {
	//a.
	int input_value;
	std::cin >> input_value;

	//b. 
	float i = { 3.14 };
	std::cout << "i: " << i << std::endl;

	//c.
	double salary = 9999.99, wage = 9999.99;

	//d.
	int d = 3.14;
	std::cout << "i: " << d << std::endl;
}

void ex_2_2_3(){
	//a. int double = 3.14;
	int _;
	//c. int catch-22; is incorrect
	//d. int 1_or_2 = 1; is incorrect
	double Double = 3.14;
}

void ex_2_2_4() {
	int i = 100, sum = 0;

	for (int i = 0; i != 10; ++i)
	{
		sum += i;
	}

	//i = 100 , sum = 10!
	std::cout << i << " " << sum << std::endl;
}

void reference_ex()
{	
	
	int ival = 1024;

	//refval is the same object as ival
	int &refVal = ival;

	std::cout << ival << " " << refVal << std::endl;

	//changing refVal to 2, changes the value of the object ival and refVal points to, now 2.  
	refVal = 2;

	//ii is a copy of refVal, not bound to the object ival and refVal points to. 
	//changing the value of ii has no effect on refVal or ival
	int ii = refVal;

	std::cout << ival << " " << refVal << " " << ii << std::endl;

	//refVal3 is bound to the object to which refVal and ival is bound to.
	int	&refVal3 = refVal;

	//i is a copy of refVal, not bound to the object ival and refVal points to.
	//changing i has no affect on ival and refVal
	int i = refVal;

	i = 3;
	std::cout << ival << " " << refVal << " " << ii << " " << i <<  std::endl;

	refVal = 32;
	std::cout << ival << " " << refVal << " " << ii << " "<< i << std::endl;
}

void ref_ex2() {
	//References example

	int i = 1024, i2 = 2048;

	//create a reference r bound to i, r2 is a copy of i2 not bound to i.
	int &r = i, r2 = i2;

	//ri is an object bound to i3
	int i3 = 1024, &ri = i3;

	//r3 is an object bound to i3
	//r4 is an object bound to i2
	int &r3 = i3, &r4 = i2;

	//eror:initializer must be an object
	//int &refVal4 = 10;

	double dval = 3.14;
	
	//error: initializer must be an int object
	//int& refVal5 = dval;
}

void ex_2_3_1() {
	//References example
	int i = 0, & r1 = i; double d = 0, & r2 = d;

	r2 = 3.14159;
	std::cout << i << " " << r1 << " " << d << " " << r2 << std::endl;
	r2 = r1;
	std::cout << i << " " << r1 << " " << d << " " << r2 << std::endl;

	i = r2;
	std::cout << i << " " << r1 << " " << d << " " << r2 << std::endl;

	r1 = d;
	std::cout << i << " " << r1 << " " << d << " " << r2 << std::endl;

	int ii, &rii = ii;

	ii = 5; rii = 10;
	std::cout << ii << " " << rii << std::endl;

}

void ptr_example() {
	//pointer example

	// both ip1 and ip2 are pointers to int
	int* ip1, * ip2; 

	//dp2 is a pointer to double, dp is a double
	double dp, * dp2;

	int ival = 42;
	
	//p holds the address of ival; p is a pointer to ival
	int *p = &ival;

	double dval;

	// pointer pd contains the address of dval object of type double
	double* pd = &dval;

	// pointer pd2 contains the address of pd which contains the address of dval object of type double
	double* pd2 = pd;

	//int	*pi = pd; -- error types of pi and pd are different
	//pi = &dval; -- error assigning the address of a double to a pointer to int

	//dereference operator

	int iival = 42;


	//p holds the address of ival; p is a pointer to ival
	int* pp = &iival; 

	// * yields the object to which p points to; prints 42
	std::cout << *pp;

	// * yields the object; we assign a new value to ival through p
	// ival is now = 0
	*pp = 0;
}

void ptr_example2() {
	int i = 42;
	int& r = i; // r is bound to object i

	std::cout << i << " " << r  << std::endl;

	//reference
	int* p;	

	//pointer 
	p = &i;		// pointer p stores the object of i

	std::cout << i << " " << *p << " " << p  << " "<< r << std::endl;

	*p = i; // pointer p which stores object of i, changes the value of i to i

	int& r2 = *p; //r2 is bound to pointer p which points to object i.

	std::cout << i << " " << *p << " " << p << " " << r << " " << r2 << std::endl;


}
void ptr_example4() {
	int i = 42;
	int* pi = 0; //pi is initialized but addresses no objects

	int* pi2 = &i; //pi2 initialized to hold the address of i

	int* pi3; //pi3 is uninitialized pointer 
	
	pi3 = pi2;	// pi3 points to pi2, address the same object, e.g. i,42

	pi2 = 0; //pi2 now addresses no objects

	pi = &i; // value in pi has changed, pi now points to object i

	*pi = 0; //value in i is changedto 0, pi still points to i.
	
	std::cout << pi << " "<< *pi2 << " "<< pi3 << " "<< i << std::endl;


}

void ptr_personal_ex() {
	int* pi, * pi2, ival = 4, pval =1048;

	//pi stores address of ival 
	pi = &ival;
	std::cout << *pi << " " << ival << std::endl;
	
	//pi changes existing value of object to ival
	*pi = ival;

	//pi changes existing value of object, pointing to ival to 2078
	*pi = 2078;
	std::cout << *pi << " " << ival << std::endl;


	//pi2 points to object of type int pval
	pi2 = &pval;

	//pointer pi changes its value to pointer pi2 which points to pval
	*pi = *pi2;
	std::cout << *pi << " " << *pi2 << " " << pval << " " << ival << std::endl;
	
	//pi = ival; -- triggers an error
	//*pi = &ival; -- triggers an error

	//----------------------------------------------

	
	 //reference pi3 is bound to pointer pi which points to object ival.
	int& pi3 = *pi;
	std::cout << pi3 << " " << *pi << " " << ival <<std::endl;

	//change the value of reference pi3 which is bound to pointer pi which points to object ival to 36
	pi3 = 36;
	std::cout << pi3 << " " << *pi << " " << ival << std::endl;

	//int& pi3 = pi2; //-- triggers an error
	//pi3 = &ival; //-- triggers an error
}
int main2() {

	//b is true
	bool b = 42;

	std::cout << "b: " << b << std::endl;

	//i has a value of 1
	int i = b;
	 
	std::cout << "i: " << i << std::endl;

	//i has a value of 3
	i = 3.14;	
	std::cout << "i: " << i << std::endl;

	//pi has a value of 3.0
	double pi = i;
	std::cout << "pi: " << pi << std::endl;

	//assuming 8 bit chars, c has value 255
	unsigned char c = -1;
	std::cout << "c: " << c << std::endl;

	//assuming 8 bit chars, the value of c2 is undefined
	signed char c2 = 256;
	std::cout << "c2: " << c2 << std::endl;

	//Unsigned types arithmetic

	unsigned u = 10;
	int p = -42;
	std::cout << p + p << std::endl; // prints -84
	std::cout <<"u: " << u << std::endl; 

	//if u + p results in a negative number for unsigned type, the result wraps around from the largest number 2^32 - (u+p)
	std::cout << u + p << std::endl; //32 bit ints, prints 4294967264

	unsigned u1 = 42, u2 = 10;

	std::cout << u1 - u2 << std::endl; // ok: result is 32

	//if u2 - u1 results in a negative number for unsigned types, the result wraps around from the largest number 2^32 - (u2- u1)
	std::cout << u2 - u1 << std::endl; //ok: but the result will wrape


	//Signed arithmetic

	signed u6 = 42, u7 = 10;

	std::cout << u6 - u7 << std::endl; // ok: result is 32

	//u2 - u1 results in a negative number for signed types
	std::cout << u7 - u6 << std::endl; //ok: but the result will wrape

	//ex_2_3();

	std::cout << "Hi \x4dO\115!\n"; //prints Hi MOM! followed by a new line

	std::cout << '\115' << '\n'; // prints M followed by new line


	//type wchart_t, gets the ascii value
	std::cout << L'a' <<std::endl;

	//type utf-8 string literal
	std::cout << u8"hi!" << std::endl;

	//type unsigned long long inter literal
	std::cout << 42ULL <<std::endl;

	//type floating point
	std::cout << 1E-3F << std::endl;

	//type double 
	std::cout << 3.14159L << std::endl;
	
	//ex_2_5_6_7();
	//ex_2_2_3();
	//ex_2_2_4();
	//ex_2_3_1();
	//reference_ex();
	//ptr_example4();
	ptr_personal_ex();
	return 0;

}

