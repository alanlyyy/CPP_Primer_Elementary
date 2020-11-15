#include <iostream>

void ptr_personal_ex2() {
	int* pi, * pi2, ival = 4, pval = 16;

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

	//pi = ival; //-- triggers an error
	//*pi = &ival; -- triggers an error

	//----------------------------------------------


	 //reference pi3 is bound to pointer pi which points to object ival.
	int& pi3 = *pi;
	std::cout << pi3 << " " << *pi << " " << ival << std::endl;

	//change the value of reference pi3 which is bound to pointer pi which points to object ival to 36
	pi3 = 36;
	std::cout << pi3 << " " << *pi << " " << ival << std::endl;

	//int& pi3 = pi2; //-- triggers an error
	//pi3 = &ival; //-- triggers an error
}

void ex_2_3_2() {
	int ival = 69, pval = 36, * pv, * pd;
	
	//pointer pv points to address of ival
	pv = &ival;
	
	//pointer pd points to address of pval
	pd = &pval;


	std::cout << *pd << " " << pval << " " << *pv << " " << ival << std::endl;

	//pointer pd changes existing value of pval to 365
	*pd = 365;

	std::cout << *pd << " " << pval << " " << *pv << " " << ival << std::endl;

	//pointer pv is now equal to pointer pd which points to pval, ( pd = &pval )
	pv = pd;

	std::cout << *pd << " " << pval << " " << *pv << " " << ival << std::endl;
	std::cout << "Address of pv:" << pv << std::endl;
	std::cout << "Address of pd:" << pd << std::endl;

	int i = 42;

	int* p1 = &i;
	*p1 = *p1 * *p1; 
	std::cout << 42 * 42 << "=" << *p1 << std::endl;

}

void ptr_to_ptr_ex() {
	int ival = 1024;

	//pi points to an int ival
	int* pi = &ival;

	//ppi points to an pointer pi
	int** ppi = &pi;

	std::cout << "The value of ival\n"
		<< "direct value: " << ival << "\n"
		<< "indirect value: " << *pi << "\n"
		<< "doubly indirect value: " << **ppi
		<< std::endl;
}

void reference_to_ptr_ex() {

	//read definitions from right to left 

	int i = 42;
	int* p;

	//r is a reference to pointer p
	int* &r = p;

	//existing pointer p now points to int i
	r = &i;

	//change the value of pointer p which points to int i to 0
	*r = 0;
}

void ex_2_3_3() {

	//ip is a int pointer,ip is a pointer referenced by r
	int* ip, *&r = ip;

	// i is an int, nullpter is pointed to by pointer ip
	//int i, * ip = 0;

	//ip is an int pointer, ip2 is an int.
	//int* ip, ip2;
}

int main3() {

	//ex_2_3_2();
	ptr_to_ptr_ex();
	return 0;
}