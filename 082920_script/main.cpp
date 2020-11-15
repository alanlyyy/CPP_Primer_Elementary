#include <iostream>
/*
main function prints a product of 2 numbers
main2 functions prints a sum of 2 numbers
*/

void  while_looping() {
	int sum = 0, val = 50;

	//keep executing the while as long as val is less than or equal to 10

	while (val <= 100) {
		sum += val; // assigns sum + val to sum
		++val;		// add 1 to val
	}
	//reset val
	val = 50;

	std::cout << "Sum of " << val << " to " << val*2 << " inclusive is ";
	std::cout << sum << std::endl;
}

void while_looping2() {
	/*
	case 1: Print numbers from 10 to 0 
	case 2: Print numbers from v1 to v2
	*/
	int input_mode_switch = 0;

	int v1, v2 = 0;

	if (input_mode_switch == 0)
	{
		std::cout << "Please input 2 numbers" << std::endl;
		std::cin >> v1 >> v2;
	}
	else
	{
		v1 = 0;
		v2 = 10;
	}

	//keep executing the while as long as val is less than or equal to 10

	while (v2 > v1) {
		std::cout << v2  << " "; // assigns sum + val to sum
		--v2;		// decrement v2
	}
	std::cout << std::endl;
}
void for_looping() {
	int sum = 0;
	//sum values from 1 through 10 inclusive

	for (int val = 1; val <= 10; ++val)
	{
		sum += val;
		std::cout << "Sum of 1 to 10 inclusive is "
			<< sum << std::endl;
	}
}

int main2()
{
	// print 
	std::cout << "Enter two numbers: " << std::endl;

	
	int  v1 = 0, v2 = 0;

	//input 2 numbers
	std::cin >> v1 >> v2;

	std::cout << " The sum of " << v1 << " and " << v2
		<< " is " << v1 + v2 << std::endl;

	return 0;
}

int main3() {

	int v1 = 0, v2 = 0;

	std::cout << "Hello World!" << std::endl;

	std::cout << "Please input 2 numbers: " << std::endl;

	std::cin >> v1;
	std::cin >> v2;

	std::cout << "The Product is ";
	std::cout << v1 * v2;
	std::cout << std::endl;

	//calling main 2 function for summing.
	main2();

	return 0;
}

int main4() {
	std::cout << "/*";
	std::cout << "*/";
	std::cout << /* "*/" */";
	std::cout << /* "*/" /* "/*" */;

	return 0;
}

int main() {

	while_looping2();
	for_looping();
	return 0;
}